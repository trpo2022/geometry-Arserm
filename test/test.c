#include <libgeometry/geometry.h>

#include "../thirdparty/ctest.h"

CTEST(ctest, simple_test)
{
    short flag;
    int a = 8;
    int b = 7;
    short flag_exp = 15;
    flag = sum(a, b);
    ASSERT_EQUAL(flag_exp, flag);
}