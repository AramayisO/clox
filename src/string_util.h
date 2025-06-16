#ifndef CLOX_STRING_UTIL_H
#define CLOX_STRING_UTIL_H

#include <stddef.h>

struct String {
    char *data;
    size_t length;
};

typedef struct String String;

String String_create(const char* str);

const char *String_to_c_string(const String *string);

#endif // CLOX_STRING_UTIL_H