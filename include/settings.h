#ifndef C_PONG_SETTINGS_H
#define C_PONG_SETTINGS_H

#include "label.h"
#include "button.h"
#include "drop_down.h"
#include <stdbool.h>
#include <raylib.h>


#define SETTINGS_FILE_PATH "./settings.ini"
#define POSSIBLE_RESOLUTIONS "Resolution;3840x2160;2560x1440;1920x1080;1280x800"

typedef struct {
    Vector2 screen_resolution;
    bool fullscreen;
    unsigned int fps;
    float sfx_volume;
    float music_volume;
} Settings;

typedef struct {
    Label heading_label;
    DropDown resolution_drop_down;
    Button cancel_button;
    Button apply_button;
} SettingsMenu;

extern Settings settings;
extern SettingsMenu settings_menu;

/**
 * @brief Initializes the settings struct.
 *
 * Tries to read and parse the settings file. If this file does not exist,
 * a new file with default valued will be created.
 *
 * @return false - if the initialization went successful, true otherwise
 */
bool init_settings();

void init_settings_menu();

void draw_settings_menu();

void update_settings_menu();

/**
 * @brief Reads/Parse content from the settings file
 *
 * Checks if the settings file exists and if so the content will be read
 * and parsed.
 *
 * @return false - if reading and parsing went successful, true otherwise
 */
bool load_settings();

/**
 * @brief Writes the content of the Settings struct to the settings file
 *
 * Takes the current content of the Settings struct and write it to the file.
 *
 * @return false - if writing went successful, true otherwise
 */
bool write_settings();

/**
 * @brief Is only neccessary for the inih parser
 *
 * @note Do not use this function outside of load_settings()
 */
static int handler(void* data, const char* section, const char* name, const char* value);

#endif /* C_PONG_SETTINGS_H */
