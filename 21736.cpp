#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int N, M;
int a, b;
int cnt = 0;
int map[600][600];
bool visited[600][600];

int dirX[] = { -1, 0, 1, 0 };
int dirY[] = { 0, -1, 0, 1 };

void dfs(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < input.length(); j++) {
			char foo;
			foo = input[j];
			switch (foo) {
				case 'O':
					map[i][j] = 1;
					break;
				case 'X':
					visited[i][j] = true;
					break;
				case 'P':
					map[i][j] = 2;
					break;
				case 'I':
					map[i][j] = 1;
					a = i; b = j;
					break;
				default:
					break;
			}
		}
	}

	dfs(a, b);

	if (cnt == 0) cout << "TT\n";
	else cout << cnt << "\n";

	return 0;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	if (map[x][y] == 2) cnt++;

	for (int i = 0; i < 4; i++) {
		int newX = x + dirX[i];
		int newY = y + dirY[i];

		if (!visited[newX][newY] && newX >= 0 && newX < N && newY >= 0 && newY < M) {
			dfs(newX, newY);
		}
	}
	return;
}