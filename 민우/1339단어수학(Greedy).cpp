#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

/*
* 백트래킹 문제지만 그리디로도 풀 수 있음
* 문자당 앞의 계수가 큰 순서대로 9부터 집어넣으면 가장 큰 수가 되는 것을 이용
*/

int main() {
	int answer = 0;
	cin >> n;
	vector<int> words_value(27, 0);
	vector<string> words;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		words.push_back(tmp);

		for (int i = 0; i < tmp.length(); i++)
		{
			words_value[tmp[i] - 'A'] += pow(10, tmp.length() - (i + 1));
		}
	}

	sort(words_value.rbegin(), words_value.rend());

	for(int i = 0; words_value[i] != 0; i++) {
		answer += (9 - i) * words_value[i];
	}

	cout << answer << endl;
}
