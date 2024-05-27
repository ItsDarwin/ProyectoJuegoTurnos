#include "../include/SceneWaiting.h"
#include "../include/Game.h"

SceneWaiting::SceneWaiting(Game& game,std::string rol):Scene(game),dotCount(0),rol(rol),sendRol(false) {
    waitingText.setFont(game.getFont());
    waitingText.setString("Waiting for connection");
    waitingText.setCharacterSize(24);
    waitingText.setFillColor(sf::Color::White);
    waitingText.setPosition(game.getWindow().getSize().x / 2.f - waitingText.getLocalBounds().width / 2.f, game.getWindow().getSize().y / 2.f - waitingText.getLocalBounds().height / 2.f);

	game.getNetworkManager()->connect(); //Iniciar la conexion
}

void SceneWaiting::update() {
	Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= 0.2f) {
		dotCount = (dotCount + 1) % 5;
		std::string dots(dotCount, '.');
		waitingText.setString("Waiting for connection" + dots);
		waitingText.setPosition(getInstanceGame()->getWindow().getSize().x / 2.f - waitingText.getLocalBounds().width / 2.f, getInstanceGame()->getWindow().getSize().y / 2.f - waitingText.getLocalBounds().height / 2.f);
		clock.restart();
	}
	// Verificar si el cliente se ha conectado
	if (getInstanceGame()->getNetworkManager()->isConnected() && !sendRol) {
		getInstanceGame()->getNetworkManager()->send(rol); //Se envia el rol del jugador local al jugador externo
		rolEnemy = getInstanceGame()->getNetworkManager()->getReceivedData(); //Se recibe el rol del jugador externo
		getInstanceGame()->getNetworkManager()->clearReceivedData(); //Se limpia la variable en la que se recibe informacion (importante)
		std::cout << "El rol enemigo es: " << rolEnemy << std::endl; //Mensaje de depuracion para ver en consola
		getInstanceGame()->initMyCharacter(rol); //Inciar el jugador local
		getInstanceGame()->getNetworkManager()->send(getInstanceGame()->getCharacter(0)->ProccessSendStats()); //Enviar los stats del jugador local con la variacion al jugador externo
		std::cout << "Estadisticas mandadas: " << getInstanceGame()->getCharacter(0)->ProccessSendStats() << std::endl;
		std::string stats = getInstanceGame()->getNetworkManager()->getReceivedData(); //Recibir las stats del jugador externo con la variabilidad
		getInstanceGame()->getNetworkManager()->clearReceivedData(); //Limpiar la variable en la que se recibe informacion (importante)
		getInstanceGame()->initEnemyCharacter(stats, rolEnemy); //Inicializar una copia del jugador externo de forma local con las stats que recibimos
		sendRol = true;
	}
	//Si el cliente se ha conectado, el rol enemigo tiene un valor y ya se crearon los jugadores entonces se pasa a la siguiente escena
	if (rolEnemy != "" && sendRol && getInstanceGame()->getCharactersExist()) {
		getInstanceGame()->changeScene(new SceneBattle(*getInstanceGame()));
	}
}

void SceneWaiting::draw() {
	getInstanceGame()->getWindow().clear();
	for (size_t i = 0; i < ITEMS_BACKGROUND; i++) {//Dibuja el fondo del menu
		getInstanceGame()->getWindow().draw(getInstanceGame()->getSpritesFont(static_cast<int>(i)));
	}
	getInstanceGame()->getWindow().draw(waitingText);
	getInstanceGame()->getWindow().display();
}