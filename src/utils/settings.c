#include "settings.h"
#include "raygui.h"
#include "label.h"
#include "button.h"
#include "drop_down.h"
#include "layout.h"

#include "state_manager.h"
#include "utils.h"

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ini.h>


Settings settings;
SettingsMenu settings_menu;

bool init_settings() {
    settings = (Settings) {0};

    if (!load_settings())
        return false;

    /* Default values */
    settings = (Settings) {
        .screen_resolution = (Vector2) { .x = 1280, .y = 800 },
        .fullscreen = false,
        .fps = 60,
    };

    if (write_settings()) {
        fprintf(stderr, "Unable to write the settings: %s\n", strerror(errno));
        return true;
    }

    return false;
}

void init_settings_menu() {
    settings_menu = (SettingsMenu) {0};

    const float center_screen_x = layout_center_x();
    const float heading_font_size = get_font_size(UI_ELEMENT_HEADING);
    const Vector2 heading_margin = get_element_margin(UI_ELEMENT_HEADING);

    /*
     * Heading
     */
    const char* heading_content = "Settings";
    const Vector2 heading_dimension = MeasureTextEx(GetFontDefault(), heading_content, heading_font_size, TEXT_SPACING);
    settings_menu.heading_label = (Label) {
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
     * Resolution DropDown
     */
    const Vector2 drop_down_dimension = get_ui_size(UI_ELEMENT_DROP_DOWN);
    const float drop_down_font_size = get_font_size(UI_ELEMENT_DROP_DOWN);
    const float distance_drop_down_top =
       settings_menu.heading_label.bounds.y +
       settings_menu.heading_label.bounds.height + 
       heading_margin.y;

    settings_menu.resolution_drop_down = (DropDown) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (drop_down_dimension.x / 2),
            .y = distance_drop_down_top,
            .width = drop_down_dimension.x,
            .height = drop_down_dimension.y,
        },
        .options = POSSIBLE_RESOLUTIONS,
        .font_size = drop_down_font_size,
        .selection = 0,
        .edited = false,
    };

    /*
     * FPS DropDown
     */
    const Vector2 drop_down_margin = get_element_margin(UI_ELEMENT_DROP_DOWN);
    const float distance_fps_drop_down_top = 
        settings_menu.resolution_drop_down.bounds.y +
        settings_menu.resolution_drop_down.bounds.height +
        drop_down_margin.y;

    settings_menu.fps_drop_down = (DropDown) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (drop_down_dimension.x / 2),
            .y = distance_fps_drop_down_top,
            .width = drop_down_dimension.x,
            .height = drop_down_dimension.y,
        },
        .options = POSSIBLE_FPS,
        .font_size = drop_down_font_size,
        .selection = 0,
        .edited = false,
    };

    /*
     * Fullscreen DropDown
     */
    const float distance_fullscreen_drop_down_top =
        settings_menu.fps_drop_down.bounds.y +
        settings_menu.fps_drop_down.bounds.height +
        drop_down_margin.y;
    
    settings_menu.fullscreen_drop_down = (DropDown) {
        .bounds = (Rectangle) {
            .x = center_screen_x - (drop_down_dimension.x / 2),
            .y = distance_fullscreen_drop_down_top,
            .width = drop_down_dimension.x,
            .height = drop_down_dimension.y,
        },
        .options = POSSIBLE_FULLSCREEN_STATES,
        .font_size = drop_down_font_size,
        .selection = 0,
        .edited = false,
    };

    /*
     * Cancel Button
     */
    const Vector2 button_margin = get_element_margin(UI_ELEMENT_BUTTON);
    const Vector2 button_dimension = get_ui_size(UI_ELEMENT_BUTTON);
    const float button_font_size = get_font_size(UI_ELEMENT_BUTTON);
    const float distance_button_group_bot = 
        settings.screen_resolution.y -
        button_dimension.y -
        button_margin.y;

    settings_menu.cancel_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_screen_x - button_dimension.x - button_margin.x,
            .y = distance_button_group_bot,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .font_size = button_font_size,
        .content = "Cancel",
        .pressed = false,
    };

    /*
     * Apply Button
     */
    settings_menu.apply_button = (Button) {
        .bounds = (Rectangle) {
            .x = center_screen_x + 
            button_margin.x,
            .y = distance_button_group_bot,
            .width = button_dimension.x,
            .height = button_dimension.y,
        },
        .font_size = button_font_size,
        .content = "Apply",
        .pressed = false,
    };
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
            StringArray* resolution_options = split_str(POSSIBLE_RESOLUTIONS, ';');
            char* selected_resolution = resolution_options->data[settings_menu.resolution_drop_down.selection];
            StringArray* resolution_dimension = split_str(selected_resolution, 'x');

            settings.screen_resolution.x = (float) atoi(resolution_dimension->data[0]);
            settings.screen_resolution.y = (float) atoi(resolution_dimension->data[1]);

            free_str_arr(resolution_options);
            free_str_arr(resolution_dimension);
            data_changed = true;
        } 
        if (settings_menu.fps_drop_down.selection) {
            StringArray* fps_options = split_str(POSSIBLE_FPS, ';');

            settings.fps = atoi(fps_options->data[settings_menu.fps_drop_down.selection]);
            SetTargetFPS(settings.fps);

            free_str_arr(fps_options);
            data_changed = true;
        } 
        if (settings_menu.fullscreen_drop_down.selection) {
            StringArray* fullscreen_options = split_str(POSSIBLE_FULLSCREEN_STATES, ';');

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

bool load_settings() {
    /* Checks if the File exists or not */
    FILE* file;
    if ((file = fopen(SETTINGS_FILE_PATH, "r")) == NULL) {
        return true;
    }
    fclose(file);

    /* Parse content from ini file into settings */
    if (ini_parse(SETTINGS_FILE_PATH, handler, &settings) < 0) {
        fprintf(stderr, "Can't load %s\n", SETTINGS_FILE_PATH);
        return true;
    }

    return false;
}

bool write_settings() {
    FILE* file;

    if ((file = fopen(SETTINGS_FILE_PATH, "w")) == NULL)
        return true;

    fprintf(file, "[Video]\n");
    fprintf(file, "screen_resolution=%ix%i\n", (int) settings.screen_resolution.x, (int) settings.screen_resolution.y);
    fprintf(file, "fullscreen=%b\n", settings.fullscreen);
    fprintf(file, "fps=%i\n", settings.fps);

    fclose(file);

    return false;
}

static int handler(void* data, const char* section, const char* name, const char* value) {
    Settings* settings = (Settings*) data;

    #define MATCH(s, n) (strcasecmp(section, s) == 0 && strcasecmp(name, n) == 0)
    if (MATCH("video", "screen_resolution")) {
        StringArray* resolution_str = split_str(value, 'x');

        if (resolution_str->size != 2) {
            free_str_arr(resolution_str);
            return 0;
        }
            
        settings->screen_resolution.x = (float) atoi(resolution_str->data[0]);
        settings->screen_resolution.y = (float) atoi(resolution_str->data[1]);

        free_str_arr(resolution_str);
    } else if (MATCH("video", "fullscreen")) {
        settings->fullscreen = (bool) atoi(value);
    } else if (MATCH("video", "fps")) {
        settings->fps = atoi(value);
    } else {
        return 0;
    }

    return 1;
}
