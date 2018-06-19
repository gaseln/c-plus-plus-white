#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int main() {
	int N, i;
	std::cin >> N;
	std::vector<int> vec(N);
	for (i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	std::sort(begin(vec), end(vec), [](int a, int b) {return (abs(a) < abs(b));});
	for (i = 0; i < N; ++i) {
		std::cout << vec[i] << " ";
	}
	return 0;
}
