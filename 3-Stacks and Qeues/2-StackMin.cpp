// 2-StackMin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
	int top() {
		return all.top();
	}

	int min() {
		return minimum.top();
	}

	void push(const int& i) {
		if (minimum.empty() || min() >= 1) {
			minimum.push(i);
		}
		all.push(i);
	}

	void pop() {
		if (top() == min()) {
			minimum.pop();
		}
		all.pop();
	}


private:
	stack<int>all;
	stack<int>minimum;
};



int main()
{
    return 0;
}

