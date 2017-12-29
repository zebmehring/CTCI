#include <stack>
#include <iostream>

void sort(std::stack<int>& s)
{
	std::stack<int> sorted;
	while (!s.empty())
	{
		int popped = s.top();
		s.pop();
		int numPushed = 0;
		for ( ; !sorted.empty() && (popped < sorted.top()); numPushed++)
		{
			int temp = sorted.top();
			sorted.pop();
			s.push(temp);
		}
		sorted.push(popped);
		for (int i = numPushed; i > 0; i--)
		{
			int temp = s.top();
			s.pop();
			sorted.push(temp);
		}
	}
	while (!sorted.empty())
	{
		int temp = sorted.top();
		std::cout << temp << std::endl;
		sorted.pop();
		s.push(temp);
	}
}

int main()
{
	std::stack<int> s;
	s.push(15);
	s.push(5);
	s.push(0);
	s.push(8);
	s.push(-1);
	sort(s);

	std::cin.get();
}