#include <stdio.h>

int main ()
{
	char c;
	int parity = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == '"') {
			if (parity % 2)
				printf("''");
			else
				printf("``");
			parity++;
			continue;
		}
		putchar(c);
	}

	return 0;
}
