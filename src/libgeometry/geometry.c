#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "geometry.h"

void separator(
        char *inp,
        char *sample,
        char *out,
        char *x,
        char *y,
        char *r,
        char *judge,
        struct storage *store)
{
    int step = 0;
    int elem = 0;
    int flag = 0;
    int index = 0;
    int indicator = 0;
    int traitor = 0;
    int exit = 0;

    for (size_t i = 0; i < strlen(inp); i++) {
        if (inp[i] != ' ')
            break;
        else
            step = i + 1;
    }
    indicator = step;
    for (size_t i = step; i < strlen(inp); i++) {
        step = i;
        if ((inp[i] == ' ') || (inp[i] == '(') || (inp[i] == '('))
            break;
        else {
            flag++;
            if (sample[elem] == tolower(inp[i]))
                elem++;
        }
    }

    if (elem == 6 && flag == 6) {
        printf("Ваша фигура окружность\n");
        for (size_t i = step; i < strlen(inp); i++) {
            step = i + 1;
            indicator = step;
            if (inp[i] != ' ') {
                if (inp[i] == ')') {
                    printf(" вы препутали скобку\n");
                    break;
                }

                if (inp[i] == '(') {
                    for (size_t i = step; i < strlen(inp); i++) {
                        step = i + 1;
                        if (inp[i] != ' ') {
                            out[index] = inp[i];
                            index++;
                            flag = 1;
                            if (traitor == 0) {
                                traitor = 1;
                                indicator = step;
                            }
                        } else if (flag == 1)
                            break;
                    }
                    chislo(out, x, judge, store);
                    flag = 0;
                    index = 0;
                    traitor = 0;
                    if (judge[0] == '0') {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for (size_t i = step; i < strlen(inp); i++) {
                        step = i + 1;
                        if (inp[i] == ',')
                            break;
                        if (inp[i] != ' ') {
                            out[index] = inp[i];
                            index++;
                            flag = 1;
                            if (traitor == 0) {
                                traitor = 1;
                                indicator = step;
                            }
                        } else if (flag == 1)
                            break;
                    }
                    chislo(out, y, judge, store);
                    flag = 0;
                    index = 0;
                    traitor = 0;
                    if (judge[0] == '0') {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for (size_t i = step - 1; i < strlen(inp); i++) {
                        step = i + 1;
                        if (inp[i] != ' ') {
                            if (inp[i] != ',') {
                                indicator = step;
                                exit = 1;
                                break;
                            } else
                                break;
                        }
                    }
                    if (exit == 1) {
                        printf("На месте %d ожидается запятая\n", indicator);
                        break;
                    }
                    for (size_t i = step; i < strlen(inp); i++) {
                        indicator = step;
                        step = i + 1;
                        if ((inp[i] == ')') || (inp[i] == '('))
                            break;
                        if ((inp[i] != ' ') || (inp[i] == ')')
                            || (inp[i] == '(')) {
                            out[index] = inp[i];
                            index++;
                            flag = 1;
                            if (traitor == 0) {
                                traitor = 1;
                                indicator = step;
                            }
                        } else if (flag == 1)
                            break;
                    }
                    chislo(out, r, judge, store);
                    flag = 0;
                    index = 0;
                    traitor = 0;
                    if (judge[0] == '0') {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    if (judge[0] == '2') {
                        printf("Радиус не может быть меньше нуля, ошибка на месте %d \n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for (size_t i = step - 1; i < strlen(inp); i++) {
                        if (inp[i] != ' ') {
                            step = i + 1;
                            if (inp[i] == '(') {
                                printf("Введена неправильная скобка\n");
                                break;
                            }
                            if (inp[i] == ')') {
                                for (size_t i = step + 1; i < strlen(inp); i++) {
                                    if (inp[i] != ' ')
                                        printf("в конце строки ненужные "
                                               "символы\n");
                                }
                                break;
                            } else {
                                printf("ожидается скобка\n");
                                break;
                            }
                        }
                    }
                } else
                    printf("На месте %d ожидается скобка\n", indicator);
                break;
            }
        }
    } else 
        printf("Неверно задана фигура, на месте %d ожидается название фигуры\n",
               indicator + 1);
}


void chislo(char* out, char* mass, char* judge, struct storage *store)
{
    int point = 0;
    int sum = 0;
    size_t a = 0;
    
    double number = 0;
    //printf("----%s----\n", out);

    for (size_t i = 0; i < strlen(out); i++) {
        if (out[i] == '.')
            point++;
    }

    if ((point > 1) && (sum == 0)) {
        printf("введите правильно число - слишком много точек\n");
        sum++;
    }
    if (out[0] == '.')
        sum++;
    if (out[0] == '-')
    {
        if (out[1] == '.')
            sum++;
        else    
            a = 1;
    }
    if (isdigit(out[strlen(out) - 1]) == 0)
        sum++;
    if (out[strlen(out) - 1] == ' ')
        sum--;
    if (sum == 0)
    {
        for (size_t i = a; i < strlen(out)-1; i++)
        {
            if(isdigit(out[i]) == 0 && isdigit(out[i]) == '.')
                sum++;
        }
    }

    if (sum == 0) {
            judge[0] = '1';
        
            number = atof(out);

            if (store->sum == 0)
                store->x = number;

            if (store->sum == 1)
                store->y = number;

            if (store->sum == 2)
            {
                if(number < 0)
                    store->sum++;
                else    
                    store->r = number;
            }            
            store->sum++;
            
            if (store->sum != 4)
            {
                for (size_t i = 0; i < strlen(mass); i++) {
                printf("%c", mass[i]);
                }
                for (size_t i = 0; i < strlen(out); i++) {
                    if (out[i] == ' ')
                        break;
                    else
                        printf("%c", out[i]);
                }
                printf("\n");
            }  
            if (store->sum == 4)
                judge[0] = '2';
        }
    for (size_t i = 0; i < strlen(out); i++) {
        out[i] = ' ';
    }
}


void intersection(struct storage *first, struct storage *second)
{
    double sum_r;
    double sum_xy;
    if ((first->sum == 3) && (second->sum == 3))
    {
        sum_r = first->r + second->r;
        sum_xy = sqrt((first->x + second->x) * (first->x + second->x) + (first->y + second->y) * (first->y + second->y));

        if ((first->r == second->r) && (first->x == second->x) && (first->y == second->y))
            printf("Окружности совпадают\n");
        else if (sum_r < sum_xy)
            printf("Окружности не пересекаются\n");
        else if (sum_r == sum_xy)
            printf("Окружности касаются внешним образом\n");
        else if((first->r != second->r) && (first->x == second->x) && (first->y == second->y))
            printf("Окружности не пересекаются\n");    
        else if((sum_r > sum_xy) && ((first->r <= sum_xy) || (second->r <= sum_xy)))
            printf("Окружности пересекаются\n");
        else if((first->r) == (second->r) + sum_xy)
        {
            printf("Окружности касаются внутренним образом\n");
        }
        else
            printf("Окружности пересекаются\n");    
    }
}

void perimeter_and_area(struct storage *first, struct storage *second)
{
    if ((first->sum == 3) && (second->sum == 3))
    {
        printf("\n");
        printf("Периметр первой окружности равен %f\n", 2*3.14*first->r);
        printf("Площадь первой окружности равена %f\n", 3.14*first->r*first->r);

        printf("\n");
        printf("Периметр второй окружности равен %f\n", 2*3.14*second->r);
        printf("Площадь второй окружности равена %f\n", 3.14*second->r*second->r);
    }
}
