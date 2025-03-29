#ifndef C_PONG_LAYOUT_H
#define C_PONG_LAYOUT_H

#include <raylib.h>


typedef enum {
    UI_ELEMENT_BUTTON,
    UI_ELEMENT_LABEL,
    UI_ELEMENT_HEADING,
    UI_ELEMENT_DROP_DOWN,
} UIElementType;

/**
 * @brief Retrieves the predefined size of a UI element.
 *
 * This function returns the width and height of an element based on its type.
 * Labels and headings should determine their size dynamically using `MeasureText()`
 * or `MeasureTextEx()`.
 *
 * @param element The type of UI element.
 * @return A `Vector2` containing the width and height of the button in pixels.
 *         If the element type is not supported, it returns `{0, 0}`.
 */
Vector2 get_ui_size(UIElementType element);

/**
 * @brief Retrieves the margin (spacing) around a UI element.
 *
 * This function returns the appropriate outer margin for a given UI element type.
 * The margin defines the spacing between this element and others in the UI.
 *
 * @param element The type of UI element (button, label, or heading).
 * @return A `Vector2` containing the horizontal and vertical margin in pixels.
 */
Vector2 get_element_margin(UIElementType element);

/**
 * @brief Determines the font size for a given UI element.
 *
 * Since labels and headings require dynamic size calculation via `MeasureText()`,
 * this function only provides a default font size for each type.
 *
 * @param element The type of UI element (button, label, or heading).
 * @return A `Vector2` where `x` is ignored, and `y` represents the font size in pixels.
 *         Labels and headings should still use `MeasureText()` for accurate dimensions.
 */
float get_font_size(UIElementType element);

/**
 * Converts a percentage of the screen width into pixels.
 *
 * This function calculates the corresponding pixel value based on the given percentage
 * of the screen width, as defined in the `Settings` struct.
 *
 * @param percentage The percentage of the screen width (>100 results in full width).
 * @return The computed pixel value corresponding to the given percentage of the screen width.
 */
float layout_px_from_percentage_x(float percentage);

/**
 * Converts a percentage of the screen height into pixels.
 *
 * This function calculates the corresponding pixel value based on the given percentage
 * of the screen height, as defined in the `Settings` struct.
 *
 * @param percentage The percentage of the screen height (>100 results in full height).
 * @return The computed pixel value corresponding to the given percentage of the screen height.
 */
float layout_px_from_percentage_y(float percentage);

/**
 * Converts a percentage of both screen width and height into a Vector2 pixel value.
 *
 * This function returns a `Vector2` containing the corresponding pixel values for both
 * the X and Y axes, based on the given percentage of the screen dimensions.
 *
 * @param percentage The percentage of the screen dimensions (>100 results in full size).
 * @return A `Vector2` containing the computed pixel values for both axes.
 */
Vector2 layout_px_from_percentage(float percentage);

/**
 * Converts separate X and Y percentages of the screen into a Vector2 pixel value.
 *
 * This function calculates the corresponding pixel values for both the X and Y axes
 * based on the given percentages of the screen width and height, as defined in the `Settings` struct.
 *
 * @param percentage_x The percentage of the screen width (>100 results in full width).
 * @param percentage_y The percentage of the screen height (>100 results in full height).
 * @return A `Vector2` containing the computed pixel values for both axes.
 */
Vector2 layout_px_from_percentage_x_y(float percentage_x, float percentage_y);

/**
 * Calculates the X-axis center position of the screen.
 *
 * This function determines the pixel position for centering an element along the X-axis,
 * based on the screen width defined in the `Settings` struct.
 *
 * @return The pixel position at the center of the screen along the X-axis.
 */
float layout_center_x();

/**
 * Calculates the Y-axis center position of the screen.
 *
 * This function determines the pixel position for centering an element along the Y-axis,
 * based on the screen height defined in the `Settings` struct.
 *
 * @return The pixel position at the center of the screen along the Y-axis.
 */
float layout_center_y();

/**
 * Calculates the center position of the screen as a Vector2.
 *
 * This function returns a `Vector2` containing the computed pixel coordinates
 * for centering an element on both the X and Y axes.
 *
 * @return A `Vector2` representing the pixel position at the center of the screen.
 */
Vector2 layout_center();


#endif /* C_PONG_LAYOUT_H */
