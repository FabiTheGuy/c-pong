#ifndef C_PONG_SETTINGS_H
#define C_PONG_SETTINGS_H

#include <stdbool.h>
#include <raylib.h>

#define SETTINGS_FILE_PATH "./settings.ini"

typedef struct {
    /* Represents the current game screen resolution. */
    Vector2 screen_resolution;
    /* Represents whether the current game screen is in Fullscreen or not */
    bool fullscreen;
    /* Represents the current FPS (frames per second) the game screen will be rendered */
    unsigned int fps;
} Settings;

extern Settings settings;

/**
 * @brief Initializes the settings struct.
 *
 * Tries to read and parse the settings file. If this file does not exist,
 * a new file with default valued will be created.
 *
 * @return false - if the initialization went successful, true otherwise
 */
bool init_settings();

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
 * @brief Is only necessary for the inih parser
 *
 * @note Do not use this function outside of load_settings()
 */
static int handler(void* data, const char* section, const char* name, const char* value);

#endif /* C_PONG_SETTINGS_H */
