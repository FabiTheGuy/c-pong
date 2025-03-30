#ifndef C_PONG_LABEL_H
#define C_PONG_LABEL_H

#include "raygui.h"


typedef struct {
    /* Defines the rectangular area that serves as the boundary for the DropDown element. */
    Rectangle bounds;
    /* Content the Label contains. */
    char* content;
    /* Represents the font size of the Label. */
    int font_size;
    /* Represents the font color of the Label. */
    Color color;
} Label;


/**
 * @brief Renders a graphical label onto the screen.
 *
 * This function draws a label at its specified position on the user interface.
 * The label's text, font size, and color are defined by the `Label` parameter.
 *
 * @param label A constant pointer to a `Label` structure containing information
 * about the label's content, position, font size, and color.
 */
void draw_label(const Label* label);

#endif /* C_PONG_LABEL_H */
