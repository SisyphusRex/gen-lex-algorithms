#include "../unity/src/unity.h"
#include "../include/ui.h"

void setUp(void) {};

void tearDown(void) {};

void test_ValidateIsInt(void)
{
    char *user_input = "house";
    TEST_ASSERT_EQUAL(-1, ValidateIsInt(user_input));
};

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_ValidateIsInt);
    return UNITY_END();
}