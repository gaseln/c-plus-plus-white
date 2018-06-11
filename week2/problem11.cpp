#include <iostream>
#include <map>
#include <string>
#include <vector>

bool IsAnagram(std::string s1, std::string s2) {
    std::map<char, int> for_s1, for_s2;
    for (const auto& sym: s1) {
        ++for_s1[sym];
    }
    for (const auto& sym: s2) {
        ++for_s2[sym];
    }
    if (for_s1 == for_s2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, i;
    std::cin >> N;
    std::vector<bool> out(N);
    std::string s1, s2;
    for (i = 0; i < N; ++i) {
        std::cin >> s1 >> s2;
        out[i] = IsAnagram(s1, s2);
    }
    for (i = 0; i < N; ++i) {
        if (out[i]) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
