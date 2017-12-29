#include <iostream>
#include <vector>

template <typename T>
std::vector<std::vector<T>> powerSet(std::vector<T> s)
{
	std::vector<std::vector<T>> ps;
	powerSetHelper(ps, s, 0);
	return ps;
}

template <typename T>
void powerSetHelper(std::vector<std::vector<T>> &ps, std::vector<T> s, int i)
{
	if (s.size() <= i)
	{
		std::vector<T> empty(1);
		ps.push_back(empty);
		return;
	}

	powerSetHelper(ps, s, i + 1);
	std::vector<std::vector<T>> newsets;
	for (std::vector<T> set : ps)
	{
		std::vector<T> newset;
		for (T item : set)
			newset.push_back(item);
		newset.push_back(s[i]);
		newsets.push_back(newset);
	}

	for (std::vector<T> set : newsets)
		ps.push_back(set);
}

int main()
{
	std::vector<int> s;
	s.push_back(4);
	s.push_back(3);
	s.push_back(2);
	s.push_back(1);
	std::vector<std::vector<int>> ps = powerSet(s);
	for (std::vector<int> set : ps)
	{
		std::cout << "{" << set[0];
		for (unsigned int i = 1; i < set.size(); i++)
			std::cout << ", " << set[i];
		std::cout << "}" << std::endl;
	}
	std::cin.get();
}