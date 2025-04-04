#include "ui/settings-menu.h"
#include "ui/layout.h"
#include "ui/factory.h"
#include "ui/button.h"
#include "ui/label.h"
#include "ui/drop-down.h"
#include "utils/layout.h"
#include "utils/settings.h"
#include "utils/string-array.h"
#include "utils/state-manager.h"
#include <stdlib.h>
#include <string.h>
#include <raylib.h>


SettingsMenu settings_menu;

void init_settings_menu() {
    settings_menu = (SettingsMenu) {0};

    const float center_screen_x = layout_center_x();
    const Vector2 drop_down_margin = get_ui_element_margin(UI_ELEMENT_DROP_DOWN);
    const Vector2 heading_margin = get_ui_element_margin(UI_ELEMENT_HEADING);

    /* Heading */
    settings_menu.heading_label = ui_create_heading("Settings", center_screen_x, heading_margin.y);

    /* Resolution DropDown */
    float top_y = settings_menu.heading_label.bounds.y + settings_menu.heading_label.bounds.height + heading_margin.y;
    settings_menu.resolution_drop_down = ui_create_drop_down(RESOLUTION_OPTIONS, center_screen_x, top_y, 0);

    /* FPS DropDown */
    top_y += settings_menu.resolution_drop_down.bounds.height + drop_down_margin.y;
    settings_menu.fps_drop_down = ui_create_drop_down(FPS_OPTIONS, center_screen_x, top_y, 0);

    /* Fullscreen DropDown */
    top_y += settings_menu.fps_drop_down.bounds.height + drop_down_margin.y;
    settings_menu.fullscreen_drop_down = ui_create_drop_down(FULLSCREEN_STATES, center_screen_x, top_y, 0);

    /* Cancel/Apply Button */
    const Vector2 button_dimensions = get_ui_size(UI_ELEMENT_BUTTON);
    const Vector2 button_margin = get_ui_element_margin(UI_ELEMENT_BUTTON);
    const float button_top_y = settings.screen_resolution.y - button_margin.y - button_dimensions.y;
    const float cancel_button_x = center_screen_x - button_margin.x - (button_dimensions.x / 2);
    const float apply_button_x = center_screen_x + button_margin.x + (button_dimensions.x / 2);

    settings_menu.cancel_button = ui_create_button("Cancel", cancel_button_x, button_top_y);
    settings_menu.apply_button = ui_create_button("Apply", apply_button_x, button_top_y);
}

void draw_settings_menu() {
    draw_label(&settings_menu.heading_label);
    draw_button(&settings_menu.cancel_button);
    draw_button(&settings_menu.apply_button);
    draw_drop_down(&settings_menu.resolution_drop_down);
    if (!settings_menu.resolution_drop_down.edited)
        draw_drop_down(&settings_menu.fps_drop_down);
    if (!settings_menu.resolution_drop_down.edited && !settings_menu.fps_drop_down.edited)
        draw_drop_down(&settings_menu.fullscreen_drop_down);
}

void update_settings_menu() {
    if (settings_menu.apply_button.pressed) {
        bool data_changed = false;

        /* Checks whether one of the DropDowns was set */
        if (settings_menu.resolution_drop_down.selection) {
            StringArray* resolution_options = split_str(RESOLUTION_OPTIONS, ';');
            const char* selected_resolution = resolution_options->data[settings_menu.resolution_drop_down.selection];
            StringArray* resolution_dimension = split_str(selected_resolution, 'x');

            settings.screen_resolution.x = (float) atoi(resolution_dimension->data[0]);
            settings.screen_resolution.y = (float) atoi(resolution_dimension->data[1]);

            free_str_arr(resolution_options);
            free_str_arr(resolution_dimension);
            data_changed = true;
        }
        if (settings_menu.fps_drop_down.selection) {
            StringArray* fps_options = split_str(FPS_OPTIONS, ';');

            settings.fps = atoi(fps_options->data[settings_menu.fps_drop_down.selection]);
            SetTargetFPS(settings.fps);

            free_str_arr(fps_options);
            data_changed = true;
        }
        if (settings_menu.fullscreen_drop_down.selection) {
            StringArray* fullscreen_options = split_str(FULLSCREEN_STATES, ';');

            settings.fullscreen = strcmp(fullscreen_options->data[settings_menu.fullscreen_drop_down.selection], "OFF");
            if (IsWindowFullscreen() != settings.fullscreen)
                ToggleFullscreen();

            free_str_arr(fullscreen_options);
            data_changed = true;
        }

        if (data_changed)
            write_settings();
    } else if (settings_menu.cancel_button.pressed) {
        change_state_manager_state(MAIN_MENU);
    }
}
