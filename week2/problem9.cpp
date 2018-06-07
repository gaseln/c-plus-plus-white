#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int BoolSum(std::vector<bool> vec) {
    int res = 0;
    for (auto el: vec) {
        if (el) {
            ++res;
        }
    }
    return res;
}


int main() {
    std::vector<int> worry_count;
    int n, i, j;
    std::string str;
    std::cin >> n;
    std::vector<bool> queue;
    for (i = 0; i < n; ++i) {
        std::cin >> str;
        if (str == "WORRY") {
            std::cin >> j;
            queue[j] = true;
        }
        if (str == "QUIET") {
            std::cin >> j;
            queue[j] = false;
        }
        if (str == "COME") {
            std::cin >> j;
            queue.resize(queue.size() + j, false);
        }
        if (str == "WORRY_COUNT") {
            worry_count.push_back(BoolSum(queue));
        }
    }
    for (i = 0; i < worry_count.size(); ++i) {
        std::cout << worry_count[i] << std::endl;
    }
    return 0;
}
