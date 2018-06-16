#include <iostream>
#include <map>
#include <vector>
#include <string>

std::map<std::vector<std::string>, int> accordance;
std::vector<std::string> out;

int main() {
	int Q, i, j, n, counter = 1;
	std::vector<std::string> new_route;
	std::cin >> Q;
	for (i = 0; i < Q; ++i) {
		std::cin >> n;
		new_route.resize(n);
		for (j = 0; j < n; ++j) {
			std::cin >> new_route[j];
		}
		if (accordance.count(new_route) == 0) {
			accordance[new_route] = counter;
			out.push_back("New bus " + std::to_string(counter));
			++counter;
		}
		else {
			out.push_back("Already exists for " + std::to_string(accordance[new_route]));
		}
	}
	for (i = 0; i < out.size(); ++i) {
		std::cout << out[i] << std::endl;
	}
}
