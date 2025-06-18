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

String String_empty(void) {
    return (String){ .data = NULL, .length = 0 };
}

const char *String_to_c_string(const String *string) {
    size_t string_length = 0;

    if (string != NULL && string->data != NULL) {
        string_length = string->length;
    }

    char *c_str = (char *)malloc(string_length + 1);

    if (string != NULL && string->data != NULL) {
        memcpy(c_str, string->data, string_length);
    }

    c_str[string_length] = '\0';
    return c_str;
}
