#include <string.h>
#include <stdlib.h>
#include "string_util.h"

String String_create(const char *str) {
    if (str == NULL) {
        return (String){ .data = NULL, .length = 0 };
    }

    size_t length = strlen(str);
    char *data = (char *)malloc(length);

    if (data != NULL) {
        memcpy(data, str, length);
    }

    return (String){ .data = data, .length = length };
}

const char *String_to_c_string(const String *string) {
    if (string == NULL || string->data == NULL) {
        return "";
    }

    char *c_str = (char *)malloc(string->length + 1);

    if (c_str != NULL) {
        memcpy(c_str, string->data, string->length);
        c_str[string->length] = '\0'; // Null-terminate the string
    }

    return c_str;
}