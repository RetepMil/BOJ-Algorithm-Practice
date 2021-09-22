#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int cnt = 0;
vector<int> trees[101];
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < trees[v].size(); i++) {
		if (!visited[trees[v][i]]) {
			cnt++;
			dfs(trees[v][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	visited.resize(N);

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		trees[n1].push_back(n2);
		trees[n2].push_back(n1);
	}

	dfs(1);

	cout << cnt << "\n";

	return 0;
}