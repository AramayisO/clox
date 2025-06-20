#include "../lib/Unity/src/unity.h"
#include "./test_string_util.h"
#include "./test_repl.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(void) {
    UNITY_BEGIN();
    run_string_util_tests();
    run_repl_tests();
    return UNITY_END();
}
