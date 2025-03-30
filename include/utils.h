#ifndef C_PONG_UTILS_H
#define C_PONG_UTILS_H

#include <stddef.h>


typedef struct {
    char** data;
    size_t size;
} StringArray;

StringArray* create_str_arr(size_t capacity);

void free_str_arr(StringArray* string_array);

StringArray* split_str(const char* str, char del);

#endif /* C_PONG_UTILS_H */