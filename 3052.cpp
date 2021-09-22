#include <iostream>

int main() {
	int n, cnt = 0;
	int map[42] = {0};

	for (int i = 0; i < 10; i++) {
		std::cin >> n;
		map[n % 42] = 1;
	}

	for (int j = 0; j < 42; j++) {
		if (map[j] == 1)
			cnt++;
	}

	std::cout << cnt << std::endl;

	return 0;
}