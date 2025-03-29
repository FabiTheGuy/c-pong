#ifndef C_PONG_LABEL_H
#define C_PONG_LABEL_H

#include "raygui.h"


typedef struct {
    Rectangle bounds;
    char* content;
    int font_size;
    Color color;
} Label;


/**
 * @brief Draws a label (text) on the screen at a specified position with a given font size and color.
 * 
 * This function uses Raylib's `DrawText` function to render the text specified in the `Label` structure.
 * The label's position, font size, and color are all configurable via the `Label` structure's properties.
 * 
 * @param label A pointer to a `Label` structure that contains the text content, font size, 
 *              position (bounds), and color of the label to be drawn.
 */
static void draw_label(Label* label) {
    DrawText(label->content, label->bounds.x, label->bounds.y, label->font_size, label->color);
}

#endif /* C_PONG_LABEL_H */