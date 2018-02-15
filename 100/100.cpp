/* Thiago Dong Chen */

#include <cstdio>
#include <algorithm>
using namespace std;

int main () {

	int i, j;

	while (scanf("%d %d", &i, &j) != EOF) {
		printf("%d %d", i, j);
		int max = 0;
		if (i > j) {
			swap(i, j);
		}
		for (int k = i; k <= j; k++) {
			int n = k;
			int actual = 1;
			while (n != 1) {
				if (n % 2)
					n = n * 3 + 1;
				else
					n /= 2;
				actual++;
			}
			if (actual > max)
				max = actual;
		}
		printf(" %d\n", max);
	}
	return 0;
}
