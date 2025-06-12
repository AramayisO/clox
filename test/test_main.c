#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_passes(void) {
    TEST_PASS();
}

void test_fails(void) {
    TEST_FAIL();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_passes);
    RUN_TEST(test_fails);
    return UNITY_END();
}
