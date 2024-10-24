// C++ program to merge to unsorted stacks
// into a third stack in sorted way.
#include <bits/stdc++.h>
using namespace std;

// Sorts input stack and returns sorted stack.
stack<int> sortStack(stack<int>& input)
{
	stack<int> tmpStack;

	while (!input.empty()) {
		// pop out the first element
		int tmp = input.top();
		input.pop();

		// while temporary stack is not empty and top
		// of stack is greater than temp
		while (!tmpStack.empty() && tmpStack.top() > tmp) {

			// pop from temporary stack and push
			// it to the input stack
			input.push(tmpStack.top());
			tmpStack.pop();
		}

		// push temp in temporary of stack
		tmpStack.push(tmp);
	}

	return tmpStack;
}

stack<int> sortedMerge(stack<int>& s1, stack<int>& s2)
{
	// Push contents of both stacks in result
	stack<int> res;
	while (!s1.empty()) {
		res.push(s1.top());
		s1.pop();
	}
	while (!s2.empty()) {
		res.push(s2.top());
		s2.pop();
	}

	// Sort the result stack.
	return sortStack(res);
}

// main function
int main()
{
	stack<int> s1, s2;
	s1.push(34);
	s1.push(3);
	s1.push(31);

	s2.push(1);
	s2.push(12);
	s2.push(23);

	// This is the temporary stack
	stack<int> tmpStack = sortedMerge(s1, s2);
	cout << "Sorted and merged stack :\n";

	while (!tmpStack.empty()) {
		cout << tmpStack.top() << " ";
		tmpStack.pop();
	}
}
