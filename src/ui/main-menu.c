#include "ui/main-menu.h"
#include "ui/button.h"
#include "ui/label.h"
#include "ui/layout.h"
#include "ui/factory.h"
#include "utils/layout.h"
#include "utils/state-manager.h"
#include <raylib.h>


MainMenu main_menu;

void init_main_menu() {
    main_menu = (MainMenu) {0};
    const float center_screen_x = layout_center_x();
    const Vector2 button_margin = get_ui_element_margin(UI_ELEMENT_BUTTON);
    const Vector2 heading_margin = get_ui_element_margin(UI_ELEMENT_HEADING);

    /* Heading */
    main_menu.heading_label = ui_create_heading("C-Pong", center_screen_x, heading_margin.y);

    /* Start Game Button */
    float y = main_menu.heading_label.bounds.y + main_menu.heading_label.bounds.height + heading_margin.y;
    main_menu.start_button = ui_create_button("Start Game", center_screen_x, y);

    /* Settings Button */
    y += main_menu.start_button.bounds.height + button_margin.y;
    main_menu.settings_button = ui_create_button("Settings", center_screen_x, y);

    /* Quit Button */
    y += main_menu.settings_button.bounds.height + button_margin.y;
    main_menu.quit_button = ui_create_button("Quit Game", center_screen_x, y);
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