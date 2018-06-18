#include <iostream>
#include <set>
#include <string>

int main() {
	std::set<std::string> my_strings;
	int N, i;
	std::string str;
	std::cin >> N;
	for (i = 0; i < N; ++i) {
		std::cin >> str;
		my_strings.insert(str);
	}
	std::cout << my_strings.size() << std::endl;
	return 0;
}