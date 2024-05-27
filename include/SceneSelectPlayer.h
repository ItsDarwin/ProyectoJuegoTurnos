#ifndef SCENESELECTPLAYER_H
#define SCENESELECTPLAYER_H
#include "Scene.h"
#define OPTIONS_SELECT_SCENE 4
class SceneSelectPlayer :
    public Scene
{
private:
    Text tileScene; //Titulo de la escena
    Text backScene; //Texto boton regresar
    Text selectedPlayer[OPTIONS_SELECT_SCENE]; //Texto con los 4 roles
    Texture rolesTextures[OPTIONS_SELECT_SCENE];//Texturas para cargar el spritsheet
    Sprite rolesSelect[OPTIONS_SELECT_SCENE]; //Sprite en la que se maneja la textura
    int selectIndex; //Eleccion del jugador
    IntRect frameRects[OPTIONS_SELECT_SCENE];
    Text stat;
    Text stats[6];
    Clock clockFrame;
public:
    SceneSelectPlayer(Game &game);
    void update();
    void draw();
};

#endif
