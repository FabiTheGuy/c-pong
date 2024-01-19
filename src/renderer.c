#include <raylib.h>
#include <stddef.h>

#include "../include/renderer.h"
#include "../include/window.h"


void init_renderer(Window* window)
{
  for (size_t i = 0; window->flags[i] != '\0'; i++)
    SetConfigFlags(window->flags[i]);
  InitWindow(window->size.x, window->size.y, window->title);
}

void draw_player(Window* window, Player* player)
{
  Vector2 scaled_position = (Vector2) { player->position.x * window->scale.x, player->position.y * window->scale.y };
  Vector2 scaled_size = (Vector2) { player->size.x * window->scale.x, player->size.y * window->scale.y };

  DrawRectangleV(scaled_position, scaled_size, RAYWHITE);
}

void draw_ball(Window* window, Ball* ball)
{
  Vector2 scaled_position = (Vector2) { ball->position.x * window->scale.x, ball->position.y * window->scale.y };
  float scaled_radius = ball->radius * window-> scale.x;

  DrawCircleV(scaled_position, scaled_radius, RAYWHITE);
}