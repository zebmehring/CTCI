#include <iostream>
#include <bitset>

int insert(int N, int M, int i, int j)
{
	int mask = (1 << (j - i + 1)) - 1;
	mask = ~(mask << i);
	N = N & mask;
	M = M << i;
	return M | N;	
}

int main()
{
	int N = 0b10000000000;
	int M = 0b10011;
	int i = 2;
	int j = 6;
	int shifted = insert(N, M, i, j);
	std::cout << std::bitset<16>(shifted) << std::endl;
	std::cin.get();
	return 0;
}