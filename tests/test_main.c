#include "unity.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_passes(void) {
    TEST_ASSERT(1);
}

void test_fails(void) {
    TEST_ASSERT(0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_passes);
    RUN_TEST(test_fails);
    return UNITY_END();
}
