#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[11];
int operations[4]
int N, S;

void dfs(int index, int sum) {
	if (index == N)
		return;
	if (sum + arr[index] == S)
		cnt++;

	dfs(index + 1, sum);
	dfs(index + 1, sum + arr[index]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	dfs(0, 0);

	return 0;
}