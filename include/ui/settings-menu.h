#ifndef C_PONG_SETTINGS_MENU_H
#define C_PONG_SETTINGS_MENU_H

#include "label.h"
#include "drop-down.h"
#include "button.h"

#define RESOLUTION_OPTIONS "Resolution;3840x2160;2560x1440;1920x1080;1280x800"
#define FPS_OPTIONS "FPS;60;30"
#define FULLSCREEN_STATES "Fullscreen;ON;OFF"

typedef struct {
    Label heading_label;
    DropDown resolution_drop_down;
    DropDown fps_drop_down;
    DropDown fullscreen_drop_down;
    Button cancel_button;
    Button apply_button;
} SettingsMenu;

extern SettingsMenu settings_menu;

/**
 * @brief Initializes the settings menu by setting up the heading and buttons.
 *
 * This function sets the properties for the `settings_menu` object, including the position,
 * font size, and content for the heading label and each of the buttons (Start, Settings, Quit).
 * It is typically called once at the start of the game to set up the menu.
 */
void init_settings_menu();

/**
 * @brief Draws the settings menu on the screen.
 *
 * This function renders the `settings_menu` components (heading, drop-downs and buttons) on the screen.
 * It calls the `draw_label` function to draw the heading and `draw_drop_down` for each of the drop-downs
 * and `draw_button` for each of the buttons.
 */
void draw_settings_menu();

/**
 * @brief Updates the state of the settings menu based on user input.
 *
 * This function checks if any of the drop-downs or buttons in the `settings_menu` are pressed and applies
 * them to the game (Resolution change need a restart).
 * It is typically called every frame during the game loop.
 */
void update_settings_menu();

#endif /* C_PONG_SETTINGS_MENU_H */
