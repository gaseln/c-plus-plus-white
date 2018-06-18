#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

std::map<std::set<std::string>, int> accordance;
std::vector<std::string> out;

int main() {
	int Q, i, j, n, counter = 1;
	std::set<std::string> new_route;
	std::string str;
	std::cin >> Q;
	for (i = 0; i < Q; ++i) {
		std::cin >> n;
		new_route.erase(new_route.begin(), new_route.end());
		for (j = 0; j < n; ++j) {
			std::cin >> str;
			new_route.insert(str);
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