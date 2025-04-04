#include "ui/layout.h"
#include "utils/layout.h"
#include <raylib.h>


Vector2 get_ui_size(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return layout_px_from_percentage_x_y(20, 8);
        case UI_ELEMENT_DROP_DOWN: return layout_px_from_percentage_x_y(20, 8);
        default: return (Vector2) { .x = 0, .y = 0 };
    }
}

Vector2 get_ui_element_margin(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return layout_px_from_percentage_x_y(3.125f, 5);
        case UI_ELEMENT_DROP_DOWN: return layout_px_from_percentage_x_y(3.125f, 5);
        case UI_ELEMENT_HEADING: return layout_px_from_percentage_x_y(6.25f, 10);
        case UI_ELEMENT_LABEL: return layout_px_from_percentage_x_y(3.125f, 5);
        default: return (Vector2) { .x = 0, .y = 0 };
    }
}

int get_ui_font_size(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_DROP_DOWN: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_LABEL: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_HEADING: return (int) layout_px_from_percentage_y(15);
        default: return 0;
    }
}
