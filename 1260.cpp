#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, V;
int graph[MAX][MAX];
bool visited[MAX] = {false};
queue<int> q;

void dfs(int a) {
	visited[a] = true;
	cout << a << " ";

	for (int i = 1; i <= N; i++) {
		if (graph[a][i] > 0 && !visited[i])
			dfs(i);
	}

	return;
}

void bfs(int a) {
	q.push(a);
	visited[a] = true;
	cout << a << " ";

	while(!q.empty()) {
		a = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (graph[a][i] > 0 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> V;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(V);
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	bfs(V);

	return 0;
}