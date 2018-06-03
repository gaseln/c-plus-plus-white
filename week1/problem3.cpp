#include <iostream>
#include <cmath>

int main() {
	double a, b, c;
	std::cin >> a >> b >> c;
	double discr = b*b - 4 * a * c;
	if (a != 0) {
		if (discr > 0) {
			std::cout << (-b + sqrt(discr)) / (2 * a) << " " << (-b - sqrt(discr)) / (2 * a) << std::endl;
		}
		else if (discr == 0) {
			std::cout << -b / (2 * a) << std::endl;
		}
	}
	else if (b!=0 && c!=0) {
		std::cout << -c / b << std::endl;
	}
	else if (c == 0) {
		std::cout << 0 << std::endl;
	}
	return 0;
}
