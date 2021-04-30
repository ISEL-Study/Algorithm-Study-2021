#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 0;
int map[15] = {0,};

bool check(int cnt, int value) {
	for (int i = 0; i < cnt; i++) {
    
    // 퀸이 같은 행에 있거나, 대각선에 있을 때 (대각선 판별법 : (X, Y), (A, B)일 때 |X - A| == |Y - B|)
		if (map[i] == value || cnt - i ==  abs(map[i] - value))
			return false;
	}

	return true;
}

/*
* N*N 배열을 만들 필요 없음 (퀸이므로 한 열에 하나씩만 존재할 것
*
* 따라서 대각선과 행에서 조건 검사만 해주면 됨
*/
void DFS(int cnt)
{
	if (cnt == n) {
		answer++;
		return;
	}
  
  // 일단 퀸을 배치하고, 배치한 상태가 조건에 맞으면 재귀함수 호출
	for (int i = 0; i < n; i++)
	{
		map[cnt] = i;

		if (check(cnt, i))
			DFS(cnt + 1);
	}
}


int main() {
	cin >> n;
	DFS(0);

	cout << answer << endl;
}
