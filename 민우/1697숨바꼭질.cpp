#include <iostream>
#include <vector>
#include <queue>

int n, k;

using namespace std;


int BFS() {
	queue<int> q;
	int cnt = 0;
	int visit[100001] = {0,};

	q.push(n);

	int sz = q.size();
	int tmp = 0;

	while(q.size() > 0)
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
			return cnt;

		if (visit[cur] == 0) {
			//cout << cur << " and cnt = " << cnt << endl;
			if (cur - 1 >= 0 && visit[cur - 1] == 0 )
				q.push(cur - 1);

			if (cur + 1 <= 100000 && visit[cur + 1] == 0)
				q.push(cur + 1);

			if (cur * 2 <= 100000 && visit[cur * 2] == 0)
				q.push(cur * 2);

			visit[cur] = 1;
			
		}

		tmp++;

		if (sz == tmp) {
				sz = q.size();
				tmp = 0;
				cnt++;
		}
	}

	return cnt;
}


int main() {
	cin >> n >> k;

	if (n == k) {
		cout << 0 << endl;
		return 0;
	}

	cout << BFS() << endl;
}
