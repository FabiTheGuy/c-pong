#include "../include/layout.h"
#include "../include/settings.h"


float layout_px_from_percentage_x(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution.x;
    else if (percentage <= 0)
        return 0;

    return settings.screen_resolution.x * (percentage / 100);
}

float layout_px_from_percentage_y(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution.y;
    else if (percentage <= 0)
        return 0;

    return settings.screen_resolution.y * (percentage / 100);
}

Vector2 layout_px_from_percentage(float percentage) {
    if (percentage >= 100)
        return settings.screen_resolution;
    else if (percentage <= 0)
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
