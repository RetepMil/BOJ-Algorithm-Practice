#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int graph[100][100] = { 0 };
bool visited[100][100];
int depth[100][100] = { 0 };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };


void bfs() {
	visited[0][0] = true;
	depth[0][0]++;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && graph[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				depth[nx][ny] = depth[xx][yy] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	bfs();
	cout << depth[N - 1][M - 1];

	return 0;
}