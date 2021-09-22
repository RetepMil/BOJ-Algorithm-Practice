#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> dots;
bool visited[30][30];
char map[30][30];
int N, M;
int dotNum;
int ans;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void roll(int x, int y, int dir, int moveCellCnt, int rollCnt) {
	if (dotNum == moveCellCnt) {
		if (ans > rollCnt) ans = rollCnt;
		return;
	}

	int newx = x + dx[dir];
	int newy = y + dy[dir];

	if (!(newx < 0 || newy < 0 || newx >= N || newy >= M) &&
		!visited[newx][newy] && map[newx][newy] == '.') {
		visited[newx][newy] = true;
		roll(newx, newy, dir, moveCellCnt + 1, rollCnt);
		visited[newx][newy] = false;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;
			newx = x + dx[i];
			newy = y + dy[i];

			if (!(newx < 0 || newy < 0 || newx >= N || newy >= M) &&
				!visited[newx][newy] && map[newx][newy] == '.') {
				visited[newx][newy] = true;
				roll(newx, newy, i, moveCellCnt + 1, rollCnt + 1);
				visited[newx][newy] = false;
			}
		}
	}
}

void solve() {
	if (dotNum == 1) {
		ans = 0;
		return;
	}
	for (pair<int, int> it : dots) {
		int x = it.first;
		int y = it.second;

		for (int i = 0; i < 4; i++) {
			visited[x][y] = true;
			roll(x, y, i, 1, 1);
			visited[x][y] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1; 
	while (cin >> N >> M) {
		dotNum = 0;
		ans = 1000000;
		dots.clear();

		for (int i = 0; i < N; i++) {
			cin >> map[i];
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
				if (map[i][j] == '.') {
					dotNum++;
					dots.push_back(make_pair(i, j));
				}
			}
		}
		solve();
		cout << "Case " << T++ << ": " << (ans == 1000000 ? -1 : ans) << "\n";
	}

	return 0;
}