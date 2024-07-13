#include "keeneyed/neural.h"

int main() {
	neural::ff::FCL fcl(3, 5);
	for (int i = 0; i < 100; i++) {
		data::Vector in = {neural::getRandom(), neural::getRandom(), neural::getRandom()};
		std::cout << fcl.forward(in).repr() << std::endl;
	}
}