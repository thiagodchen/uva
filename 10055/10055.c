/*
10:07 - 10:45
1 AC - 3 WA - 1 CE

ansi nao aceita // como comentarios
fabs nao funciona com float, por que??
*/


#include <stdio.h>
#include <math.h>

int main ()
{
	float x, y;

	while (scanf("%f %f", &x, &y) != EOF) {
		printf("%.f, %.f, %.f\n", x, y, x-y);
		printf("%.f\n", fabs(x-y));
	}

	return 0;
}
