#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma once

struct storage{
	double x;
        double y;
        double r;
        int sum;
};

void chislo(char* out, char* mass, char* judge, struct storage *store);
void separator(
        char* inp,
        char* sample,
        char* out,
        char* x,
        char* y,
        char* r,
        char* judge,
        struct storage *store);