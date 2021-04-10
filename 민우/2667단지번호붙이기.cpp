#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// BFS로 

int visit[26][26] = {0,};
int location[26][26];
int n;


int BFS(int x, int y)
{
	//cout << "x: " << x << ", y: " << y << endl;
	int tmp = 0;
	queue<pair<int, int>> q;

	q.push(pair(x, y));

	while(q.size() > 0)
	{
		pair<int, int> t = q.front();
		q.pop();

		if (visit[t.first][t.second] == 0)
		{
			if (location[t.first+1][t.second] == 1)
				q.push(pair(t.first + 1, t.second));

			if (location[t.first][t.second+1] == 1)
				q.push(pair(t.first, t.second + 1));

			if (location[t.first][t.second-1] == 1)
				q.push(pair(t.first, t.second - 1));

			if (location[t.first-1][t.second] == 1)
				q.push(pair(t.first - 1, t.second));

			tmp++;
			visit[t.first][t.second] = 1;
		}
	}

	return tmp;
}


int main() {
	vector<int> family;
	cin >> n;

	// 지도 완성
	for (int i = 0; i < n; i++) {
		string len;
		cin >> len;

		for (int j = 0; j < n; j++) {
			location[i][j] = len[j] - '0';
		}
	}

 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 이미 방문했을 때
			if (visit[i][j] != 0)
				continue;

			// 집이 있을 때
			if (location[i][j] != 0) {
				int result =  BFS(i, j);
				family.push_back(result);
			}
		}
	}

	cout << family.size() << endl;
	sort(family.begin(), family.end());
	for (int i = 0; i < family.size(); i++)
		cout << family[i] << endl;
}
