#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> str(3);
	std::cin >> str[0] >> str[1] >> str[2];
	std::sort(str.begin(), str.end());
	std::cout << str[0];
	return 0;
}
