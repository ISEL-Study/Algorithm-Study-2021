#include <iostream>
#include <vector>

#define min(a, b) a > b ? b : a

using namespace std;

int n;

vector<int> p(1001, 0);
vector<int> dp(1001, 20000000);


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}

	dp[1] = p[1];


	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			int tmp = dp[j] + p[i-j];

			dp[i] = min(dp[i], tmp);
		}

		dp[i] = min(dp[i], p[i]);
	}

	printf("%d\n", dp[n]);
}
