/**
 * @file renderer.h
 * @author FabiTheGuy (fabian.doeller@mailfence.com)
 * @brief Contains all function which are neccessary to draw to the screen
 * @version 0.1
 * @date 2024-01-19
 */
#ifndef C_PONG_RENDERER_H
#define C_PONG_RENDERER_H

#include <raylib.h>

#include "window.h"
#include "entities.h"

/**
 * @brief Initializes the Renderer by creating the Window an which the renderer
 * will draw
 * 
 * @param window Window instance 
 */
void init_renderer(Window* window);

/**
 * @brief Draws the Player according to the window scaling to the monitor
 * 
 * @param window Window instance
 * @param player Player instance
 */
void draw_player(Window* window, Player* player);

/**
 * @brief Draws the Ball according ti the window scaling to the monitor
 * 
 * @param window 
 * @param ball 
 */
void draw_ball(Window* window, Ball* ball);

#endif /* C_PONG_RENDERER_H */