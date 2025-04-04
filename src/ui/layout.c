#include "ui/layout.h"
#include "utils/settings.h"
#include <raylib.h>


Vector2 get_ui_size(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return layout_px_from_percentage_x_y(20, 8);
        case UI_ELEMENT_DROP_DOWN: return layout_px_from_percentage_x_y(20, 8);
        default: return (Vector2) { .x = 0, .y = 0 };
    }
}

Vector2 get_element_margin(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return layout_px_from_percentage_x_y(3.125f, 5);
        case UI_ELEMENT_DROP_DOWN: return layout_px_from_percentage_x_y(3.125f, 5);
        case UI_ELEMENT_HEADING: return layout_px_from_percentage_x_y(6.25f, 10);
        case UI_ELEMENT_LABEL: return layout_px_from_percentage_x_y(3.125f, 5);
        default: return (Vector2) { .x = 0, .y = 0 };
    }
}

int get_font_size(UIElementType element) {
    switch (element) {
        case UI_ELEMENT_BUTTON: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_DROP_DOWN: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_LABEL: return (int) layout_px_from_percentage_y(5);
        case UI_ELEMENT_HEADING: return (int) layout_px_from_percentage_y(15);
        default: return 0;
    }
}

float layout_px_from_percentage_x(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution.x;
    if (percentage <= 0)
        return 0;

    return settings.screen_resolution.x * (percentage / 100);
}

float layout_px_from_percentage_y(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution.y;
    if (percentage <= 0)
        return 0;

    return settings.screen_resolution.y * (percentage / 100);
}

Vector2 layout_px_from_percentage(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution;
    if (percentage <= 0)
        return (Vector2) { .x = 0, .y = 0 };

    return (Vector2) { 
        .x = layout_px_from_percentage_x(percentage), 
        .y = layout_px_from_percentage_y(percentage) 
    };
}

Vector2 layout_px_from_percentage_x_y(float percentage_x, float percentage_y) {
    if (percentage_x >= 100 || percentage_y >= 100)
        return settings.screen_resolution;
    if (percentage_x <= 0 || percentage_y <= 0)
        return (Vector2) { .x = 0, .y = 0 };
    
    return (Vector2) {
        .x = layout_px_from_percentage_x(percentage_x),
        .y = layout_px_from_percentage_y(percentage_y)
    };
}

float layout_center_x() {
    return settings.screen_resolution.x / 2;
}

float layout_center_y() {
    return settings.screen_resolution.y / 2;
}

Vector2 layout_center() {
    return (Vector2) {
        .x = layout_center_x(),
        .y = layout_center_y()
    };
}
