#include <iostream>
#include <vector>
#include <deque>
#define INF 99999

using namespace std;


int n, m;
vector<vector<int>> v;

int visit[101][101] = {0,};


/*
* 0-1 BFS 알고리즘
*	https://justicehui.github.io/medium-algorithm/2018/08/30/01BFS/ 참고
* 
* edge의 가중치가 0 또는 1인 그래프에서 사용
* 우선순위큐를 사용해도 되나, deque에서 push_front, push_back 와 같이
* 강력한 메소드를 지원해주므로 deque가 편리하다
*/

void zero_one_BFS() {
	vector<vector<int>> graph(n, vector<int>(m, INF));

	graph[0][0] = 0;
	deque<pair<int, int>> deq;

	deq.push_front(pair(0, 0));

	while (deq.size() > 0)
	{
		int x = deq.front().first;
		int y = deq.front().second;

		deq.pop_front();


		/*
		* 가중치가 1일 때 (이 문제에서는 벽이 있을 때)
		*	나중에 pop하기 위해 push_back
		*
		* 가중치가 0이면 push_front를 해줘서 너비 탐색
		* 0인 경로를 먼저 모두 찾아갈 수 있음
		*
		* 1일 때는 벽을 부숴야 하므로 cost를 1 증가
		* 최단 경로에서 벽을 부술 수 있으므로 최솟값 계산
		*/
		if (visit[x][y] == 0) {
		if (y + 1 < m && visit[x][y+1] == 0) {
			if (v[x][y+1] == 1) {
				graph[x][y+1] = min(graph[x][y+1], graph[x][y] + 1);
				deq.push_back(pair(x, y+1));
			}
			else {
				graph[x][y+1] = graph[x][y];
				deq.push_front(pair(x, y+1));
			}
		}

		if (y - 1 >= 0 && visit[x][y-1] == 0) {
			if (v[x][y-1] == 1) {
				graph[x][y-1] = min(graph[x][y-1], graph[x][y] + 1);
				deq.push_back(pair(x, y-1));
			}
			else {
				graph[x][y-1] = graph[x][y];
				deq.push_front(pair(x, y-1));
			}
		}


		if (x + 1 < n && visit[x+1][y] == 0) {
			if (v[x+1][y] == 1) {
				graph[x+1][y] = min(graph[x+1][y], graph[x][y] + 1);
				deq.push_back(pair(x+1, y));
			}
			else {
				graph[x+1][y] = graph[x][y];
				deq.push_front(pair(x+1, y));
			}
		}


		if (x - 1 >= 0 && visit[x-1][y] == 0) {
			if (v[x-1][y] == 1) {
				graph[x-1][y] = min(graph[x-1][y], graph[x][y] + 1);
				deq.push_back(pair(x-1, y));
			}
			else {
				graph[x-1][y] = graph[x][y];
				deq.push_front(pair(x-1, y));
			}
		}

		visit[x][y] = 1;
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	*/
	cout << graph[n-1][m-1] << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;

	v.assign(n, vector<int>(m, 0));

	string tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;

		for (int j = 0; j < m; j++) {
			v[i][j] = tmp[j] - '0';
		}
	}

	zero_one_BFS();
}
