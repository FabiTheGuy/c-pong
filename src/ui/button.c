#include "ui/button.h"
#include "ui/raygui.h"


void draw_button(Button* button) {
    const int old_font_size = TEXT_SIZE;

    GuiSetStyle(DEFAULT, TEXT_SIZE, button->font_size);
    button->pressed = GuiButton(button->bounds, button->content);
    GuiSetStyle(DEFAULT, TEXT_SIZE, old_font_size);
}
