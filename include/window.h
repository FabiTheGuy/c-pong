/**
 * @file window.h
 * @author FabiTheGuy (fabian.doeller@mailfence.com)
 * @brief A implementation of the Game Window
 * @version 0.1
 * @date 2024-01-18
 */
#ifndef C_PONG_WINDOW_H
#define C_PONG_WINDOW_H

#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct
{
  Vector2 size; /* size of Window */
  Vector2 scale; /* scale of Window */
  char* title; /* title of Window */ 
  bool is_fullscreen; /* is Window in fullscreen */
  ConfigFlags* flags; /* extra flags fror Window */
} Window;

/**
 * @brief Creates a Window instance
 * 
 * @param size Window size
 * @param scale Window scale
 * @param title Window title
 * @param fullscreen Window in fullscreen
 * @param flags Window extra flags
 * @return Window* - On success a pointer to the Window instance will be returned, If
 * an error occurs NULL will be returned and errno will be set
 */
static Window* construct_window(Vector2 size, Vector2 scale, char* title, bool fullscreen, ConfigFlags* flags)
{
  Window* win = (Window*) calloc(1, sizeof(Window));
  if (win == NULL)
    return NULL;

  win->size = size;
  win->scale = scale;
  win->title = title;
  win->is_fullscreen = fullscreen;
  win->flags = flags;

  return win;
}

/**
 * @brief Destruct the Window instance
 * 
 * @param window Window instance which will be destroyed
 */
static void destruct_window(Window* window)
{
  free(window->flags);
  free(window);
}

#endif /* C_PONG_WINDOW_H */