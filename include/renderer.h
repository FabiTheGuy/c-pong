// TODO: Write comment for this Header
#ifndef C_PONG_RENDERER_H
#define C_PONG_RENDERER_H

#include <raylib.h>

#include "window.h"
#include "entities.h"

// TODO: Write comment for this function
void init_renderer(Window* window);

void draw_player(Window* window, Player* player);

void draw_ball(Window* window, Player* player);

#endif /* C_PONG_RENDERER_H */