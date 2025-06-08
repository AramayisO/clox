#include <sysexits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EX_USAGE);
    }
    return 0;
}
