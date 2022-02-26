#include <stdio.h>
#include <string.h>
#include <ctype.h>


void chislo(char* out, char* mass, char* judge)
{
    int point=0;
    int sum=0;

    for(int i=0; i<strlen(out); i++)
    {
        if(out[i]=='.') point++;
    }    

    if((point>1) && (sum==0))
    {
        printf("введите правильно число - слишком много точек");
        sum++;
    }
    if((isdigit(out[0])==0) && (sum==0))
    {
        sum++;
    }
    if((isdigit(out[strlen(out)-1])==0) && (sum==0))
    {
        sum++;
    }
    else
    {   
        if(sum == 0)
        {
            judge[0] = '1';
            for(int i=0; i<strlen(mass); i++)
            {
                printf("%c", mass[i]);
            }
            //printf("Координата X равна: ");
            for(int i=0; i<strlen(out); i++)
            {
                if(out[i]==' ') break;
                else printf("%c", out[i]);
            }
        }    
    }
    printf("\n");
    for(int i=0; i<strlen(out); i++)
    {
        out[i] = ' ';
    } 
}



void separator(char* inp, char* sample,char* out, char* x, char* y, char* r, char* judge)
{
    int step=0;
    int elem=0;//nen
    int flag = 0;
    int index=0;
    int indicator=0;
    int traitor=0;
    int exit=0;
    
    for(int i=0; i<strlen(inp); i++)
    {
        if(inp[i] != ' ') break;
        else step=i+1;
    }
    //пробелы
    indicator = step;
    for(int i=step; i<strlen(inp); i++)
    {
        step=i;
        if((inp[i] ==' ') || (inp[i] =='(') || (inp[i] =='(')) break;
        else 
        {
            flag++;
            if(sample[elem]== tolower(inp[i])) elem++;
        }
    }

    if(elem == 6 && flag == 6)
    {
        printf("Ваша фигура окружность\n");
        for(int i=step; i<strlen(inp); i++)
        {
            step=i+1;
            indicator = step;
            if(inp[i]!=' ')
            {
                if(inp[i] ==')') 
                {
                    printf(" вы препутали скобку\n");
                    break;
                }

                if(inp[i] =='(') 
                {
                    for(int i=step; i<strlen(inp); i++)
                    {
                        step=i+1;
                        if(inp[i]!=' ')
                        {
                            out[index]=inp[i];
                            index++;
                            flag=1;
                            if(traitor == 0)
                            {
                                traitor=1;
                                indicator = step;
                            }
                        }
                        else
                        { 
                            if(flag==1)
                            {
                                break;
                            }
                        }
                    }
                    chislo(out, x, judge);
                    flag=0;
                    index=0;
                    traitor=0;
                    if(judge[0] == '0') 
                    {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for(int i=step; i<strlen(inp); i++)
                    {
                        step=i+1;
                        if(inp[i]==',') break;
                        if(inp[i]!=' ')
                        {
                            out[index]=inp[i];
                            index++;
                            flag=1;
                            if(traitor == 0)
                            {
                                traitor=1;
                                indicator = step;
                            }
                        }
                        else
                        { 
                            if(flag==1)
                            {
                                break;
                            }
                        }
                    }
                    chislo(out, y, judge);
                    flag=0;
                    index=0;
                    traitor=0;
                    if(judge[0] == '0') 
                    {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for(int i=step-1; i<strlen(inp); i++)
                    {
                        step = i+1;
                        if(inp[i]!=' ')
                        {
                            if(inp[i]!=',') 
                            {
                                indicator = step;
                                exit=1;
                                break;
                            }
                        }
                    }
                    if(exit==1)
                    {
                        printf("На месте %d ожидается запятая\n", indicator);
                        break;
                    }
                    for(int i=step; i<strlen(inp); i++)
                    {
                        indicator = step;
                        step=i+1;
                        if((inp[i]==')') || (inp[i]=='(')) break;
                        if((inp[i]!=' ') ||(inp[i]==')') || (inp[i]=='('))
                        {
                            out[index]=inp[i];
                            index++;
                            flag=1;
                            if(traitor == 0)
                            {
                                traitor=1;
                                indicator = step;
                            }
                        }
                        else
                        { 
                            if(flag==1)
                            {
                                break;
                            }
                        }
                    }
                    chislo(out, r, judge);
                    flag=0;
                    index=0;
                    traitor=0;
                    if(judge[0] == '0') 
                    {
                        printf("На месте %d ожидается число\n", indicator);
                        break;
                    }
                    judge[0] = '0';

                    for(int i=step-1; i<strlen(inp); i++)
                    {
                        if(inp[i] != ' ')
                        {
                            step = i+1;
                            if(inp[i] == '(') 
                            {
                                printf("Введена неправильная скобка\n");
                                break;
                            } 
                            if(inp[i] == ')')
                            {
                                for(int i=step+1; i<strlen(inp); i++)
                                {
                                    if(inp[i]!=' ') printf("в конце строки ненужные символы\n");
                                }
                                break;
                            }
                            else 
                            {
                                printf("ожидается скобка\n");
                                break;
                            }
                        }
                    }
                }
                else printf("На месте %d ожидается скобка\n", indicator);
                break;
            }
        }
    } 
    else printf("Неверно задана фигура, на месте %d ожидается название фигуры\n", indicator+1);
}
int main()
{
    char inp[40];
    char out[40];
    char sample[]="circle";
    char x[]="Координата X равна ";
    char y[]="Координата Y равна ";
    char r[]="Радиус равен ";
    char judge[2]="0";
    printf("Введите параметры окружности по образцу:\n circle(x y, r)\n");
    fgets(inp, 40, stdin);
    separator(inp, sample, out, x, y, r, judge);
}