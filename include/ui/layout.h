/**
 * @file ui/layout.h
 * @brief Layout utilities specific to UI elements.
 *
 * This header defines functions and types related to UI layout management,
 * such as determining element sizes, margins, and font sizes for different
 * UI components. These utilities help ensure consistent spacing and scaling
 * of interface elements based on screen resolution and element type.
 *
 * This header is specifically focused on UI-related layout concerns and is
 * separate from general layout utilities or gameplay layout logic.
 */
#ifndef C_PONG_UI_LAYOUT_H
#define C_PONG_UI_LAYOUT_H

#include <raylib.h>


/**
 * @brief Enumeration of supported UI element types.
 *
 * Used to distinguish between different categories of UI elements
 * such as buttons, labels, headings, and dropdown menus, ... .
 */
typedef enum {
    UI_ELEMENT_BUTTON,
    UI_ELEMENT_LABEL,
    UI_ELEMENT_HEADING,
    UI_ELEMENT_DROP_DOWN,
} UIElementType;

/**
 * @brief Retrieves the size of a UI element based on its type.
 *
 * Determines the width and height of a given UI element type.
 * Sizes may be scaled relative to screen resolution or other layout rules.
 *
 * @param element The UI element type.
 * @return A Vector2 representing the element's width (x) and height (y) in pixels.
 *         Returns (0, 0) for unsupported or unknown types.
 */
Vector2 get_ui_size(UIElementType element);

/**
 * @brief Retrieves the margin applied to a specific UI element type.
 *
 * Margins define spacing around the element, typically used for layout padding
 * or spacing between elements in a container.
 *
 * @param element The UI element type.
 * @return A Vector2 representing horizontal (x) and vertical (y) margins in pixels.
 *         Returns (0, 0) for unsupported or unknown types.
 */
Vector2 get_ui_element_margin(UIElementType element);

/**
 * @brief Calculates the font size for a given UI element type.
 *
 * Font sizes are determined based on element type and may be scaled according
 * to screen dimensions or layout settings.
 *
 * @param element The UI element type (e.g., button, label, heading).
 * @return The recommended font size in pixels. Returns 0 for unsupported or unknown types.
 */
int get_ui_font_size(UIElementType element);

#endif /* C_PONG_UI_LAYOUT_H */
