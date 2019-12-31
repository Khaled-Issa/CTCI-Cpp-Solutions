// 1-ThreeInOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>

class MultiStack {

public:
	MultiStack(size_t capacity) {
		stack_capacity = capacity;
		values = new int[num_stacks * capacity];
		sizes = new size_t[num_stacks];
	}

	~MultiStack() {
		delete values;
		delete sizes;
	}

	void push(size_t stack_index, int value) {
		assert(!is_empty(stack_index));
		sizes[stack_index]++;
		values[index_of_top(stack_index)] = value;
	}

	int pop(size_t stack_index) {
		assert(!is_empty(stack_index));

		size_t top_index = index_of_top(stack_index);
		int value = values[top_index];
		values[top_index] = 0;
		sizes[stack_index]--;

		return value;
	}

	int peek(size_t stack_index) {
		assert(!is_empty(stack_index));
		return values[index_of_top(stack_index)];
	}

	size_t index_of_top(size_t stack_index) {
		size_t offset = stack_index*stack_capacity;
		size_t size = sizes[stack_index];
		return offset + size - 1;
	}

	bool is_full(size_t stack_index) {
		return (sizes[stack_index] == stack_capacity);
	}

	bool is_empty(size_t stack_index) {
		return (sizes[stack_index] == 0);
	}

	
private:
	const int num_stacks = 3;
	size_t stack_capacity;
	int* values;
	size_t* sizes;
};




int main()
{
    return 0;
}

