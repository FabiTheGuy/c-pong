/**
 * @file game.h
 * @author FabiTheGuy (fabian.doeller@mailfence.com)
 * @brief A implementation of a Game instance which holds
 * a neccessary Datas for a Game
 * @version 0.1
 * @date 2024-01-18
 */
#ifndef C_PONG_GAME_H
#define C_PONG_GAME_H

#include <stdbool.h>
#include <stdlib.h>

#include "window.h"
#include "entities.h"


typedef struct
{
  Window* window; /* Game related Window instance */
  Player* player_1; /* Player 1 */
  Player* player_2; /* Player 2 */
  Ball* ball; /* Ball */
  bool game_running; /* Games is running */
} Game;

/**
 * @brief Creates a Game instance
 * 
 * @param window Window instance
 * @param player_1 Player instance
 * @param player_2 Player instance
 * @param ball Ball instance
 * @param game_running Game is running
 * @return Game* 
 */
static Game* construct_game(Window* window, Player* player_1, Player* player_2, Ball* ball, bool game_running)
{
  Game* game = (Game*) calloc(1, sizeof(Game));
  if (game == NULL)
    return NULL;

  game->window = window;
  game->player_1 = player_1;
  game->player_2 = player_2;
  game->ball = ball;
  game->game_running = game_running;

  return game;
}

/**
 * @brief Destructs the Game instance and all it's Childs
 * 
 * @param game The Game instance which will be destroyed
 */
static void destruct_game(Game* game)
{
  destruct_window(game->window);
  destruct_player(game->player_1);
  destruct_player(game->player_2);
  destruct_ball(game->ball);
  free(game);
}

#endif /* C_PONG_GAME_H */