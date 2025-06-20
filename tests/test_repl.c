#include <stdio.h>
#include <stdlib.h>
#include "../lib/Unity/src/unity.h"
#include "../src/repl.h"
#include "./test_repl.h"

void run_repl_tests(void) {
    RUN_TEST(test_repl_print_prompt_to_stdout_prints_correct_string_to_stdout);
    RUN_TEST(test_repl_read_line_from_stdin_reads_single_line_from_stdin);
    RUN_TEST(test_repl_read_line_from_stdin_can_be_called_repeatedly_to_read_next_lines);
    RUN_TEST(test_repl_read_line_from_stdin_returns_empty_string_is_empty);
    RUN_TEST(test_repl_read_line_from_stdin_returns_emptry_string_if_eof_is_read);
}

void test_repl_print_prompt_to_stdout_prints_correct_string_to_stdout(void) {
    char *expected = "> ";

    // Create a temporary file where stdout will be redirected
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    // Swap stdout with the temporary file
    FILE *original_stdout = stdout;
    fflush(stdout);
    stdout = tmp;

    // Call unit under test which should write to the temporary file
    repl_print_prompt_to_stdout();
    
    // Restore stdout
    fflush(stdout);
    stdout = original_stdout;

    // Check that content writen to the temporary file
    char buffer[128] = {0};
    rewind(tmp);
    fgets(buffer, sizeof(buffer), tmp);
    TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

void test_repl_read_line_from_stdin_reads_single_line_from_stdin(void) {
    char *stdin_content = "Hello, World!\nTesting 1, 2, 3\n";
    char *expected = "Hello, World!";

    // Create a temporary file that will be redirected to stdin
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    // Write content to the temporary file that will be redirected to stdin
    fputs(stdin_content, tmp);
    fflush(tmp);
    rewind(tmp);

    // Redirect the temporary file to stdin
    FILE *original_stdin = stdin;
    stdin = tmp;

    // Call unit under test that should read from stdin
    String line = repl_read_line_from_stdin();
    const char *actual = String_to_c_string(&line);

    // Restore stdin
    stdin = original_stdin;
    
    // Check that content of returned string is correct
    TEST_ASSERT_EQUAL_STRING(expected, actual);

    // Cleanup
    free((void *)actual);
    free(line.data);
}

void test_repl_read_line_from_stdin_can_be_called_repeatedly_to_read_next_lines(void) {
    char *stdin_content = "Hello, World!\nTesting 1, 2, 3\n";
    char *expected1 = "Hello, World!";
    char *expected2 = "Testing 1, 2, 3";

    // Create a temporary file that will be redirected to stdin
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    // Write content to the temporary file that will be redirected to stdin
    fputs(stdin_content, tmp);
    fflush(tmp);
    rewind(tmp);

    // Redirect the temporary file to stdin
    FILE *original_stdin = stdin;
    stdin = tmp;

    // Call unit under test that should read from stdin
    String line1 = repl_read_line_from_stdin();
    String line2 = repl_read_line_from_stdin();
    const char *actual1 = String_to_c_string(&line1);
    const char *actual2 = String_to_c_string(&line2);

    // Restore stdin
    stdin = original_stdin;
    
    // Check that content of returned string is correct
    TEST_ASSERT_EQUAL_STRING(expected1, actual1);
    TEST_ASSERT_EQUAL_STRING(expected2, actual2);

    // Cleanup
    free((void *)actual1);
    free((void *)actual2);
    free(line1.data);
    free(line2.data);
}

void test_repl_read_line_from_stdin_returns_empty_string_is_empty(void) {
    char *expected = "";

    // Create a temporary file that will be redirected to stdin
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    // Write content to the temporary file that will be redirected to stdin
    fputs(expected, tmp);
    fflush(tmp);
    rewind(tmp);

    // Redirect the temporary file to stdin
    FILE *original_stdin = stdin;
    stdin = tmp;

    // Call unit under test that should read from stdin
    String line = repl_read_line_from_stdin();

    // Restore stdin
    stdin = original_stdin;
    
    // Check that content of returned string is correct
    TEST_ASSERT_TRUE(String_is_empty(&line));

    // Cleanup
    free(line.data);
}

void test_repl_read_line_from_stdin_returns_emptry_string_if_eof_is_read(void) {
    char *stdin_content = "Hello, World!\nTesting 1, 2, 3\n";

    // Create a temporary file that will be redirected to stdin
    FILE *tmp = tmpfile();
    TEST_ASSERT_NOT_NULL(tmp);

    // Write content to the temporary file that will be redirected to stdin
    fputs(stdin_content, tmp);
    fflush(tmp);
    rewind(tmp);

    // Redirect the temporary file to stdin
    FILE *original_stdin = stdin;
    stdin = tmp;

    // Close file to cause EOF
    fclose(tmp);

    // Call unit under test that should read from stdin
    String line = repl_read_line_from_stdin();

    // Restore stdin
    stdin = original_stdin;
    
    // Check that content of returned string is correct
    TEST_ASSERT_TRUE(String_is_empty(&line));

    // Cleanup
    free(line.data);
}

