#include <cstdbool>
#include <string>
#include <iostream>

bool isSubstring(std::string &s1, std::string &s2)
{
	std::string temp = s1 + s1;
	return (temp.find(s2) != std::string::npos) ? true : false;
}

int main()
{
	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";
	std::cout << isSubstring(s1, s2) << std::endl;

	std::string s3 = "waterbottle";
	std::string s4 = "dinosaursaa";
	std::cout << isSubstring(s3, s4) << std::endl;
	
	std::cin.get();
}