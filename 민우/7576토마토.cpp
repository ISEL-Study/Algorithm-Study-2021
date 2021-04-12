#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n, m;
int visit[1001][1001] = {0,};

int BFS(vector<vector<int>> box) {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1)
				q.push(pair(i, j));
		}
	}

	int sz = q.size();
	int idx = 0;
	int day = 0;

	while(q.size() > 0)
	{
		pair<int, int> t = q.front();
		q.pop();

		if (visit[t.first][t.second] == 0) {
			if (t.first < n - 1 && box[t.first+1][t.second] == 0) {
				box[t.first+1][t.second] = 1;
				q.push(pair(t.first+1, t.second));
			}

			if (t.first > 0 && box[t.first-1][t.second] == 0) {
				box[t.first-1][t.second] = 1;
				q.push(pair(t.first-1, t.second));
			}

			if (t.second < m - 1 && box[t.first][t.second+1] == 0) {
				box[t.first][t.second+1] = 1;
				q.push(pair(t.first, t.second+1));
			}

			if (t.second > 0 && box[t.first][t.second-1] == 0) {
				box[t.first][t.second-1] = 1;
				q.push(pair(t.first, t.second-1));
			}

			idx++;
		}

		if (sz == idx) {
			idx = 0;
			day++;
			sz = q.size();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0)
				return -1;
		}
	}

	return day - 1;
}


int main() {
	cin >> m >> n;

	vector<vector<int>> box(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> box[i][j];
	}

	cout << BFS(box) << endl;
}
