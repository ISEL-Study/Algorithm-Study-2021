#include <vector>
#include <iostream>

using namespace std;

int n, m, r;

vector<vector<int>> arr;


void cal1() {
	int l = arr.size();
	for (int i = 0; i < l / 2; i++) {
		swap(arr[i], arr[(l - 1) - i]);
	}
}


void cal2() {
	int a = arr.size();
	int b = arr[0].size();

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b / 2; j++)
			swap(arr[i][j], arr[i][(b - 1) - j]);
	}
}


void cal3() {
	int a = arr.size();
	int b = arr[0].size();
	vector<vector<int>> tmp(b, vector<int>(a));

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++)
			tmp[j][i] = arr[i][j];
	}

	arr.assign(b, vector<int>(a, 0));
	copy(tmp.begin(), tmp.end(), arr.begin());

	cal2();
}


void cal4() {
	int a = arr.size();
	int b = arr[0].size();
	vector<vector<int>> tmp(b, vector<int>(a));

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++)
			tmp[j][i] = arr[i][j];
	}

	arr.assign(b, vector<int>(a, 0));
	copy(tmp.begin(), tmp.end(), arr.begin());

	cal1();
}



void cal5() {
	int a = arr.size();
	int b = arr[0].size();

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b / 2; j++)
			swap(arr[i][j], arr[i][j + (b / 2)]);
	}

	for (int i = 0; i < a / 2; i++) {
		for (int j = 0; j < b / 2; j++)
			swap(arr[i][j], arr[i + (a / 2)][j + (b / 2)]);
	}
}


void cal6() {
	int a = arr.size();
	int b = arr[0].size();

	for (int i = 0; i < a / 2; i++) {
		for (int j = 0; j < b; j++)
			swap(arr[i][j], arr[i + (a / 2)][j]);
	}

	for (int i = 0; i < a / 2; i++) {
		for (int j = 0; j < b / 2; j++)
			swap(arr[i][j], arr[i + (a / 2)][j + (b / 2)]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;

	arr.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int op;

	while(r--) {
		cin >> op;

		switch(op) {
			case 1: cal1(); break;
			case 2: cal2(); break;
			case 3: cal3(); break;
			case 4: cal4(); break;
			case 5: cal5(); break;
			case 6: cal6(); break;
		}
	}

	int a = arr.size();
	int b = arr[0].size();

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++)
			cout << arr[i][j] << " ";

		cout << endl;
	}
}
