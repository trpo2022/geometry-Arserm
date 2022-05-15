#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <libgeometry/geometry.c>
#include <libgeometry/geometry.h>
#define N 80


int main()
{
    char inp_one[N];
    char out_one[N];

    char inp_two[N];
    char out_two[N];

    struct storage *first;
    struct storage *second;

    first = (struct storage *)malloc(sizeof(struct storage));
    second = (struct storage *)malloc(sizeof(struct storage));
    first->sum = 0;
    second->sum = 0;

    char sample[] = "circle";
    char x[] = "Координата X равна ";
    char y[] = "Координата Y равна ";
    char r[] = "Радиус равен ";
    char judge[2] = "0";
    printf("\n");
    printf("!!------Каждое число состоит не более чем из 7 символов------!!\n");
    printf("!!-------Радиус окружности не может быть отрицательным-------!!\n");
    printf("В дробных числах целая и дробная части записываются через точку:\nК примеру, 3.1415\n");
    printf("\n");
    printf("Введите параметры 1-й окружности по образцу:\n circle(x y, r)\n");
    fgets(inp_one, N, stdin);

    printf("Введите параметры 2-й окружности по образцу:\n circle(x y, r)\n");
    fgets(inp_two, N, stdin);

    printf("Для первой фигуры\n");
    separator(inp_one, sample, out_one, x, y, r, judge, first);
    printf("\n");

    printf("Для второй фигуры\n");
    separator(inp_two, sample, out_two, x, y, r, judge, second);
    printf("\n");

    intersection(first, second);

    perimeter_and_area(first, second);    

}
