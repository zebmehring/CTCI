#include <deque>
#include <iostream>

std::deque<int> sumLists(std::deque<int> first, std::deque<int> second);
int sumLists(std::deque<int> &first, std::deque<int> &second, std::deque<int> &result);

std::deque<int> sumLists(std::deque<int> first, std::deque<int> second)
{
	while (second.size() < first.size()) 
	{
		second.push_front(0);
	}

	while (second.size() > first.size()) 
	{
		first.push_front(0);
	}

	std::deque<int> result;

	int carry_out = sumLists(first, second, result);

	if(carry_out) result.push_front(1);

	return result;
}

int sumLists(std::deque<int> &first, std::deque<int> &second, std::deque<int> &result)
{
	int first_val = first.front();
	int second_val = second.front();
	first.pop_front();
	second.pop_front();
	int carry = 0;
	if (first.size() && second.size()) carry = sumLists(first, second, result);
	int sum = first_val + second_val + carry;
	result.push_front(sum % 10);
	return sum > 9;
}

int main()
{
	std::deque<int> first; 
	std::deque<int> second;

	first.push_front(9);
	first.push_front(9);
	first.push_front(9);

	second.push_front(5);
	second.push_front(9);
	second.push_front(2);

	std::deque<int> result = sumLists(first, second);

	for (int i : result)
		std::cout << i << ", ";
	std::cout << std::endl;
	std::cin.get();
	return 0;
}