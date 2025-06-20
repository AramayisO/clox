#ifndef CLOX_REPL_H
#define CLOX_REPL_H

#include "./string_util.h"

void repl_print_prompt_to_stdout(void);

String repl_read_line_from_stdin(void);

#endif // CLOX_REPL_H
