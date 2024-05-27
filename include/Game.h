#ifndef GAME_H
#define GAME_H
#include "SceneMenu.h"
#include "SceneSelectPlayer.h"
#include "NetworkManager.h"
#include "SceneWaiting.h"
#include "SceneBattle.h"
#include "Character.h"
#include "Characters/Dragon.h"
#include "Characters/Sirena.h"
#include "Characters/Troll.h"
#include "Characters/Yordle.h"
using namespace sf;
#define NUM_SCENES 3
class Scene;

class Game
{
private:
	RenderWindow window;
	Scene* currentScene; //Actual escena
	Scene* pendingScene; //Escene de paso
	NetworkManager networkManager;
	Font fontGame;
	Texture textures_background[ITEMS_BACKGROUND];
	Sprite sprites[ITEMS_BACKGROUND];
	Character* characters[2];
	bool charactersExist;
public:
	Game();
	~Game();
	void updateWindowEvents();
	//void update();
	void render();
	void changeScene(Scene* newScene);
	void processPendingScene(); //Procesar la escena pendiente
	void run();
	NetworkManager* getNetworkManager();
	const Font& getFont() const;
	RenderWindow& getWindow();
	const Sprite& getSpritesFont(int index) const;
	bool getCharactersExist() const;
	Character* getCharacter(int index);
	void initMyCharacter(std::string rolMy);
	void initEnemyCharacter(std::string statsEnemy,std::string rolEnemy);
};


#endif // !GAME_H