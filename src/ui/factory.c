#include "ui/factory.h"
#include "ui/label.h"
#include "ui/button.h"
#include "ui/drop-down.h"
#include "ui/layout.h"
#include <raylib.h>


Button ui_create_button(char* content, const float center_x, const float top_y) {
    const Vector2 size = get_ui_size(UI_ELEMENT_BUTTON);

    return (Button) {
        .bounds = (Rectangle) {
            .x = center_x - size.x / 2,
            .y = top_y,
            .width = size.x,
            .height = size.y,
        },
        .font_size = get_ui_font_size(UI_ELEMENT_BUTTON),
        .content = content,
        .pressed = false,
    };
}


Label ui_create_heading(char* content, const float center_x, const float top_y) {
    const int font_size = get_ui_font_size(UI_ELEMENT_HEADING);
    const Vector2 size = MeasureTextEx(GetFontDefault(), content, (float) font_size, TEXT_SPACING);

    return (Label) {
        .bounds = (Rectangle) {
            .x = center_x - size.x / 2,
            .y = top_y,
            .width = size.x,
            .height = size.y,
        },
        .content = content,
        .font_size = font_size,
        .color = RAYWHITE,
    };
}

DropDown ui_create_drop_down(char* options, const float center_x, const float top_y, const int selection) {
    const Vector2 size = get_ui_size(UI_ELEMENT_DROP_DOWN);

    return (DropDown) {
        .bounds = (Rectangle) {
            .x = center_x - size.x / 2,
            .y = top_y,
            .width = size.x,
            .height = size.y,
        },
        .options = options,
        .font_size = get_ui_font_size(UI_ELEMENT_DROP_DOWN),
        .selection = selection,
        .edited = false,
    };
}
