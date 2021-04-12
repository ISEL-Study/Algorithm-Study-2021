#include <iostream>
#include <vector>
#include <queue>

#define INF 99999

using namespace std;

int n, m;
int visit[101][101] = {0,};

void BFS(vector<vector<int>> map, vector<vector<int>> cost)
{
	queue<pair<int, int>> q;

	q.push(pair(0, 0));

	while(q.size() > 0)
	{
		pair<int, int> p = q.front();
		q.pop();

		if (visit[p.first][p.second] == 0) {
			//cout << p.first << ", " << p.second << endl;
			if (p.first < n - 1 && map[p.first+1][p.second] == 1) {
				cost[p.first+1][p.second] = min(cost[p.first][p.second] + 1, cost[p.first+1][p.second]);

				q.push(pair(p.first+1, p.second));
			}

			if (p.first > 0 && map[p.first-1][p.second] == 1) {
				cost[p.first-1][p.second] = min(cost[p.first][p.second] + 1, cost[p.first-1][p.second]);

				q.push(pair(p.first-1, p.second));
			}

			if (p.second < m - 1 && map[p.first][p.second+1] == 1) {
				cost[p.first][p.second+1] = min(cost[p.first][p.second] + 1, cost[p.first][p.second+1]);

				q.push(pair(p.first, p.second+1));
			}

			if (p.second > 0 && map[p.first][p.second-1] == 1) {
				cost[p.first][p.second-1] = min(cost[p.first][p.second] + 1, cost[p.first][p.second-1]);

				q.push(pair(p.first, p.second-1));
			}

			visit[p.first][p.second] = 1;
		}

	}

	cout << cost[n-1][m-1] << endl;
}


int main() {
	cin >> n >> m;
	string tmp;

	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<int>> cost(n, vector<int>(m, INF));
	cost[0][0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		for (int j = 0; j < m; j++)
		{
			map[i][j] = tmp[j] - '0';
		}
	}

	BFS(map, cost);
}
