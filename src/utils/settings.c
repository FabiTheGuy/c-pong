#include "utils/settings.h"
#include "utils/string-array.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ini.h>
#include <raylib.h>


Settings settings;

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
    fprintf(file, "fullscreen=%i\n", settings.fullscreen);
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
