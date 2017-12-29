#include <vector>

std::vector<std::vector<int>> zeroMatrix(std::vector<std::vector<int>> mat)
{
	unsigned int i = 0;
	unsigned int j = 0;
	bool col0 = false;
	bool row0 = false;
	while (j < mat[0].size())
	{
		if (mat[0][j] == 0)
		{
			row0 = true;
			break;
		}
		j++;
	}
	while (i < mat.size())
	{
		if (mat[i][0] == 0)
		{
			col0 = true;
			break;
		}
		i++;
	}

	for (i = 1; i < mat.size(); i++)
	{
		for (j = 1; j < mat[0].size(); j++)
		{
			if (mat[i][j] == 0)
			{
				mat[0][j] = 0;
				mat[i][0] = 0;
			}
		}
	}

	for (i = 1; i < mat.size(); i++)
	{
		if (mat[i][0] == 0)
		{
			for (j = 0; j < mat[i].size(); j++)
				mat[i][j] = 0;
		}
	}

	for (j = 1; j < mat[0].size(); j++)
	{
		if (mat[0][j] == 0)
		{
			for (i = 0; i < mat.size(); i++)
				mat[i][j] = 0;
		}
	}

	if (row0)
	{
		for (j = 0; j < mat[0].size(); j++)
			mat[0][j] = 0;
	}

	if (col0)
	{
		for (i = 0; i < mat.size(); i++)
			mat[i][0] = 0;
	}

	return mat;
}