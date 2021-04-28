#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	vector<int> s(n);
	vector<int> result;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	if (n == 1) {
		if (s[0] == 1)
			cout << 2 << endl;
		else
			cout << 1 << endl;
		return 0;
	}


	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
      /*
      * 수열을 비트마스크로 생성
      * i와 j가 0이 아니면 sum에 부분수열 구함
      */
			if (i & (1 << j))
				sum += s[j];
		}

		result.push_back(sum);
	}
  
  //만든 부분수열을 sort하여 빈 자리가 있는지 탐색
	sort(result.begin(), result.end());

	if (result[0] != 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < result.size(); i++) {
		int cur = result[i];
		int next = result[i+1];
		if (next - cur != 0 && next - cur != 1) {
			cout << cur + 1 << endl;
			break;
		}
	}
}
