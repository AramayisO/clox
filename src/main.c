#include <string.h>
#include <sysexits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/string.h"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EX_USAGE);
    }
    String str = NewHeapAllocatedString("123");
    const char *c_str = str.GetRawCString(&str);
    printf("%s\n", c_str);
    return 0;
}
