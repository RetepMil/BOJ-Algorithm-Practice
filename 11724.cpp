#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M;
int cnt = 0;
int nextnode;
int graph[MAX][MAX];
bool visited[MAX] = { false };

bool isDone() {
	for (int i = 1; i <= N; i++)	{
		if (!visited[i]) {
			nextnode = i;
			return false;
		}
	}

	return true;
}

void dfs(int a) {
	visited[a] = true;
	for (int i = 1; i <= N; i++) {
		if (graph[a][i] > 0 && !visited[i])
			dfs(i);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	while (!isDone()) {
		cnt++;
		dfs(nextnode);
	}

	cout << cnt << "\n";

	return 0;
}