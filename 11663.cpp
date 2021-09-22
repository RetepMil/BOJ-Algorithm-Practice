#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
long dots[100000];

int binSearch(long x, long y) {
	int lowB = 0, highB = N - 1;

	int l = 0, r = N - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dots[mid] < x)
			l = mid + 1;
		else {
			lowB = mid;
			r = mid - 1;
		}
	}

	l = 0, r = N - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (dots[mid] > y)
			r = mid - 1;
		else {
			highB = mid;
			l = mid + 1;
		}
	}
	return highB - lowB + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> dots[i];
	}
	sort(dots, dots+N);
		
	for (int i = 0; i < M; i++) {
		long start, end;
		cin >> start >> end;
		if (end < dots[0] || start > dots[N - 1]) cout << 0 << "\n";
		else cout << binSearch(start, end) << "\n";
	}

	return 0;
}