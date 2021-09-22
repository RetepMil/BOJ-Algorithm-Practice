#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int ptr = 1;
	stack<int> stq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (ptr == num)
			ptr++;
		else {
			while (!stq.empty() && stq.top() == ptr) {
				stq.pop();
				ptr++;
			}
			stq.push(num);
		}
	}

	while (stq.size() > 0) {
		if (stq.top() == ptr) {
			ptr++;
			stq.pop();
		}
		else {
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";
	return 0;
}