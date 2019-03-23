#pragma once
#include <iostream>
#include "Fraction.h"
using namespace std;
class Vector {
private:
	int size;
	Fraction* storage;
public:
	Vector();
	Vector(int size);
	Vector(Vector &vector);
	~Vector();
	Vector& operator=(const Vector &vector);
	friend istream& operator>>(istream &in, Vector &vector);
	friend ostream& operator<<(ostream &out, Vector &vector);
	friend Vector operator*(const Fraction &x, const Vector &vector);
	Vector operator+(const Vector &vector) const;
	Vector operator-(const Vector &vector) const;
};