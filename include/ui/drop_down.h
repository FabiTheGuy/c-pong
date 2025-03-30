#ifndef C_PONG_DROP_DOWN_H
#define C_PONG_DROP_DOWN_H

#include "raygui.h"


typedef struct {
    Rectangle bounds;
    float font_size;
    char* options;
    int selection;
    bool edited;
} DropDown;


/**
 * @brief Draws a drop-down menu and handles its interaction.
 *
 * @param drop_down Pointer to a `DropDown` struct.
 */
static void draw_drop_down(DropDown* drop_down) {
    const float old_font_size = TEXT_SIZE;

    GuiSetStyle(DEFAULT, TEXT_SIZE, drop_down->font_size);
    if (GuiDropdownBox(drop_down->bounds, drop_down->options, &drop_down->selection, drop_down->edited))
        drop_down->edited = !drop_down->edited;
    GuiSetStyle(DEFAULT, TEXT_SIZE, old_font_size);
}

#endif /* C_PONG_DROP_DOWN_H */