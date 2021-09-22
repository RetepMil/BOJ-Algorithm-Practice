#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	multiset<int, less<int>> pq;
	int T, N;

	cin >> T;

	while (T--) {
		pq.clear();
		cin >> N;
		while (N--) {
			int num;
			char str;
			cin >> str >> num;

			if (str == 'I') {
				pq.insert(num);
			}
			else {
				if (!pq.empty()) {
					switch (num) {
					case 1:
						pq.erase(--pq.end());
						break;
					case -1:
						pq.erase(pq.begin());
						break;
					default:
						break;
					}
				}
			}
		}
		if (pq.empty())
			cout << "EMPTY" << "\n";
		else
			cout << *(--pq.end())  << " " << *pq.begin() << "\n";
	}

	return 0;
}