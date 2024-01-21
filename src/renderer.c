#include <raylib.h>
#include <stddef.h>

#include "../include/renderer.h"
#include "../include/window.h"


void init_renderer(Window* window)
{
  if (window->flags != NULL)
    for (size_t i = 0; window->flags[i] != '\0'; i++)
      SetConfigFlags(window->flags[i]);
  InitWindow(window->size.x, window->size.y, window->title);
}

void draw_player(Player* player)
{
  DrawRectangleV(player->position, player->size, RAYWHITE);
}

void draw_ball(Ball* ball)
{
  DrawCircleV(ball->position, ball->radius, RAYWHITE);
}