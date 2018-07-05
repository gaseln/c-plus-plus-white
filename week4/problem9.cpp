#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>

int gcd(const unsigned int& a, const unsigned int& b) {
	unsigned int c = a;
	unsigned int d = b;
	while (c * d != 0) {
		if (c < d)
			std::swap(c, d);
		c = c % d;
	}
	return int(d);
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}

	Rational(int new_numerator, int new_denominator) {
		int curr_gcd = gcd(abs(new_numerator), abs(new_denominator));
		numerator = new_numerator / curr_gcd;
		denominator = new_denominator / curr_gcd;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}
private:
	int numerator;
	int denominator;
};

Rational operator+(const Rational& lsd, const Rational& rsd) {
	return { lsd.Numerator() * rsd.Denominator() + rsd.Numerator() * lsd.Denominator(), lsd.Denominator() * rsd.Denominator() };
}

Rational operator-(const Rational& lsd, const Rational& rsd) {
	return { lsd.Numerator() * rsd.Denominator() - rsd.Numerator() * lsd.Denominator(), lsd.Denominator() * rsd.Denominator() };
}

Rational operator*(const Rational& lsd, const Rational& rsd) {
	return { lsd.Numerator() * rsd.Numerator(), lsd.Denominator() * rsd.Denominator() };
}

Rational operator/(const Rational& lsd, const Rational& rsd) {
	return { lsd.Numerator() * rsd.Denominator(), lsd.Denominator() * rsd.Numerator() };
}

bool operator==(const Rational& lsd, const Rational& rsd) {
	return ((lsd.Numerator() == rsd.Numerator()) && (lsd.Denominator() == rsd.Denominator()));
}

std::istream& operator>>(std::istream& input, Rational& rat) {
	std::string str;
	input >> str;
	if (!str.empty()) {
		int numerator, denominator;
		std::istringstream my_stream = std::istringstream(str);
		my_stream >> numerator;
		my_stream.ignore(1);
		my_stream >> denominator;
		rat = { numerator, denominator };
	}
	return input;
}

std::ostream& operator<<(std::ostream& output, const Rational& rat) {
	output << rat.Numerator() << "/" << rat.Denominator();
	return output;
}

bool operator<(const Rational& lsd, const Rational& rsd) {
	return (lsd.Numerator() * rsd.Denominator() < rsd.Numerator() * lsd.Denominator());
}