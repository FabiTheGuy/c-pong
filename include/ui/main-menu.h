#ifndef C_PONG_MAIN_MENU_H
#define C_PONG_MAIN_MENU_H

#include "button.h"
#include "label.h"


typedef struct {
    Label heading_label;
    Button start_button;
    Button settings_button;
    Button quit_button;
} MainMenu;

extern MainMenu main_menu;

/**
 * @brief Initializes the main menu by setting up the heading and buttons.
 * 
 * This function sets the properties for the `main_menu` object, including the position,
 * font size, and content for the heading label and each of the buttons (Start, Settings, Quit).
 * It is typically called once at the start of the game to set up the menu.
 */
void init_main_menu();

/**
 * @brief Draws the main menu on the screen.
 * 
 * This function renders the `main_menu` components (heading and buttons) on the screen.
 * It calls the `draw_label` function to draw the heading and `draw_button` for each of the buttons.
 */
void draw_main_menu();

/**
 * @brief Updates the state of the main menu based on user input.
 * 
 * This function checks if any of the buttons in the `main_menu` are pressed and performs
 * the appropriate actions (e.g., starting the game, opening settings, quitting the game).
 * It is typically called every frame during the game loop.
 */
void update_main_menu();

#endif /* C_PONG_MAIN_MENU_H */
