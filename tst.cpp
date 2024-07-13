#include "keeneyed/calc.h"

int main() {
	calc::Vector v = {1, 2};
	calc::Operator o1 = {{1, 0}, {0, 1}};
	calc::Operator o2 = {{2, 0}, {0, 1}};
	calc::Operator o3 = {{1, 0}, {0, 0}};

	o3.set(1, 1, 2);

	std::cout << v.repr() << std::endl;

	calc::Vector r1 = calc::operate(v, o1);
	calc::Vector r2 = calc::operate(v, o2);
	calc::Vector r3 = calc::operate(v, o3);

	std::cout << r1.repr() << " " << r2.repr() << " " << r3.repr() << std::endl;
}