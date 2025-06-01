#include <stdlib.h>

#include "player.h"
#include "layout.h"
#include "config.h"


Player* createPlayer(const enum PLAYER playerType) {
    Player* player = (Player*) malloc(sizeof(Player));

    if (!player) {
        return NULL;
    }

    float playerPosX;

    if (playerType == PLAYER_1) {
        playerPosX = WIN_PERC_X(PLAYER_PERC_MARGIN_X); 
    } else {
        playerPosX = winDimensions.x - WIN_PERC_X(PLAYER_PERC_MARGIN_X) - WIN_PERC_X(PLAYER_PERC_X);
    }

    player->playerType = playerType;
    player->dimension = (Vector2) {
        .x = WIN_PERC_X(PLAYER_PERC_X), 
        .y = WIN_PERC_Y(PLAYER_PERC_Y),
    };
    player->position = (Vector2) {
        .x = playerPosX, 
        .y = winDimensions.y / 2 - (player->dimension.y / 2),
    };
    player->speed = WIN_PERC_Y(PLAYER_PERC_SPEED_X);
    player->keyUp = (playerType == PLAYER_1) ? KEY_W : KEY_UP;
    player->keyDown = (playerType == PLAYER_1) ? KEY_S : KEY_DOWN;
    player->score = 0;

    return player;
}

void updatePlayer(Player* player) {
    if (IsKeyDown(player->keyUp) && player->position.y > 0) {
        player->position.y -= GetFrameTime() * player->speed;
    } else if (IsKeyDown(player->keyDown) && player->position.y < winDimensions.y - player->dimension.y) {
        player->position.y += GetFrameTime() * player->speed;
    }
}

void drawPlayer(const Player* player) {
    DrawRectangle(
        player->position.x,
        player->position.y,
        player->dimension.x,
        player->dimension.y,
        WHITE
    );
}

void destroyPlayer(Player* player) {
    free(player);
}
