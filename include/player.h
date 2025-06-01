#ifndef C_PONG_PLAYER_H
#define C_PONG_PLAYER_H

#include <raylib.h>

#define PLAYER_PERC_X 1.5
#define PLAYER_PERC_Y 20
#define PLAYER_PERC_MARGIN_X 2.5
#define PLAYER_PERC_SPEED_X 35

enum PLAYER {
    PLAYER_1,
    PLAYER_2,
};

typedef struct {
    enum PLAYER playerType;
    Vector2 dimension;
    Vector2 position;
    int speed;
    KeyboardKey keyUp, keyDown;
    int score;
} Player;


Player* createPlayer(const enum PLAYER playerType);

void updatePlayer(Player* player);

void drawPlayer(const Player* player);

void destroyPlayer(Player* player);

#endif /* C_PONG_PLAYER_H */ 
