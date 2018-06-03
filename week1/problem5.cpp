#include <iostream>

int main() {
	double N, A, B, X, Y;
	std::cin >> N >> A >> B >> X >> Y;
	if (N > B) {
		std::cout << N * (1 - Y / 100) << std::endl;
		return 0;
	}
	if (N > A) {
		std::cout << N * (1 - X / 100) << std::endl;
		return 0;
	}
	std::cout << N << std::endl;
	return 0;
}
