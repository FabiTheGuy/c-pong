#include "ui/main-menu.h"
#include "ui/button.h"
#include "ui/label.h"
#include "ui/layout.h"
#include "utils/layout.h"
#include "state-manager.h"
#include <raylib.h>


MainMenu main_menu;

void init_main_menu() {
    main_menu = (MainMenu) {0};

    const float center_screen_x = layout_center_x();
    const int button_font_size = get_ui_font_size(UI_ELEMENT_BUTTON);
    const int heading_font_size = get_ui_font_size(UI_ELEMENT_HEADING);
    const Vector2 button_dimension = get_ui_size(UI_ELEMENT_BUTTON);
    const Vector2 button_margin = get_ui_element_margin(UI_ELEMENT_BUTTON);
    const Vector2 heading_margin = get_ui_element_margin(UI_ELEMENT_HEADING);
    
    
    /* 
     * Heading 
     */
    char* heading_content = "C-Pong";
    const Vector2 heading_dimension = MeasureTextEx(GetFontDefault(), heading_content, (float) heading_font_size, TEXT_SPACING);

    main_menu.heading_label = (Label) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (heading_dimension.x / 2),
            .y = heading_margin.y,
            .width = heading_dimension.x,
            .height = heading_dimension.y,
        },
        .content = heading_content,
        .font_size = heading_font_size,
        .color = RAYWHITE,
    };

    /* 
     * Start Button 
     */
    const float distance_start_button_top =
        main_menu.heading_label.bounds.y + 
        main_menu.heading_label.bounds.height + 
        heading_margin.y;

    main_menu.start_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (button_dimension.x / 2),
            .y = distance_start_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Start Game",
        .pressed = false,
        .font_size = button_font_size,
    };

    /*
     * Settings Button 
     */
    const float distance_settings_button_top = 
        main_menu.start_button.bounds.y + 
        main_menu.start_button.bounds.height +
        button_margin.y;

    main_menu.settings_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (button_dimension.x / 2),
            .y = distance_settings_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Settings",
        .pressed = false,
        .font_size = button_font_size,
    };

    /* 
     * Quit Button 
     */
    const float distance_quit_button_top = 
        main_menu.settings_button.bounds.y +
        main_menu.settings_button.bounds.height +
        button_margin.y;

    main_menu.quit_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (button_dimension.x / 2),
            .y = distance_quit_button_top,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .content = "Quit Game",
        .pressed = false,
        .font_size = button_font_size,
    };
}

void draw_main_menu() {
    draw_label(&main_menu.heading_label);
    draw_button(&main_menu.start_button);
    draw_button(&main_menu.settings_button);
    draw_button(&main_menu.quit_button);
}

void update_main_menu() {
    if (main_menu.start_button.pressed) {
        change_state_manager_state(GAMEPLAY);
        main_menu.start_button.pressed = false;
    } else if (main_menu.settings_button.pressed) {
        change_state_manager_state(SETTINGS);
        main_menu.settings_button.pressed = false;
    } else if (main_menu.quit_button.pressed) {
        state_manager.is_running = false;
        main_menu.quit_button.pressed = false;
    }
}