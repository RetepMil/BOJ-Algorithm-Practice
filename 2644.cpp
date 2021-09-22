#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int N, A, B, M;
int graph[MAX][MAX] = { 0, };
bool visited[MAX] = { false, };
int depth[MAX] = { 0, };
queue<int> q;

int bfs(int start) {
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[start][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				depth[i] = depth[start] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> A >> B >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	bfs(A);

	if (depth[B] == 0) {
		cout << -1 << endl;
	}
	else {
		cout << depth[B] << endl;
	}

	return 0;
}