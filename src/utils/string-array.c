#include "utils/string-array.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief Creates a new dynamic StringArray with a given capacity.
 * 
 * @param capacity The number of string slots to allocate.
 * @return StringArray* Pointer to the allocated StringArray, or NULL if allocation fails.
 */
StringArray* create_str_arr(size_t capacity) {
    StringArray* str_arr = (StringArray*) malloc(sizeof(StringArray));

    if (str_arr == NULL)
        return NULL;

    if ((str_arr->data = (char**) malloc(capacity * sizeof(char*))) == NULL) {
        free(str_arr);
        return NULL;
    }

    for (size_t i = 0; i < capacity; i++)
        str_arr->data[i] = NULL;

    str_arr->size = capacity;

    return str_arr;
}

/**
 * @brief Frees all memory associated with a StringArray.
 * 
 * @param str_arr Pointer to the StringArray to free.
 */
void free_str_arr(StringArray* str_arr) {
    if (str_arr == NULL)
        return;

    for (size_t i = 0; i < str_arr->size; i++) {
        if (str_arr->data[i] != NULL)
            free(str_arr->data[i]);
    }
        
    free(str_arr->data);
    free(str_arr);
}

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 * 
 * @param str The input string to split.
 * @param del The delimiter character to split by.
 * @return StringArray* Pointer to a dynamically allocated StringArray, or NULL if allocation fails.
 */
StringArray* split_str(const char* str, char del) {
    if (str == NULL)
        return NULL;

    char* str_dup = strdup(str);
    if (str_dup == NULL)
        return NULL;

    size_t str_len = strlen(str);
    size_t del_count = 0;

    for (size_t i = 0; i < str_len; i++)
        del_count += str[i] == del;

    StringArray* str_arr = create_str_arr(del_count + 1);
    if (str_arr == NULL) {
        free(str_dup);
        return NULL;
    }

    size_t index = 0;
    char* token = strtok(str_dup, &del);
    while (token != NULL) {
        str_arr->data[index] = strdup(token);
        if (str_arr->data[index] == NULL) {
            free_str_arr(str_arr);
            free(str_dup);
            return NULL;
        }

        index++;
        token = strtok(NULL, &del);
    }

    return str_arr;
}