#ifndef C_PONG_BUTTON_H
#define C_PONG_BUTTON_H

#include "layout.h"


typedef struct {
    Rectangle bounds;
    int font_size;
    char* content;
    bool pressed;
} Button;

/**
 * @brief Draws a button on the screen and updates its pressed state.
 *
 * @param button A pointer to a `Button` structure
 */
void draw_button(const Button* button);

#endif /* C_PONG_BUTTON_H */
