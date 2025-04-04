#ifndef C_PONG_UTILS_STRING_ARRAY_H
#define C_PONG_UTILS_STRING_ARRAY_H

#include <stddef.h>


typedef struct {
    /* Pointer, which points to the heads of the strings. */
    char** data;
    /* Represents the amount of pointers contained in data. */
    size_t size;
} StringArray;

/**
 * Creates a dynamically allocated string array with a specified capacity.
 *
 * @param capacity The number of elements the string array can hold.
 * @return A pointer to the allocated StringArray structure, or NULL if allocation fails.
 */
StringArray* create_str_arr(size_t capacity);

/**
 * Frees the memory allocated for a StringArray, including all its elements.
 *
 * @param string_array Pointer to the StringArray to be freed.
 *                If the pointer is NULL, the function returns immediately.
 */
void free_str_arr(StringArray* string_array);

/**
 * Splits a given string into substrings based on a specified delimiter character.
 *
 * @param str The input string to be split. It should be a null-terminated character array.
 *            Passing NULL will result in a NULL return value.
 * @param del The delimiter character used to split the string.
 * @return A pointer to a dynamically created StringArray structure containing the substrings.
 *         If memory allocation fails or the input string is NULL, NULL is returned.
 */
StringArray* split_str(const char* str, char del);

#endif /* C_PONG_UTILS_STRING_ARRAY_H */