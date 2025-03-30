#ifndef C_PONG_DROP_DOWN_H
#define C_PONG_DROP_DOWN_H

#include "raygui.h"


typedef struct {
    /* Defines the rectangular area that serves as the boundary for the DropDown element. */
    Rectangle bounds;
    /* Represents the font size of the DropDown Elements. */
    int font_size;
    /* Holds the options for a drop-down menu. */
    char* options;
    /* Represents the currently selected option in a drop-down menu. */
    int selection;
    /* A boolean flag indicating whether the state of the dropdown menu is currently being edited. */
    bool edited;
} DropDown;

/**
 * Draws a dropdown menu on the screen.
 *
 * This function renders a dropdown menu based on the properties
 * of the provided DropDown structure. It adjusts the font size
 * dynamically while drawing the dropdown and handles toggling
 * of the edited state.
 *
 * @param drop_down A pointer to a DropDown structure that defines
 *                  the dropdowns properties such as bounds, options,
 *                  current selection, font size, and edited state.
 */
void draw_drop_down(DropDown* drop_down);

#endif /* C_PONG_DROP_DOWN_H */
