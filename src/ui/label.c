#include "ui/label.h"


void draw_label(const Label* label) {
    DrawText(label->content, (int) label->bounds.x, (int) label->bounds.y, label->font_size, label->color);
}
