#include <ctype.h>
#include <libgeometry/geometry.h>
#include <stdio.h>
#include <string.h>

#include <libgeometry/geometry.c>

int main()
{
    char inp[40];
    char out[40];
    char sample[] = "circle";
    char x[] = "Координата X равна ";
    char y[] = "Координата Y равна ";
    char r[] = "Радиус равен ";
    char judge[2] = "0";
    printf("Введите параметры окружности по образцу:\n circle(x y, r)\n");
    fgets(inp, 40, stdin);
    separator(inp, sample, out, x, y, r, judge);
}