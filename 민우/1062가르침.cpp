#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define DEFAULT 532741  // 문자 a, c, i, n, t 을 비트마스크화 한 수

using namespace std;

int n, k;
int visit[27] = {0,};
int answer = 0;
vector<int> word;
vector<int> findby;

/*
* 비트마스크 + 백트래킹 문제
*/
void DFS(int x, int cnt, int prev) {
	if (cnt == k - 5) {
		int t = 0;
		for (int i = 0; i < word.size(); i++) {
			if ((prev & word[i]) == word[i])
				t++;
		}

		answer = max(answer, t);
		return;
	}

	
  // i = 0으로 놓으면 처음부터 반복해 찾음
  // 순서 상관없이 구하므로 파라미터 x를 받아 같은 조합 반복 x
	for (int i = x; i < findby.size(); i++) {
		int idx = findby[i];
		
		if (n != 0 && visit[idx] == 0) {
			visit[idx] = 1;
			DFS(i + 1, cnt + 1, prev | (1 << idx));
			visit[idx] = 0;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	string tmp;
	int longest = 0;

	if (k - 5 < 0) {
		cout << 0 << endl;
		return 0;
	}

	else if (k == 26) {
		cout << n << endl;
		return 0;
	}


	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		int result = DEFAULT;
    
    
    // 각 문자열을 정수로
		for (int j = 4; j < tmp.length() - 4; j++)
		{
			int t = tmp[j] - 'a';
			result = result | (1 << t);
			
			if (t != 0 && t != 2 && t != 8 && t != 13 && t != 19)
				findby.push_back(t);
		}

		word.push_back(result);
	}


	visit[0] = visit[2] = visit[8] = visit[13] = visit[19] = 1;
	
  // *중복된 문자를 없애야 돌아간다* (같은 문자 여러번 볼 필요 x)
  // 한 번만 unique erase 하므로 부담되지는 않음
	sort(findby.begin(), findby.end());
	findby.erase(unique(findby.begin(), findby.end()), findby.end());

  
  // 탐색해야 할 문자를 걸러냈을 때 이 개수보다 K가 크면 다 배울 수 있으므로 n 리턴
	if (findby.size() <= k - 5) {
		cout << n << endl;
		return 0;
	}

	
	DFS(0, 0, DEFAULT);

	cout << answer << endl;
}
