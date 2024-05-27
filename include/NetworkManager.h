#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <SFML/Network.hpp>
#include <thread>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>

class Game; // Declaración anticipada de la clase Game

class NetworkManager {
public:
    enum class Mode { NONE, SERVER, CLIENT };

    NetworkManager(Game& game);
    ~NetworkManager();

    bool connect();
    void disconnect();
    void send(const std::string& data);
    std::string receive();

    Mode getMode() const;
    bool isConnected() const;
    std::string getReceivedData();
    void clearReceivedData();

private:
    void startServer();
    void startClient();

    Game& game;
    sf::TcpListener listener;
    sf::TcpSocket socket;
    std::thread networkThread;
    std::atomic<Mode> mode;
    std::atomic<bool> running;
    std::atomic<bool> connected;
    std::mutex socketMutex;
    std::string receivedData;
    std::condition_variable dataCondition; //Condicion para esperar y notificar la recepcion de datos
};

#endif // NETWORKMANAGER_H