#ifndef C_PONG_DROP_DOWN_H
#define C_PONG_DROP_DOWN_H

#include "raygui.h"


typedef struct {
    Rectangle bounds;
    int font_size;
    char* options;
    int selection;
    bool edited;
} DropDown;

/**
 * @brief Draws a drop-down menu and handles its interaction.
 *
 * @param drop_down Pointer to a `DropDown` struct.
 */
void draw_drop_down(DropDown* drop_down);

#endif /* C_PONG_DROP_DOWN_H */
