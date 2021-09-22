#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string S;
int N, M;
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> S;

	for (int i = 1; i < M; i++) {
		int cnt = 0;
		if (S[i - 1] == 'I') {
			while (S[i] == 'O' && S[i + 1] == 'I') {
				i += 2;
				cnt++;
			}
			if (cnt >= N)
				ans += cnt - N + 1;
		}

	}

	cout << ans << endl;

	return 0;
}