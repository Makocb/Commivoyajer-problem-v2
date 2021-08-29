#pragma once

#include <vector>

#include "Globals.h"

class Matrix
{
	public:
		std::vector<std::vector<int>> matrix;
		std::vector<int> horzHeading;
		std::vector<int> vertHeading;

		Matrix();

		Matrix( int min, int max, int dim );

		int minInRow(const int& rowNum);
		int minInCol(const int& colNum);

		void rowReduction(const int& rowNum, const int& reductionNumber);
		void colReduction(const int& colNum, const int& reductionNumber);

		void globalRowReduction();
		void globalColReduction();

		void deleteRow(const int& rowNum);
		void deleteCol(const int& colNum);

	private:

		void catchBlock_(int& errorCode);
};

