#include <stdio.h>
#include <stdlib.h>
#include "./string_util.h"
#include "./repl.h"

#define REPL_PROMPT "> "

void repl_print_prompt_to_stdout(void) {
    printf(REPL_PROMPT);
}

String repl_read_line_from_stdin(void) {
    char *line = NULL;
    size_t cap = 0;
    ssize_t line_len = getline(&line, &cap, stdin);
    String string;

    if (line_len > 0) {
        if (line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
        }
        string = String_create(line);
    } else {
        string = String_empty();
    }
    
    if (line != NULL) {
        free(line);
    }

    return string;
}
