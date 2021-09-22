#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))
			return (a > b) ? true : false;
		else 
			return (abs(a) > abs(b));
	}
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	priority_queue<int, vector<int>, compare> pq;
	int N;
	int num;

	cin >> N;

	while (N--) {
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}

	return 0;
}