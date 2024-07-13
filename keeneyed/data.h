#pragma once
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

namespace data {

	template <typename T>
	class Array {

		protected:

			T* elements;
			size_t length;
			bool cleanedUp = false;

			void indexCheck(const int index) { 
				if (index < 0 || index >= length) { 
					std::stringstream ss;
					ss << "array access: index out of range: tried index " << index << " on array of length " << length;
					throw std::out_of_range(ss.str()); 
				}
			}

		public:

			Array() {}
			Array(int l): length(l), elements(new T[l]) {}
			Array(std::initializer_list<T> initList): length(initList.size()), elements(new T[initList.size()]) {
				size_t index = 0; for (const T& value: initList) { elements[index++] = value; }
			}


			T& get(const int index) { indexCheck(index); return elements[index]; } 
			void set(const int index, const T value) { indexCheck(index); elements[index] = value; }
			T& operator[](const int index) { indexCheck(index); return elements[index]; }
			size_t getLength() const noexcept { return length; }

			std::string repr() {
				std::stringstream ss;
				ss << "{";
				for (int i = 0; i < getLength(); i++) { ss << get(i); if (i != getLength() - 1) { ss << " "; } }
				ss << "}";
				return ss.str();
			}

	};

	template <typename T>
	class Matrix {
	
		protected:

			T* elements;
			size_t rows;
			size_t cols;
			bool cleanedUp = false;

		public:

			Matrix() {}

			Matrix(int rows, int cols): rows(rows), cols(cols) {
				elements = new T[rows * cols];
				size_t index = 0;
			}

			Matrix(std::initializer_list<std::initializer_list<T>> initList) {
				rows = initList.size();
				cols = initList.begin()->size();
				elements = new T[rows * cols];
				size_t index = 0;
				for (auto& row : initList) {
					if (row.size() != cols) {
						throw std::invalid_argument("matrix initialization: all rows must have the same number of columns");
					}
					for (const T& value : row) {
						elements[index++] = value;
					}
				}
			}

			T& get(size_t row, size_t col) {
				if (row >= rows) throw std::out_of_range("matrix access: row out of range");
				if (col >= cols) throw std::out_of_range("matrix access: column out of range");
				return elements[row * cols + col];
			}
			void set(size_t row, size_t col, T value) { elements[row * cols + col] = value; }
			size_t getRows() { return rows; }
			size_t getCols() { return cols; }

	};

};