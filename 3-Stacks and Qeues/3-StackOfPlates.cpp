﻿// 3-StackOfPlates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<cassert>

using namespace std;

class setOfStacks{

public:

	void popAt(size_t index)
	{
		assert(index < stack_vec.size() && stack_vec[index].size() > 0);
		if (stack_vec[index].size() > 1)
		{
			stack_vec[index].pop();
		}
		else
		{
			if (stack_vec.size() > 1)
				stack_vec.erase(stack_vec.begin() + index);
			else // we only have one stack
				stack_vec[index].pop();
		}
	}

	bool pop()
	{
		if (stack_vec.size() == 1 && stack_vec[0].empty())
			return false;

		stack_vec.back().pop();

		if (stack_vec.back().empty() && stack_vec.size() > 1)
			stack_vec.pop_back();

		return true;
	}

	void push(const int& i)
	{
		if (stack_vec.back().size() == capacity)
			stack_vec.push_back(stack<int>());
		stack_vec.back().push(i);
	}


private:
	vector<stack<int>> stack_vec;
	size_t capacity;
};



int main()
{
    return 0;
}

