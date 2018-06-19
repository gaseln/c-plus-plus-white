#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
	int N, i;
	std::cin >> N;
	std::vector<std::string> vec(N);
	std::string str;
	for (i = 0; i < N; ++i) {
		std::cin >> str;
		vec[i] = str;
	}
	sort(begin(vec), end(vec), [](std::string a, std::string b) {
		std::string c = a, d = b;
		std::transform(a.begin(), a.end(), c.begin(), ::tolower);
		std::transform(b.begin(), b.end(), d.begin(), ::tolower);
		return  c < d;});
	for (i = 0; i < N; ++i) {
		std::cout << vec[i] << " ";
	}
	return 0;
}
