#include <iostream>
#include <string>
#include <array>

bool oneAway(std::string &s1, std::string &s2);
bool oneReplace(std::string &s1, std::string &s2);
bool oneInsert(std::string &s1, std::string &s2);

bool oneAway(std::string &s1, std::string &s2)
{
	if (s1.size() == s2.size())
		return oneReplace(s1, s2);
	else if (s1.size() == (s2.size() - 1))
		return oneInsert(s2, s1);
	else if (s1.size() == (s2.size() + 1))
		return oneInsert(s1, s2);
	else
		return false;
}

bool oneReplace(std::string &s1, std::string &s2)
{
	bool diff = false;
	for (unsigned int i = 0; i < s1.size(); i++)
	{
		if (s1.at(i) != s2.at(i))
		{
			if (diff)
				return false;
			else
				diff = true;
		}			
	}
	return true;
}

bool oneInsert(std::string &s1, std::string &s2)
{
	unsigned int i = 0, j = 0;
	while (i < s1.size() && j < s2.size())
	{
		if (s1.at(i) != s2.at(j))
		{
			if (i != j)
				return false;
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	return true;
}

int main()
{
	std::string s1 = "pale";
	std::string s2 = "ple";
	std::cout << oneAway(s1, s2) << std::endl;

	std::string s3 = "bake";
	std::cout << oneAway(s1, s3) << std::endl;

	std::cin.get();
}