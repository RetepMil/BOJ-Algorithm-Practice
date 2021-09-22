#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	long long cnt = 0;
	string nm;
	queue<int> names[21];

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nm;
		int length = nm.length();

		while (!names[length].empty() && i - names[length].front() > K)
			names[length].pop();
		cnt += names[length].size();

		names[length].push(i);
	}

	cout << cnt;
}