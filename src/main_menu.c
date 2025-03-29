#include "main_menu.h"
#include "button.h"
#include "label.h"
#include "layout.h"
#include "settings.h"

#include <stdio.h>
#include <raylib.h>


MainMenu main_menu;


void init_main_menu() {
    const Color color = RAYWHITE;
    const float center_x = layout_center_x();
    const Vector2 button_dimension = layout_px_from_percentage_x_y(20, 8);
    
    /* Heading related */
    const float distance_heading_top = layout_px_from_percentage_y(10);
    const float font_size_heading = layout_px_from_percentage_y(15);
    const char* content_heading = "C-Pong";
    const Vector2 dimension_heading = MeasureTextEx(GetFontDefault(), content_heading, font_size_heading, TEXT_SPACING);

    main_menu.heading = (Label) {
        .bounds = (Rectangle) {
            .x = center_x - (dimension_heading.x / 2),
            .y = distance_heading_top,
            .width = dimension_heading.x,
            .height = dimension_heading.y,
        },
        .content = content_heading,
        .font_size = font_size_heading,
        .color = color,
    };

    const float font_size_button = layout_px_from_percentage_y(5);
    const float distance_heading_button = layout_px_from_percentage_y(10
    );
    const float distance_button_button = layout_px_from_percentage_y(5);

    /* Start Button related */
    const float distance_start_button_top = 
        main_menu.heading.bounds.y + 
        main_menu.heading.bounds.height + 
        distance_heading_button;

    main_menu.start_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_x - (button_dimension.x / 2),
            .y = distance_start_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Start Game",
        .pressed = false,
        .font_size = font_size_button,
    };

    /* Settings Button related */
    const float distance_settings_button_top = 
        main_menu.start_button.bounds.y + 
        main_menu.start_button.bounds.height +
        distance_button_button;

    main_menu.settings_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_x - (button_dimension.x / 2),
            .y = distance_settings_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Settings",
        .pressed = false,
        .font_size = font_size_button,
    };

    /* Quit Button related */
    const float distance_quit_button_top = 
        main_menu.settings_button.bounds.y +
        main_menu.settings_button.bounds.height +
        distance_button_button;

    main_menu.quit_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_x - (button_dimension.x / 2),
            .y = distance_quit_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Quit Game",
        .pressed = false,
        .font_size = font_size_button,
    };
}

void draw_main_menu() {
    draw_label(&main_menu.heading);
    draw_button(&main_menu.start_button);
    draw_button(&main_menu.settings_button);
    draw_button(&main_menu.quit_button);
}

void update_main_menu() {
    if (main_menu.start_button.pressed) {
        printf("Start Button pressed\n");
        /* TODO: Implement behaviour */
        main_menu.start_button.pressed = false;
    } else if (main_menu.settings_button.pressed) {
        printf("Settings Button pressed\n");
        /* TODO: Implement behaviour */
        main_menu.settings_button.pressed = false;
    } else if (main_menu.quit_button.pressed) {
        printf("Quit Button pressed\n");
        /* TODO: Implement behaviour */
        main_menu.quit_button.pressed = false;
    }
}