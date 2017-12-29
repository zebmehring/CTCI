#include <string>
#include <iostream>

std::string compressString(std::string &str)
{
	std::string compressed;
	int count = 0;
	for (int i = 0; i < (int) str.length(); i++)
	{
		count++;

		if ((i + 1 >= (int)str.length()) || (str[i] != str[i + 1]))
		{
			compressed.push_back(str[i]);
			compressed.append(std::to_string(count));
			count = 0;
		}
	}
	return (compressed.length() < str.length()) ? compressed : str;
}

int main()
{
	std::string one("aabcccccaaa");
	std::cout << compressString(one) << std::endl;
	std::cin.get();
}