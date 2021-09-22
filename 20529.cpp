#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T;
vector<string> name;

void work(int N) {
	if (N > 32) {
		cout << 0 << "\n";
		return;
	}

	int result = 999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int temp = 0;
				if (i == j || j == k || k == i) continue;
				for (int a = 0; a < 4; a++) {
					if (name[i][a] != name[j][a]) temp += 1;
					if (name[j][a] != name[k][a]) temp += 1;
					if (name[i][a] != name[k][a]) temp += 1;
				}
				result = min(result, temp);
			}
		}
	}
	cout << result << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		name.clear();

		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			name.push_back(temp);
		}

		work(N);
	}

	return 0;
}