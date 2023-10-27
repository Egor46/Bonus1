#pragma once
#include "Vector.h"
#include <fstream>
#include "Complex.h"
#include <assert.h>

Vector<double> task1() {
	int al, bl;
	std::cin >> al;
	Vector<double> a(al), c;
	std::cin >> a >> bl;
	Vector<double> b(bl);
	std::cin >> b;
	return (a + b) * a;
}

Complex* task2(int n) {

	Complex* compA = new Complex[n];
	std::ifstream in1("comp1.txt");
	assert(in1.is_open() && !in1.eof());
	for (int i = 0; i < n; i++) in1 >> compA[i];

	Complex* compB = new Complex[n];
	std::ifstream in2("comp2.txt");
	assert(in1.is_open() && !in2.eof());
	for (int i = 0; i < n; i++) in2 >> compB[i];

	Complex* compC = new Complex[n];
	for (int i = 0; i < n; i++) {
		compC[i] = (compA[i] + compB[i]) * compA[i];
	}

	in1.close(); in2.close();
	delete[] compA; delete[] compB;
	return compC;
}

int main() {

	// task 1

	Vector<double> c = task1();
	std::cout << c << '\n';
	
	// task 2

	int n; std::cin >> n;
	Complex* compC = task2(n);
	for (int i = 0; i < n; i++) std::cout << compC[i] << std::endl;
	delete[] compC;

	return 0;
}