#include <algorithm>
#include <vector>
#include <iostream>

class FunctionPart {
public:
	FunctionPart(const char& new_operation, const double& new_value) {
		operation = new_operation;
		value = new_value;
	}
	double Apply(const double& argument) const {
		if (operation == '+') {
			return argument + value;
		}
		else {
			return argument - value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		}
		else {  
			operation = '+';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char operation, double value) {
		parts.push_back({ operation, value });
	}
	double Apply(double value) const {
		for (const auto& part : parts) {
			value = part.Apply(value);
		}
		return value;
	}
	void Invert() {
		for (auto& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}
private:
	std::vector<FunctionPart> parts;
};