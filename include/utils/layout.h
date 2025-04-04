/**
 * @file layout.h
 * @brief General-purpose layout utilities for screen positionning.
 *
 * This header defines functions for converting percentage-based layout
 * values into absolute pixel values based on the current screen resolution.
 * These functions are intended to be resolution-independent and reusable
 * across different parts of the application, including both the UI and
 * gameplay layers.
 *
 * Unlike the layout utilities in `ui/layout.h` and `gameplay/layout.h`,
 * the functions declared here are not tied to specific domain elements
 * such as UI components or game objects. They provide low-level utilities
 * to assist with consistent layout calculations across the codebase.
 */
#ifndef C_PONG_UTILS_LAYOUT_H
#define C_PONG_UTILS_LAYOUT_H

#include <raylib.h>


/**
 * @brief Converts a horizontal percentage to a pixel value.
 *
 * Maps a percentage (0–100) to an absolute x-coordinate in pixels,
 * based on the current screen width.
 *
 * @param percentage Percentage value to convert (0.0 to 100.0).
 *                   Values are clamped within this range.
 * @return The corresponding x-coordinate in pixels.
 */
float layout_px_from_percentage_x(float percentage);

/**
 * @brief Converts a vertical percentage to a pixel value.
 *
 * Maps a percentage (0–100) to an absolute y-coordinate in pixels,
 * based on the current screen height.
 *
 * @param percentage Percentage value to convert (0.0 to 100.0).
 *                   Values are clamped within this range.
 * @return The corresponding y-coordinate in pixels.
 */
float layout_px_from_percentage_y(float percentage);

/**
 * @brief Converts a single percentage value to both x and y pixel values.
 *
 * Applies the same percentage value to both axes, mapping it to pixel
 * coordinates relative to the screen width and height.
 *
 * @param percentage Percentage value to convert (0.0 to 100.0).
 *                   Values are clamped within this range.
 * @return A Vector2 containing x and y pixel values.
 */
Vector2 layout_px_from_percentage(float percentage);

/**
 * @brief Converts separate horizontal and vertical percentages to pixel values.
 *
 * Maps the given x and y percentages to a 2D position in pixels, relative to
 * the screen width and height.
 *
 * @param percentage_x Horizontal percentage (0.0 to 100.0).
 * @param percentage_y Vertical percentage (0.0 to 100.0).
 *                     Values are clamped within this range.
 * @return A Vector2 representing the position in pixels.
 */
Vector2 layout_px_from_percentage_x_y(float percentage_x, float percentage_y);

/**
 * @brief Returns the horizontal center position in pixels.
 *
 * Calculates the screen’s center x-coordinate based on its current width.
 *
 * @return The x-coordinate of the horizontal center.
 */
float layout_center_x();

/**
 * @brief Returns the vertical center position in pixels.
 *
 * Calculates the screen’s center y-coordinate based on its current height.
 *
 * @return The y-coordinate of the vertical center.
 */
float layout_center_y();

/**
 * @brief Returns the center point of the screen in pixels.
 *
 * Combines the horizontal and vertical center positions into a 2D vector.
 *
 * @return A Vector2 representing the screen’s center in pixels.
 */
Vector2 layout_center();

#endif /* C_PONG_UTILS_LAYOUT_H */
