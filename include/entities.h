/**
 * @file entities.h
 * @author FabiTheGuy (fabian.doeller@mailfence.com)
 * @brief A implementation of Game entities
 * @version 0.1
 * @date 2024-01-18
 */
#ifndef C_PONG_ENTITIES_H
#define C_PONG_ENTITIES_H

#include <raylib.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct
{
  Vector2 size; /* Size of Player */
  Vector2 position; /* Position of Player */
  KeyboardKey key_up; /* Keyboard Key Up */
  KeyboardKey key_down; /* Keyboard Key Down */
  size_t speed; /* Speed of Player */
  size_t score; /* Score of Player */
} Player;

typedef struct
{
  Vector2 position; /* Position of Ball */
  float radius; /* Radius of Ball */
} Ball;

/**
 * @brief Creates a Player instance
 * 
 * @param size Player size
 * @param position Player position
 * @param key_up Player move up key
 * @param key_dwn Player move down key
 * @param speed Player speed
 * @param score Player score
 * @return Player* - On success a pointer to the Player will be returned, If 
 * an error occurs NULL will be returned and errno will be set
 */
Player* construct_player(Vector2 size, Vector2 position, KeyboardKey key_up, KeyboardKey key_down, size_t speed, size_t score)
{
  Player* player = (Player*) calloc(1, sizeof(Player));
  if (player == NULL)
    return NULL;

  player->size = size;
  player->position = position;
  player->key_up = key_up;
  player->key_down = key_down;
  player->speed = speed;
  player->score = score;

  return player;
}

/**
 * @brief Destructs Player instance
 * 
 * @param player Player instance which will be destructed
 */
void destruct_player(Player* player)
{
  free(player);
}

/**
 * @brief Creates a Ball instance
 * 
 * @param position Ball position
 * @param radius Ball radius
 * @return Ball* - On success a pointer to the Ball will be returned, If an
 * error occurs NULL will be returned and errno will be set 
 */
Ball* construct_ball(Vector2 position, float radius)
{
  Ball* ball = (Ball*) calloc(1, sizeof(Player));
  if (ball == NULL)
    return NULL;

  ball->position = position;
  ball->radius = radius;

  return ball;
}

/**
 * @brief Destructs Ball instance
 * 
 * @param ball Ball instance which will be destructed
 */
void destruct_ball(Ball* ball)
{
  free(ball);
}

#endif /* C_PONG_ENTITIES_H */