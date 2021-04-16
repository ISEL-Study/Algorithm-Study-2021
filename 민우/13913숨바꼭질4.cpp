#include <iostream>
#include <vector>
#include <queue>

int n, k;

using namespace std;


void BFS() {
	queue<pair<int, string>> q;
	int cnt = 0;
	int visit[100001] = {0,};

  /*
  * pair에 vector를 넣어도 되겠지만,
  * vector 복사하는데 시간이 너무 많이 들음 (copy(target.begin(), target.end(), dist.begin()))
  */
	string t = to_string(n);

  
  /*
  * 큐에 pair로 넣어 지나간 위치를 기록한다
  */
	q.push(pair(n, t));

	int sz = q.size();
	int tmp = 0;

	while(q.size() > 0)
	{
		int cur = q.front().first;
		string cur_tree = q.front().second;
		q.pop();

		if (cur == k) {
			cout << cnt << endl;
			cout << cur_tree << endl;
			return;
		}

		if (visit[cur] == 0) {
			if (cur - 1 >= 0 && visit[cur - 1] == 0) {
				string a = cur_tree + " " + to_string(cur-1);

				q.push(pair(cur - 1, a));
			}

			if (cur < k && cur + 1 <= 100000 && visit[cur + 1] == 0) {
				string a = cur_tree + " " + to_string(cur+1);

				q.push(pair(cur + 1, a));
			}

			if (cur < k && cur * 2 <= 100000 && visit[cur * 2] == 0) {
				string a = cur_tree + " " + to_string(cur*2);

				q.push(pair(cur * 2, a));
			}

			visit[cur] = 1;
			
		}

		tmp++;

		if (sz == tmp) {
				sz = q.size();
				tmp = 0;
				cnt++;
		}
	}

}


int main() {
	cin >> n >> k;

  /*
  * n과 k가 같을 경우 걸린 시간은 0이지만,
  * 처음 위치는 
  */
  
	if (n == k) {
		cout << 0 << endl << n << endl;
		return 0;
	}

  /*
  *  n이 k보다 클 경우, 1씩 감소하는 경우밖에 없음
  /
	else if (n > k) {
		cout << n - k << endl;
		 for (int i = n; i >= k; i--)
		 		cout << i << " ";
			cout << endl;
	}

	else
		BFS();
}
