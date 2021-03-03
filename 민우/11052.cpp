#include <iostream>

#define max(a, b) a > b ? a : b

using namespace std;

int n;

int p[1001] = {0,};
int dp[1001] = {0,};

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}

	dp[1] = p[1];


	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			int tmp = dp[j] + p[i-j];

			dp[i] = max(dp[i], tmp);
		}

		dp[i] = max(dp[i], p[i]);
	}

	printf("%d\n", dp[n]);
}
