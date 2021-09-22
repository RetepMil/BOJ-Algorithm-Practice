#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int T;
int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		int foo, bar;
		while (M--) cin >> foo >> bar;

		cout << N - 1 << endl;
	}

	return 0;
}