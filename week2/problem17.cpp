#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

int main() {
	std::map<std::string, std::set<std::string>> synonyms;
	std::vector<std::string> out;
	int Q, i;
	std::string str1, word1, word2;
	std::cin >> Q;
	for (i = 0; i < Q; ++i) {
		std::cin >> str1;
		if (str1 == "ADD") {
			std::cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		}
		if (str1 == "COUNT") {
			std::cin >> word1;
			out.push_back(std::to_string(synonyms[word1].size()));
		}
		if (str1 == "CHECK") {
			std::cin >> word1 >> word2;
			if (synonyms[word1].count(word2) == 0) {
				out.push_back("NO");
			}
			else {
				out.push_back("YES");
			}
		}
	}
	for (i = 0; i < out.size(); ++i) {
		std::cout << out[i] << std::endl;
	}
	return 0;
}