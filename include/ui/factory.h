/**
 * @file factory.h
 * @brief UI factory functions for creating common UI components with
 *        consistent layout, font size, and styling across the application.
 *
 * These functions centralize the creation logic for standard UI elements
 * such as buttons and labels, using default UI configuration values.
 *
 * This avoids redundant setup code in multiple menus and ensures
 * consistency across different UI contexts.
 */
#ifndef C_PONG_UI_FACTORY_H
#define C_PONG_UI_FACTORY_H

#include "ui/button.h"
#include "ui/label.h"
#include "ui/drop-down.h"


/**
 * @brief Creates and returns a fully configured Button UI element with standard layout.
 *
 * This function centers the button and uses the default button font size and layout
 * settings defined in `ui/layout.h`.
 *
 * @param content The content string displayed on the button
 * @param center_x The horizontal center point where the button should be aligned
 * @param top_y The top y-coordinate of the button’s position
 * @return A fully initialized Button struct with proper bounds and visual styling
 */
Button ui_create_button(char* content, const float center_x, const float top_y);

/**
 * @brief Creates and returns a fully configured Label UI element, typically for headings.
 *
 * This function centers the label horizontally and uses the default heading font
 * size and layout settings defines in `ui/layout.h`.
 *
 * @param content The content string of the label
 * @param center_x The horizontal center point where the label should be aligned
 * @param top_y The top y-coordinate of the label’s position
 * @return A fully initialized Label struct with proper bounds and visual styling
 */
Label ui_create_heading(char* content, const float center_x, const float top_y);

/**
 * @brief Creates and returns a fully configured DropDown UI element with standard layout.
 *
 * This function centers the dropdown and uses the default dropdown font size and
 * layout settings defined in `ui/layout.h`
 *
 * @param options The options displayed in the dropdown seperated with an ";"
 * @param center_x The horizontal center point where the label should be aligned
 * @param top_y The top y-coordinate of the dropdowns position
 * @param selection The Option which should be selected by default (starting at 0)
 * @return A fully initialized DropDown struct with proper bounds and visual styling
 */
DropDown ui_create_drop_down(char* options, const float center_x, const float top_y, const int selection);

#endif /* C_PONG_UI_FACTORY_H */
