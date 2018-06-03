#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	int counter = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'f') {
			counter += 1;
		}
		if (counter == 2) {
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << counter - 2 << std::endl;
	return 0;
}
