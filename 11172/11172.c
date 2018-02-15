#include <stdio.h>

int main ()
{
	int N;
	scanf("%d", &N);
	
	int a, b, i;

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);

		if (a < b) putchar('<');
		else if (a > b) putchar('>');
		else putchar ('=');
		putchar('\n');
	}

	return 0;
}
