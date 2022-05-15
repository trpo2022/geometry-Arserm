#include <libgeometry/geometry.h>
#include <libgeometry/geometry.c>

#include "../thirdparty/ctest.h"

CTEST(ctest, simple_test)
{ 
    char inp_two[] = "circle(1.6 2,3)";
    char sample[] = "circle";
    char judge[] = "0";
    char out_two[80];
    char x[] = "Координата X равна ";
    char y[] = "Координата Y равна ";
    char r[] = "Радиус равен ";
    struct storage *second;
    second = (struct storage *)malloc(sizeof(struct storage));

    separator(inp_two, sample, out_two, x, y, r, judge, second);
    ASSERT_DBL_NEAR_TOL(1.6, second->x, 0);  
    ASSERT_EQUAL(2, second->y);      
    ASSERT_EQUAL(3, second->r);
    ASSERT_EQUAL(3, second->sum);

    free(second);
}

CTEST(ctest, simple_test1)
{ 
    char inp_two[] = "circle(1.6 2,3)";
    char sample[] = "circle";
    char judge[] = "0";
    char out_two[80];
    char x[] = "Координата X равна ";
    char y[] = "Координата Y равна ";
    char r[] = "Радиус равен ";
    struct storage *second;
    second = (struct storage *)malloc(sizeof(struct storage));

    separator(inp_two, sample, out_two, x, y, r, judge, second);
    ASSERT_DBL_NEAR_TOL(1.6, second->x, 0);  
    ASSERT_EQUAL(2, second->y);      
    ASSERT_EQUAL(3, second->r);
    ASSERT_EQUAL(3, second->sum);

    free(second);
}
