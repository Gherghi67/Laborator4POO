#include <iostream>
#include <stdexcept>
#include "Fraction.h"
#include "Vector.h"
using namespace std;
Vector::Vector() {
	size = 0;
	storage = NULL;
}
Vector::Vector(int size) {
	this->size = size;
	storage = new Fraction[size];
}
Vector::Vector(Vector &vector) {
	this->size = vector.size;
	this->storage = new Fraction[this->size];
	int i;
	for (i = 0; i < this->size; i++) {
		this->storage[i] = vector.storage[i];
	}
}
Vector::~Vector() {
	delete[] storage;
	size = 0;
}
Vector& Vector::operator=(const Vector &vector) {
	if (&vector == this) {
		return *this;
	}
	delete[] this->storage;
	this->size = vector.size;
	this->storage = new Fraction[this->size];
	int i;
	for (i = 0; i < this->size; i++) {
		this->storage[i] = vector.storage[i];
	}
	return *this;
}
istream& operator>>(istream &in, Vector &vector) {
	int i;
	for (i = 0; i < vector.size; i++) {
		in >> vector.storage[i];
	}
	return in;
}
ostream& operator<<(ostream &out, Vector &vector) {
	int i;
	for (i = 0; i < vector.size; i++) {
		out << vector.storage[i] << " ";
	}
	out << "\n";
	return out;
}
Vector operator*(const Fraction &x, const Vector &vector) {
	Vector v;
	v.size = vector.size;
	v.storage = new Fraction[v.size];
	int i;
	for (i = 0; i < v.size; i++) {
		v.storage[i] = vector.storage[i] * x;
	}
	return v;
}
Vector Vector::operator+(const Vector &vector) const {
	if (vector.size != this->size) {
		invalid_argument e("Dimensiuni incorecte");
		throw e;
	}
	Vector v;
	v.size = this->size;
	v.storage = new Fraction[v.size];
	int i;
	for (i = 0; i < this->size; i++) {
		v.storage[i] = this->storage[i] + vector.storage[i];
	}
	return v;
}
Vector Vector::operator-(const Vector &vector) const {
	if (vector.size != this->size) {
		invalid_argument e("Dimensiuni incorecte");
		throw e;
	}
	Vector v;
	v.size = this->size;
	v.storage = new Fraction[v.size];
	int i;
	for (i = 0; i < this->size; i++) {
		v.storage[i] = this->storage[i] - vector.storage[i];
	}
	return v;
}