#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
	int n;
	int m;
	int GCD(int n, int m) const;
public:
	Fraction();
	Fraction(int n, int m);
	Fraction(const Fraction &fraction);
	Fraction operator+(const Fraction &fraction) const;
	Fraction operator-(const Fraction &fraction) const;
	Fraction operator*(const Fraction &fraction) const;
	Fraction operator/(const Fraction &fraction) const;
	friend istream& operator>>(istream &in, Fraction &fractie);
	friend ostream& operator<<(ostream &out, Fraction &fractie);
	friend Fraction operator*(int x, const Fraction &fraction);
	int GetN();
	int GetM();
	void SetN(int x);
	void SetM(int x);
};