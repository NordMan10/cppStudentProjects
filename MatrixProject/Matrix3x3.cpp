#include <iostream>
#include <time.h>
#include "Matrix3x3.h"
using namespace std;

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
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 3; j++)
			matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
}

int Matrix3x3::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 3; j++)
			if (i == j)	
				sum += matrix[i][j];
	return sum;
}

int Matrix3x3::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < 3; i++)
		sum += matrix[i][3 - i - 1];
	return sum;
}
int Matrix3x3::productPrincipalDiag() const
{
	int sum = 1;
	for (auto i = 0; i < 3; i++)
		for (auto j = 0; j < 3; j++)
			if (i == j)
				sum *= matrix[i][j];
	return sum;
}
int Matrix3x3::productSecondaryDiag() const
{
	int sum = 1;
	for (auto i = 0; i < 3; i++)
		sum *= matrix[i][3 - 1 - i];
	return sum;
}
int Matrix3x3::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto j = 0; j < 3; j++)
		sum += matrix[iRow][j];
	return sum;
}
int Matrix3x3::minColumn(const int iCol) const
{
	int sum = INT32_MAX;
	for (auto i = 0; i < 3; i++)
		if (matrix[i][iCol] < sum)
			sum = matrix[i][iCol];
	return sum;
}
int Matrix3x3::maxColumn(const int iCol) const
{
	int sum = INT32_MIN;
	for (auto i = 0; i < 3; i++)
		if (matrix[i][iCol] > sum)
			sum = matrix[i][iCol];
	return sum;
}