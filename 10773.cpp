#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	int num;
	int sum = 0;
	stack<int> stq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			stq.pop();
		} else {
			stq.push(num);
		}
	}

	for (int j = 0; !stq.empty(); j++) {
		sum += stq.top();
		stq.pop();
	}

	cout << sum << endl;
}