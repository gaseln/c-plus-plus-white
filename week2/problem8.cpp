#include <iostream>
#include <vector>
#include <algorithm>

int CalculateAverage(std::vector<int>& vec) {
    long res = 0;
    for (auto val: vec) {
        res += val;
    }
    return int(res / vec.size());
}

int main() {
    int N, i;
    std::cin >> N;
    std::vector<int> temp(N);
    for (i = 0; i < N; ++i) {
        std::cin >> temp[i];
    }
    int average = CalculateAverage(temp);
    int count = 0;
    std::vector<int> ind;
    for (i = 0; i < N; ++i) {
        if (temp[i] > average) {
            count++;
            ind.push_back(i);
        }
    }
    std::cout << count << std::endl;
    for (i = 0; i < count; ++i) {
        std::cout << ind[i] << " ";
    }
    return 0;
}
