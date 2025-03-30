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
 * @param label A pointer to a `Label` structure.
 */
void draw_label(const Label* label);

#endif /* C_PONG_LABEL_H */
