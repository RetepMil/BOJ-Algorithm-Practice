#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int T;
int sudoku[9][9];
pair<int, int> missing[5];
bool stop = false;

void printGrid() {
	for (auto& arr : sudoku) {
		for (int& i : arr)
			cout << i;
		cout << "\n";
	}
	cout << "\n";
}

bool check(int a, int b) {
	bool checkNumX[10] = { false, };
	bool checkNumY[10] = { false, };
	bool checkNum3x3[10] = { false, };

	for (int i = 0; i < 9; i++) {
		int num = sudoku[a][i];
		if (num == 0) continue;
		if (checkNumX[num]) return false;
		else checkNumX[num] = true;
	}

	for (int i = 0; i < 9; i++) {
		int num = sudoku[i][b];
		if (num == 0) continue;
		if (checkNumY[num]) return false;
		else checkNumY[num] = true;
	}

	int x = a / 3; int y = b / 3;
	for (int i = x * 3; i / 3 < x + 1; i++)
		for (int j = y * 3; j / 3 < y + 1; j++) {
			int num = sudoku[i][j];
			if (num == 0) continue;
			if (checkNum3x3[num]) return false;
			else checkNum3x3[num] = true;
		}

	return true;
}

void brute(int level) {
	int a = missing[level - 1].first; int b = missing[level - 1].second;
	for (int i = 1; i < 10; i++) {
		sudoku[a][b] = i;
		if (check(a, b)) {
			if (level == 5) stop = true;
			else brute(level + 1);
		}
		if (stop) return;
	}
	if (level == 1) return;
	sudoku[a][b] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		int cnt = 0;
		for (int i = 0; i < 9; i++)	{
			int line;
			cin >> line;
			for (int j = 8; j > -1; j--) {
				int num = line % 10;
				if (num == 0) missing[cnt++] = make_pair(i, j);
				sudoku[i][j] = num;
				line /= 10;
			}
		}
		brute(1);
		if (stop) printGrid();
		else cout << "Could not complete this grid.\n\n";
		stop = false;
	}
;
	return 0;
}