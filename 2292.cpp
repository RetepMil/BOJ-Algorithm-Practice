#include <iostream>

int main() {
	int n, cnt = 1;
	std::cin >> n;

	if (n != 1) {
		n -= 1;
		while (1) {
			n -= 6 * cnt++;
			if (n <= 0) {
				std::cout << cnt << std::endl;
				break;
			}
		}
	}
	else
		std::cout << cnt << std::endl;

	return 0;
}