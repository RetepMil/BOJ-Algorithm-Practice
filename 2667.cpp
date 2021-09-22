#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25

int N, cnt;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;

		if (graph[nx][ny] == 1 && !visited[nx][ny])
			dfs(nx, ny);
	}

	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	vector<int> complex;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				complex.push_back(cnt);
			}
		}
	}

	sort(complex.begin(), complex.end());
	int size = complex.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << complex[i] << '\n';

	return 0;
}