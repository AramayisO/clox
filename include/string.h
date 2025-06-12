#pragma once

#include <stddef.h>

struct String {
    char *str;
    size_t len;
    const char* (*GetRawCString)(struct String *self);
    struct String (*Concat)(struct String *self, struct String *other);
    struct String (*Strip)(struct String *self);
    bool (*Equal)(struct String *self, struct String *other);
};

typedef struct String String;

String NewHeapAllocatedString(char *str);
