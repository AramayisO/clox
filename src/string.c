#include "../include/string.h"
#include <_string.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#define THIS(

const char* GetRawCString(String *s)
{
    if (!s) {
        return "";
    }
    return s->str;
}

String NewHeapAllocatedString(char *str)
{
    size_t str_length = strlen(str);
    size_t buf_length = str_length + 1;
    char *buf = (char*) malloc(buf_length* sizeof(str));
    memcpy(buf, str, buf_length * sizeof(char));
    return (String) { .str=buf, .len=str_length, .GetRawCString=GetRawCString };
}

