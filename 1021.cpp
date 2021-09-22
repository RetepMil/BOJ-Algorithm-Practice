#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	int cnt = 0;
	deque<int> dq;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int pos;
		int key;
		cin >> key;

		for (int j = 0; j < dq.size(); j++) {
			if (key == dq[j]) {
				pos = j;
				break;
			}
		}

		if (pos < dq.size() - pos) {
			while (1) {
				if (dq.front() == key) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (1) {
				if (dq.front() == key) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	cout << cnt;
	return 0;
}