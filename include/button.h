#ifndef C_PONG_BUTTON_H
#define C_PONG_BUTTON_H

#include "raygui.h"
#include "layout.h"


typedef struct {
    Rectangle bounds;
    float font_size;
    char* content;
    bool pressed;
} Button;


/**
 * @brief Draws a button on the screen and updates its pressed state.
 * 
 * This function draws a button using the Raygui library's `GuiButton` function.
 * It changes the button's font size temporarily to the size defined in the 
 * `Button` structure and resets it to the original font size after drawing.
 * It also updates the `pressed` state of the button based on the user's input.
 * 
 * @param button A pointer to a `Button` structure 
 * 
 * @note The font size used to draw the button is temporarily changed using 
 *       `GuiSetStyle`. After the button is drawn, the font size is restored to 
 *       its original value.
 */
static void draw_button(Button* button) {
    const float old_font_size = TEXT_SIZE;

    GuiSetStyle(DEFAULT, TEXT_SIZE, button->font_size);
    button->pressed = GuiButton(button->bounds, button->content);
    GuiSetStyle(DEFAULT, TEXT_SIZE, old_font_size);
}

#endif /* C_PONG_BUTTON_H */