#ifndef C_PONG_UI_BUTTON_H
#define C_PONG_UI_BUTTON_H

#include "ui/raygui.h"


typedef struct {
    /* Defines the rectangular area that serves as the boundary for the Button element. */
    Rectangle bounds;
    /* Represents the font size of the Button Label. */
    int font_size;
    /* Content the Label of the Button will contain. */
    char* content;
    /* Flag, which indicates whether the Button was pressed or not. */
    bool pressed;
} Button;

/**
 * @brief Renders a button on the Screen.
 *
 * This function draws the given button on the graphical user interface using
 * the properties of the Button structure, such as its bounds, font size, and content.
 * The pressed state of the button is updated based on user interaction.
 *
 * The function temporarily changes the text size to match the button's specified font size
 * and restores the original text size after drawing the button.
 *
 * @param button A pointer to the Button structure that contains the rendering properties and state.
 */
void draw_button(Button* button);

#endif /* C_PONG_UI_BUTTON_H */
