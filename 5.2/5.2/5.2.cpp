#include <iostream>
#include <bitset>
#include <string>

std::string toBinary(double n)
{
	if (n >= 1 || n <= 0)
		return NULL;
	std::string binary(".");
	while (n > 0)
	{
		if (binary.size() >= 32)
			return "ERROR";
		double r = n * 2;
		(r >= 1) ? binary.append("1") : binary.append("0");
		n = (r >= 1) ? r - 1 : r;
	}
	return binary;
}

int main()
{
	std::cout << toBinary(.72) << std::endl;
	std::cin.get();
	return 0;
}