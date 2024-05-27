#include "..//include/NetworkManager.h"
#include "..//include/Game.h"

NetworkManager::NetworkManager(Game& game)
    :game(game),mode(Mode::NONE),running(false),connected(false){}

NetworkManager::~NetworkManager() {
    disconnect();
}

bool NetworkManager::connect() {
    running = true;
    connected = false;

    // Crea un hilo que intenta conectarse como cliente o servidor
    networkThread = std::thread([this]() {
        sf::IpAddress localAddress = sf::IpAddress::getLocalAddress();
        sf::IpAddress broadcastAddress = sf::IpAddress::Broadcast;

        if (listener.listen(53000) == sf::Socket::Done) {
            // Si puede oir en el puerto, se vuelve servidor
            mode = Mode::SERVER;
            startServer();
        }
        else {
            // Si no puede oir en el puerto, es el cliente
            mode = Mode::CLIENT;
            startClient();
        }
    });

    return true;
}

void NetworkManager::disconnect() {
    running = false;
    if (networkThread.joinable()) {
        networkThread.join();
    }
    socket.disconnect();
    connected = false;
}

void NetworkManager::send(const std::string& data) {
    std::lock_guard<std::mutex> lock(socketMutex);
    if (socket.send(data.c_str(), data.size() + 1) != sf::Socket::Done) {
        std::cout << "Failed to sent data." << std::endl;
        // Handle send error
    }
}

std::string NetworkManager::receive() {
    char buffer[1024];
    std::size_t received;
    if (socket.receive(buffer, sizeof(buffer) - 1, received) == sf::Socket::Done) {
        buffer[received] = '\0';
        return std::string(buffer); 
    }
    return "";
}

NetworkManager::Mode NetworkManager::getMode() const {
    return mode.load();
}

bool NetworkManager::isConnected() const {
    return connected.load();
}

void NetworkManager::startServer() {
    if (listener.accept(socket) == sf::Socket::Done) {
        connected = true;
        while (running) {
            std::string data = receive();
            {
                std::lock_guard<std::mutex> lock(socketMutex);
                receivedData = data;
                dataCondition.notify_one(); //Notifica que se ha recibido un nuevo dato
            }
        }
    }
    else {
        connected = false;
        std::cout << "Error al crear el server" << std::endl;
        // Handle accept error
    }
}

void NetworkManager::startClient() {
    sf::IpAddress serverAddress = sf::IpAddress::getLocalAddress();
    while (running) {
        if (socket.connect(serverAddress, 53000) == sf::Socket::Done) {
            connected = true;
            while (running) {
                std::string data = receive();
                {
                    std::lock_guard<std::mutex> lock(socketMutex);
                    receivedData = data;
                    dataCondition.notify_one(); //Notifica que se ha recibido un nuevo dato
                }
            }
            break;
        }
        sf::sleep(sf::milliseconds(100));
    }
    if (!connected) {
        // Handle connect error
        std::cout << "Error al crear el cliente" << std::endl;
    }
}

std::string NetworkManager::getReceivedData(){
    std::unique_lock<std::mutex> lock(socketMutex);
    dataCondition.wait(lock, [this] { return !receivedData.empty(); });
    return receivedData;
}

void NetworkManager::clearReceivedData() {
    std::lock_guard<std::mutex> lock(socketMutex);
    receivedData.clear();
}
