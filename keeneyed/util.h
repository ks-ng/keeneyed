#include <initializer_list>
#include <string>

namespace util {

	namespace list {

		template <typename T>
		class Node {

			private:

				T val;
				Node<T>* next;
				Node<T>* last;

			public:
				
				Node(T val): val(val), next(nullptr), last(nullptr) {}

				T& value() { return val; }

				Node<T> getNext() { return *next; }
				Node<T> getLast() { return *last; }
				Node<T>* getNextPtr() { return next; }
				Node<T>* getLastPtr() { return last; }

				void setNext(Node<T>* ptr) { next = ptr; }
				void setLast(Node<T>* ptr) { last = ptr; }

		};

		template <typename T>
		class List {

			private:

				Node<T>* head;
				Node<T>* tail;

			public:

				List(): head(nullptr), tail(nullptr) {}

				List(std::initializer_list<int> initList): head(nullptr), tail(nullptr) {
					for (int value: initList) {
						append(value);
					}
				}

				List(int length): head(nullptr), tail(nullptr) {
					for (int i = 0; i < length; i++) {
						append(T())
					}
				}

				~List() { clear(); }

				void appendItem(T value) {
					Node<T>* newNode = new Node<T>(value);
					if (!head) {
						head = tail = newNode;
					} else {
						tail->next = newNode;
						newNode->prev = tail;
						tail = newNode;
					}
				}

				void prependItem(T value) {
					Node<T>* newNode = new Node<T>(value);
					if (!head) {
						head = tail = newNode;
					} else {
						newNode->next = head;
						head->prev = newNode;
						head = newNode;
					}
				}

				T& operator[](int index) {
					Node<T>* current = head;
					for (int i = 0; i < index; i++) {
						current = head->getNextPtr();
					}
					return current->value();
				}

				void clear() {
					Node<T>* current = head;
					while (current) {
						Node<T>* next = current->next;
						delete current;
						current = next;
					}
					head = tail = nullptr;
				}

		}

	};

};
