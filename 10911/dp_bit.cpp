#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int N, target;
double dist[20][20], memo[1 << 16];

double matching (int bitmask)
{
	if (memo[bitmask] > -0.5)
		return memo[bitmask];
	if (bitmask == target)
		return memo[bitmask] = 0;
	double ans = 2000000000.0;
	int p1, p2;
	for (p1 = 0; p1 < 2 * N; p1++) {
		if (!(bitmask & (1 << p1))) {
//			cout << p1 << " deu break p1" << endl;
			break;
		}
	}
	for (p2 = p1 + 1; p2 < 2 * N; p2++)
		if (!(bitmask & (1 << p2))) {
//			cout << p2 << " deu break p2" << endl;
			//cout << (1 << p1) << " " << (1<<p2) << " " << dist[p1][p2] <<  endl;
			printf("dist[%d][%d]: %.2lf on bitmask %d\n", p1,p2,dist[p1][p2],bitmask);
			ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
			cout << "ans: " << ans << ", on bitmask: " << bitmask << endl;
		}
	
	//printf("bitmask: %d,\tans: %lf\n", bitmask, ans);
	return memo[bitmask] = ans;
}

int main ()
{
	int i, j, caseNo = 1, x[20], y[20];
	// freopen("10911.txt", "r", stdin);

	while (scanf("%d", &N), N) {
		for (i = 0; i < 2 * N; i++)
			scanf("%*s %d %d", &x[i], &y[i]);
		for (i = 0; i < 2 * N; i++)
			for (j = i + 1; j < 2 * N; j++) {
				dist[i][j] = dist[j][i] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
			}
		
		for (i = 0; i < (1 << 16); i++) memo[i] = -1.0;
		target = (1 << (2 * N)) - 1;
		printf("Case %d: %.2lf\n", caseNo++, matching(0));
	}
	return 0;
}

