#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> graph;
vector<int> visit;


/*
* 그래프 돌면서 색깔 칠함 (1 or 2)
* 이분 그래프는 같은 색끼리 인접하면 안 됨
* 완전 탐색 + DFS
*/
void DFS(int cnt, int color)
{
	visit[cnt] = color;

	for (int i = 0; i < graph[cnt].size(); i++) {
		if (visit[graph[cnt][i]] == 0)
			DFS(graph[cnt][i], 3 - color);
	}
}


/*
* visit에 색깔을 칠했으므로, 인접한 정점의 색이 같은지 확인
*
*/

bool check()
{
	for (int i = 1; i < visit.size(); i++)
	{
		for (int j = 0; j < graph[i].size(); j++) {
			if (visit[i] == visit[graph[i][j]])
				return false;
		}
	}

	return true;
}


int main() {
	int t;

	cin >> t;

	while(t--)
	{
		int v, e, v1, v2;
		cin >> v >> e;

		graph.assign(v+1, vector<int>(0, 0));
		visit.assign(v+1, 0);

		for (int i = 0; i < e; i++)
		{
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		for (int i = 1; i <= v; i++) {
			if (visit[i] == 0)
				DFS(i, 1);
		}

		bool ist = check();

		// for (int i = 1; i <= v; i++)
		// 	cout << visit[i] << " ";


		if (ist)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
