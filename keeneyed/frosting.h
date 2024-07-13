#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <unistd.h>
#include <random>

namespace frosting {

	void hideCursor() {
		std::cout << "\e[?25l";
	}

	void showCursor() {
		std::cout << "\e[?25h";
	}

	void sleep(int us) {
		usleep(us);
	}

	std::string HEADER = "\033[95m";
	std::string OKBLUE = "\033[94m";
	std::string OKCYAN = "\033[96m";
	std::string OKGREEN = "\033[92m";
	std::string WARNING = "\033[93m";
	std::string FAIL = "\033[91m";
	std::string ENDC = "\033[0m";
	std::string BOLD = "\033[1m";
	std::string UNDERLINE = "\033[4m";

	std::string colorize(std::string text, std::string color) {
		return color + text + ENDC;
	}

	std::string intrepr(int x) {
		std::stringstream ss;
		if (x >= 1e+30) {
			ss << x / 1e+30 << "Q";
		} else if (x >= 1e+27) {
			ss << x / 1e+15 << "R";
		} else if (x >= 1e+24) {
			ss << x / 1e+15 << "Y";
		} else if (x >= 1e+21) {
			ss << x / 1e+15 << "Z";
		} else if (x >= 1e+18) {
			ss << x / 1e+15 << "E";
		} else if (x >= 1e+15) {
			ss << x / 1e+15 << "P";
		} else if (x >= 1e+12) {
			ss << x / 1e+12 << "T";
		} else if (x >= 1e+9) {
			ss << x / 1e+9 << "B";
		} else if (x >= 1e+6) {
			ss << x / 1e+6 << "M";
		} else if (x >= 1e+3) {
			ss << x / 1e+3 << "k";
		} else {
			ss << x;
		}
		return ss.str();
	}

	double randomValue() {
		return (static_cast<float>(rand()) / static_cast<float>(RAND_MAX) - 0.5) * 2;
	}

};