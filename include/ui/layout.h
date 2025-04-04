#ifndef C_PONG_UI_LAYOUT_H
#define C_PONG_UI_LAYOUT_H

#include <raylib.h>


typedef enum {
    UI_ELEMENT_BUTTON,
    UI_ELEMENT_LABEL,
    UI_ELEMENT_HEADING,
    UI_ELEMENT_DROP_DOWN,
} UIElementType;

/**
 * Retrieves the size of a UI element based on its type.
 *
 * @param element The type of UI element whose size is to be retrieved.
 * @return A Vector2 structure representing the width (x) and height (y) of the UI element.
 *         Returns (0, 0) for unsupported element types.
 */
Vector2 get_ui_size(UIElementType element);

/**
 * Retrieves the margin for a specific UI element type.
 *
 * @param element The UI element type for which the margin is to be fetched.
 * @return A Vector2 structure representing the x and y margins of the specified UI element.
 *         Returns (0, 0) for unsupported element types.
 */
Vector2 get_element_margin(UIElementType element);

/**
 * Determines the font size for a specified UI element type.
 *
 * This method returns the font size in pixels based on the UI
 * element type. The font size is calculated relative to the
 * layout and screen dimensions.
 *
 * @param element The type of UI element (e.g., button, label, heading).
 * @return The calculated font size in pixels for the specified UI element.
 *         Returns 0 for unsupported element types.
 */
int get_font_size(UIElementType element);

/**
 * Converts the given percentage to a pixel value along the x-axis,
 * based on the current screen resolution settings.
 *
 * @param percentage The percentage value (0 to 100) to convert to pixels
 *                   along the x-axis. Values less than 0 are clamped to 0,
 *                   and values greater than 100 are clamped to the maximum
 *                   screen resolution's x value.
 * @return The equivalent pixel value along the x-axis corresponding to the
 *         given percentage.
 */
float layout_px_from_percentage_x(float percentage);

/**
 * Converts the given percentage to a pixel value along the y-axis,
 * based on the current screen resolution settings.
 *
 * @param percentage The percentage value (0 to 100) to convert to pixels
 *                   along the y-axis. Values less than 0 are clamped to 0,
 *                   and values greater than 100 are clamped to the maximum
 *                   screen resolution's y value.
 * @return The equivalent pixel value along the y-axis corresponding to the
 *         given percentage.
 */
float layout_px_from_percentage_y(float percentage);

/**
 * Converts the given percentage to a pixel Vector along the x-/y-axis
 * based on the current screen resolution settings.
 *
 * @param percentage The percentage value (0 to 100) to convert to pixels
 *                   along the x-/y-axis. Values less than 0 are clamped to 0,
 *                   and values greater than 100 are clamped to the maximum
 *                   screen resolution's x/y value.
 * @return The equivalent pixel value along the x-/y-axis corresponding to the
 *         given percentage.
 */
Vector2 layout_px_from_percentage(float percentage);

/**
 * Converts the given percentages to a pixel Vector along the x-/y-axis based
 * on the current screen resolution settings.
 *
 * @param percentage_x The horizontal percentage value (0 to 100) to convert.
 *                      Values greater than or equal to 100 will return the full screen width.
 *                      Values less than or equal to 0 will return 0.
 * @param percentage_y The vertical percentage value (0 to 100) to convert.
 *                      Values greater than or equal to 100 will return the full screen height.
 *                      Values less than or equal to 0 will return 0.
 * @return A Vector2 structure holding the pixel values for the x and y dimensions.
 *          If either percentage_x or percentage_y is out of the valid range (0-100),
 *          the return value will reflect the clamped or boundary pixel values.
 */
Vector2 layout_px_from_percentage_x_y(float percentage_x, float percentage_y);

/**
 * Calculates and returns the horizontal center position of the layout
 * based on the screen resolution.
 *
 * @return The horizontal center position (x-coordinate) of the layout.
 */
float layout_center_x();

/**
 * Calculates and returns the vertical center position of the screen resolution.
 *
 * @return The vertical center position as a float, based on the screen resolution height.
 */
float layout_center_y();

/**
 * Computes the center point of the layout in terms of the screen resolution.
 *
 * @return A Vector2 representing the x and y coordinates of the center point.
 */
Vector2 layout_center();

#endif /* C_PONG_UI_LAYOUT_H */
