#include <iostream>
#include <time.h>
#include "Matrix3x3.h"

int Matrix3x3::element(const int i, const int j) const
{
	return matrix[i][j];
}

void Matrix3x3::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(0));
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
}

int Matrix3x3::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			if (i == j)	
				sum += matrix[i][j];
	return sum;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i][dimension - i - 1];
	return sum;
}

int Matrix3x3::productPrincipalDiag() const
{
	int sum = 1;
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			if (i == j)
				sum *= matrix[i][j];
	return sum;
}

int Matrix3x3::productSecondaryDiag() const
{
	int sum = 1;
	for (auto i = 0; i < dimension; i++)
		sum *= matrix[i][dimension - 1 - i];
	return sum;
}

int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto j = 0; j < dimension; j++)
		sum += matrix[iRow][j];
	return sum;
}

int Matrix3x3::minColumn(const int iCol) const
{
	int sum = std::numeric_limits<int>::max();
	for (auto i = 0; i < dimension; i++)
		if (matrix[i][iCol] < sum)
			sum = matrix[i][iCol];
	return sum;
}

int Matrix3x3::maxColumn(const int iCol) const
{
	int sum = std::numeric_limits<int>::min();
	for (auto i = 0; i < dimension; i++)
		if (matrix[i][iCol] > sum)
			sum = matrix[i][iCol];
	return sum;
}
