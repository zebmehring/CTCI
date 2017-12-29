#include <string>
#include <iostream>

bool toggle(bool val)
{
	return val ? false : true;
}

bool isPalindromePermutaton(std::string str)
{
	bool arr[26] = { 0 };
	int nOdds = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		arr[(int)str[i]-97] = toggle(arr[(int)str[i] - 97]);
	}
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == 1)
			nOdds++;
	}

	if ((str.size() % 2 == 0) && (nOdds % 2 == 0))
		return true;
	else if ((str.size() % 2 == 1) && (nOdds % 2 == 1))
		return true;
	else
		return false;
}

int main()
{
	std::cout << isPalindromePermutaton("Taco coa") << std::endl;
	std::cout << isPalindromePermutaton("notap") << std::endl;
	std::cin.get();
}