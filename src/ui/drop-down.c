#include "ui/drop-down.h"
#include "ui/raygui.h"


void draw_drop_down(DropDown* drop_down) {
    const int old_font_size = TEXT_SIZE;

    GuiSetStyle(DEFAULT, TEXT_SIZE, (int) drop_down->font_size);
    if (GuiDropdownBox(drop_down->bounds, drop_down->options, &drop_down->selection, drop_down->edited))
        drop_down->edited = !drop_down->edited;
    GuiSetStyle(DEFAULT, TEXT_SIZE, (int) old_font_size);
}
