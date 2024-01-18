#include <raylib.h>
#include <stddef.h>

#include "renderer.h"
#include "window.h"


void init_renderer(Window* window)
{
  size_t index = 0;

  while (window->flags[index] != '\0')
    SetConfigFlags(window->flags[index++]);
  InitWindow(window->size.x, window->size.y, window->title);
}