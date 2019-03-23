#include <iostream>
#include "Fraction.h"
using namespace std;
Fraction::Fraction() {
	n = 0;
	m = 1;
}
Fraction::Fraction(int n, int m) {
	this->n = n;
	this->m = m;
	int x = GCD(n, m);
	this->n /= x;
	this->m /= x;
}
Fraction::Fraction(const Fraction &fraction) {
	n = fraction.n;
	m = fraction.m;
}
int Fraction::GCD(int n, int m) const{
	if (n == 0)
		return m;
	if (m == 0)
		return n;
	if (n == m)
		return n;
	while (n != m) {
		if (n > m)
			n -= m;
		else
			m -= n;
	}
	return n;
}
Fraction Fraction::operator+(const Fraction &fraction) const {
	Fraction f;
	f.m = GCD(this->m, fraction.m);
	f.m = (this->m * fraction.m) / f.m;
	f.n = (this->n) * (f.m / this->m) + (fraction.n) * (f.m / fraction.m);
	int x = GCD(f.n, f.m);
	f.n /= x;
	f.m /= x;
	return f;
}
Fraction Fraction::operator-(const Fraction &fraction) const {
	Fraction f;
	f.m = GCD(this->m, fraction.m);
	f.m = (this->m * fraction.m) / f.m;
	f.n = (this->n) * (f.m / this->m) - (fraction.n) * (f.m / fraction.m);
	int x = GCD(f.n, f.m);
	f.n /= x;
	f.m /= x;
	return f;
}
Fraction Fraction::operator*(const Fraction &fraction) const {
	Fraction f;
	f.n = this->n * fraction.n;
	f.m = this->m * fraction.m;
	int x = GCD(f.n, f.m);
	f.n /= x;
	f.m /= x;
	return f;
}
Fraction Fraction::operator/(const Fraction &fraction) const {
	Fraction f;
	f.n = this->n * fraction.m;
	f.m = this->m * fraction.n;
	int x = GCD(f.n, f.m);
	f.n /= x;
	f.m /= x;
	return f;
}
istream& operator>>(istream &in, Fraction &fraction) {
	in >> fraction.n;
	in >> fraction.m;
	return in;
}
ostream& operator<<(ostream &out, Fraction &fraction) {
	out << fraction.n << "/" << fraction.m;
	return out;
}
Fraction operator*(int x, const Fraction &fraction) {
	Fraction f;
	f.n = fraction.n * x;
	f.m = fraction.m * x;
	return f;
}
int Fraction::GetN() {
	return n;
}
int Fraction::GetM() {
	return m;
}
void Fraction::SetN(int x) {
	n = x;
}
void Fraction::SetM(int x) {
	m = x;
}