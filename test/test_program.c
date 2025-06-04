#include "../unity/include/unity.h"
#include "program.h"

void setUp(void) {};

void tearDown(void) {};

void test_run_no_args_should_return_0(void)
{
    int testReturn = run('a', 'b');
    TEST_ASSERT_EQUAL(0, testReturn);
};

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_run_no_args_should_return_0);
    return UNITY_END();
}