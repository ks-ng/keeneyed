#pragma once
#include "data.h"
#include <complex>
#include <cmath>

namespace calc {

	using Vector = data::Array<double>;
	using Operator = data::Matrix<double>;
	using QuantumState = data::Array<std::complex<double>>;
	using QuantumOperator = data::Matrix<std::complex<double>>;

	double innerProduct(Vector a, Vector b) {
		int s = a.getLength();
		if (s != b.getLength()) { throw std::out_of_range("inner vector product: vector sizes do not match"); }
		double c = 0;
		for (int i = 0; i < s; i++) { c += a[i] * b[i]; }
		return c;
	}

	Operator outerProduct(Vector a, Vector b) {
		Operator c(a.getLength(), b.getLength());
		for (int i = 0; i < a.getLength(); i++) { for (int j = 0; j < b.getLength(); j++) { c.set(i, j, a[i] * b[j]); } }
		return c;
	}

	Vector operate(Vector a, Operator o) {
		if (o.getRows() != a.getLength()) { throw std::invalid_argument("operation: vector size must match operator rows"); }
		Vector b(o.getCols());
		double s;
		for (int i = 0; i < o.getCols(); i++) {
			s = 0;
			for (int j = 0; j < o.getRows(); j++) {
				s += o.get(i, j) * a.get(j);
			}
			b.set(i, s);
		}
		return b;
	}

};