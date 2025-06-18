#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/Unity/src/unity.h"
#include "../src/string_util.h"
#include "./test_string_util.h"

void run_string_util_tests(void) {
    RUN_TEST(test_string_create_returns_empty_string_when_given_null);
    RUN_TEST(test_string_create_returns_string_with_correct_length_and_data);
    RUN_TEST(test_string_create_does_not_modify_original_string);
    RUN_TEST(test_string_empty_returns_empty_string);
    RUN_TEST(test_string_is_empty_returns_true_if_string_is_null);
    RUN_TEST(test_string_is_empty_returns_true_if_string_data_is_null);
    RUN_TEST(test_strign_is_empty_returns_true_if_string_length_is_zero);
    RUN_TEST(test_string_is_empty_returns_false_if_string_is_not_empty);
    RUN_TEST(test_string_to_c_string_returns_empty_string_if_string_is_null);
    RUN_TEST(test_string_to_c_string_returns_empty_string_if_string_data_is_null);
    RUN_TEST(test_string_to_c_string_returns_correct_c_string);
}

void test_string_create_returns_empty_string_when_given_null(void) {
    String string = String_create(NULL);
    TEST_ASSERT_EQUAL(0, string.length);
    TEST_ASSERT_NULL(string.data);
}

void test_string_create_returns_string_with_correct_length_and_data(void) {
    const char *str = "Hello, World!";
    String string = String_create(str);
    TEST_ASSERT_EQUAL(strlen(str), string.length);
    TEST_ASSERT_NOT_NULL(string.data);
    TEST_ASSERT_EQUAL_MEMORY(str, string.data, string.length);
}

void test_string_create_does_not_modify_original_string(void) {
    const char *original_str = "Hello, World!";
    char *str = malloc(strlen(original_str) + 1);
    strcpy(str, original_str);
    String string = String_create(str);
    TEST_ASSERT_EQUAL_STRING(original_str, str);
}

void test_string_empty_returns_empty_string(void) {
    String empty_string = String_empty();
    TEST_ASSERT_NULL(empty_string.data);
    TEST_ASSERT_EQUAL(0, empty_string.length);
}

void test_string_is_empty_returns_true_if_string_is_null(void) {
    String *string = NULL;
    TEST_ASSERT_TRUE(String_is_empty(string));
}

void test_string_is_empty_returns_true_if_string_data_is_null(void) {
    String string = (String){ .data = NULL, .length = 1 };
    TEST_ASSERT_TRUE(String_is_empty(&string));
}

void test_strign_is_empty_returns_true_if_string_length_is_zero(void) {
    char *str= "";
    String string = (String){ .data = str, .length = 0 };
    TEST_ASSERT_TRUE(String_is_empty(&string));
}

void test_string_is_empty_returns_false_if_string_is_not_empty(void) {
    char *str= "Hello, World!";
    size_t length = strlen(str);
    String string = (String){ .data = str, .length = length };
    TEST_ASSERT_FALSE(String_is_empty(&string));
}

void test_string_to_c_string_returns_empty_string_if_string_is_null(void) {
    const char *exepcted = ""; 
    const char *actual = String_to_c_string(NULL);
    TEST_ASSERT_EQUAL_STRING(exepcted, actual);
}

void test_string_to_c_string_returns_empty_string_if_string_data_is_null(void) {
    String string = { .data = NULL, .length = 0 };
    const char *actual = String_to_c_string(&string);
    const char *expected = "";
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_string_to_c_string_returns_correct_c_string(void) {
    const char *expected = "Hello, World!";
    size_t length = strlen(expected);
    char *data = malloc(sizeof(char) * length);
    memcpy(data, expected, sizeof(char) * length);
    String string = {.data = data, .length = length};
    const char *actual = String_to_c_string(&string);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}
