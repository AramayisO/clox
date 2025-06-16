#include "unity.h"
#include "test_string_util.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_string_create_returns_empty_string_when_given_null);
    RUN_TEST(test_string_create_returns_string_with_correct_length_and_data);
    RUN_TEST(test_string_create_does_not_modify_original_string);
    RUN_TEST(test_string_to_c_string_returns_empty_string_if_string_is_null);
    RUN_TEST(test_string_to_c_string_returns_empty_string_if_string_data_is_null);
    RUN_TEST(test_string_to_c_string_returns_correct_c_string);
    return UNITY_END();
}
