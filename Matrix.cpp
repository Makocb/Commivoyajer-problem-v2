#include "Matrix.h"

#include <ctime>
#include <iostream>
#include "Globals.h"


Matrix::Matrix():Matrix(Globals::defaultGenerationMin, Globals::defaultGenerationMax, Globals::defaultSize)
{
}

Matrix::Matrix(int min, int max, int dim)
{
	std::srand(time(NULL));

	std::vector<int> matrixRow;
	for (int i = 0; i < dim; i++)
	{
		horzHeading.push_back(i);
		vertHeading.push_back(i);

		for (int j = 0; i < dim; i++)
		{
			matrixRow.push_back(rand() % (max - min + 1) + min);
		}
		matrix.push_back(matrixRow);
		matrixRow.clear();
	}
}

int Matrix::minInRow(const int& rowNum)
{
	try
	{
		if ((rowNum > matrix.size()) or (rowNum < 0))
		{
			throw(100);
		}

		int min = -1;
		for (auto& number : matrix[rowNum])
		{
			if (number < min)
			{
				min = number;
			}
		}

		return min;
	}
	catch(int errorCode)
	{
		catchBlock_(errorCode);
	}
}

int Matrix::minInCol(const int& colNum)
{
	try
	{
		if ((colNum > matrix.size()) or (colNum < 0))
		{
			throw(100);
		}

		int min = -1;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i][colNum] < min)
			{
				min = matrix[i][colNum];
			}
		}

		return min;
	}
	catch (int errorCode)
	{
		catchBlock_(errorCode);
	}
}

void Matrix::rowReduction(const int& rowNum, const int& reductionNumber)
{
	try
	{
		if ((rowNum > matrix.size()) or (rowNum < 0))
		{
			throw(100);
		}

		for (auto& number : matrix[rowNum])
		{
			number -= reductionNumber;
		}

	}
	catch (int errorCode)
	{
		catchBlock_(errorCode);
	}
}

void Matrix::colReduction(const int& colNum, const int& reductionNumber)
{
	try
	{
		if ((colNum > matrix.size()) or (colNum < 0))
		{
			throw(100);
		}

		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i][colNum] -= reductionNumber;
		}

	}
	catch (int errorCode)
	{
		catchBlock_(errorCode);
	}
}

void Matrix::globalRowReduction()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		this->rowReduction(i, this->minInRow(i));
	}
}

void Matrix::globalColReduction()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		this->colReduction(i, this->minInCol(i));
	}
}

void Matrix::deleteRow(const int& rowNum)
{
	try
	{
		if ((rowNum > matrix.size()) or (rowNum < 0))
		{
			throw(100);
		}

		matrix[rowNum].clear();
		vertHeading.erase(vertHeading.begin() + rowNum);
	}
	catch (int errorCode)
	{
		catchBlock_(errorCode);
	}
}

void Matrix::deleteCol(const int& colNum)
{
	try
	{
		if ((colNum > matrix.size()) or (colNum < 0))
		{
			throw(100);
		}

		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].erase(matrix[i].begin() + colNum);
		}

		horzHeading.erase(horzHeading.begin() + colNum);
	}
	catch (int errorCode)
	{
		catchBlock_(errorCode);
	}
}

void Matrix::catchBlock_(int& errorCode)
{
	if (errorCode == 100)
	{
		std::cout << "index is out of matrix array range";
	}
	exit(errorCode);
}
