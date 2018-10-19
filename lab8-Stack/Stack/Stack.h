#pragma once
#define MAXSIZE 1000
template<class T> class Stack
{
public:
	Stack()
	{
		topp = bottom;
	}

	~Stack()
	{
	}

	void Stack<T>::pop() {
		if (topp < 1) {
			throw std::out_of_range("Stack<>::pop(): empty stack");
		}
		else
			data[--topp] = T();
	}

	void push(T const &t) {
		if (topp >= MAXSIZE)
			throw std::out_of_range("Stack<>::pop(): full stack");
		else
			data[topp++] = t;
	}
	T top()const {
		return data[topp - 1 > 0 ? topp - 1 : 0];
	}

	bool empty()const {
		return topp == bottom;
	}

	bool full()const {
		return topp == MAXSIZE - 1;
	}

private:
	T data[MAXSIZE];
	const int bottom = 0;
	int topp = 0;
};

