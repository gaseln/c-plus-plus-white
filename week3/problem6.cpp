#include <string>
#include <iostream>

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const std::string str) {
		private_string = str;
	}
	void Reverse() {
		std::string new_string = private_string;
		int size = private_string.size();
		for (int i = 0; i < size; ++i) {
			new_string[size - 1 - i] = private_string[i];
		}
		private_string = new_string;
	}
	std::string ToString() const {
		return private_string;
	}
private:
	std::string private_string;
};

/*
int main() {
	ReversibleString s("live");
	s.Reverse();
	std::cout << s.ToString() << std::endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	std::cout << tmp << std::endl;

	ReversibleString empty;
	std::cout << '"' << empty.ToString() << '"' << std::endl;

	return 0;
}*/