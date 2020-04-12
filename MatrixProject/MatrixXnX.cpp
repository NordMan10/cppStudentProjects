#include "MatrixXnX.h"
#include <iostream>
#include <time.h>
#include "MatrixXnX.h"
using namespace std;


MatrixXnX::MatrixXnX(const int iDim)
{
	dimension = iDim;
	matrix = new int* [iDim];
	for (auto i = 0; i < iDim; i++)
		matrix[i] = new int[iDim];
	for (auto i = 0; i < iDim; i++)
		for (auto j = 0; j < iDim; j++)
			matrix[i][j] = 0;
}
int MatrixXnX::element(const int i, const int j) const
{
	return matrix[i][j];
}
void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(0));
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
}
void MatrixXnX::setElement(const int i, const int j, const int value)
{
	matrix[i][j] = value;
}
int MatrixXnX::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			if (i == j)
				sum += matrix[i][j];
	return sum;
}
int MatrixXnX::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i][dimension - 1 - i];
	return sum;
}
int MatrixXnX::productPrincipalDiag() const
{
	int sum = 1;
	for (auto i = 0; i < dimension; i++)
		for (auto j = 0; j < dimension; j++)
			if (i == j)
				sum *= matrix[i][j];
	return sum;
}
int MatrixXnX::productSecondaryDiag() const
{
	int sum = 1;
	for (auto i = 0; i < dimension; i++)
		sum *= matrix[i][dimension - 1 - i];
	return sum;
}
int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto j = 0; j < dimension; j++)
		sum += matrix[iRow][j];
	return sum;
}
int MatrixXnX::minColumn(const int iCol) const
{
	int sum = INT32_MAX;
	for (auto i = 0; i < dimension; i++)
		if (matrix[i][iCol] < sum)
			sum = matrix[i][iCol];
	return sum;
}
int MatrixXnX::maxColumn(const int iCol) const
{
	int sum = INT32_MIN;
	for (auto i = 0; i < dimension; i++)
		if (matrix[i][iCol] > sum)
			sum = matrix[i][iCol];
	return sum;
}
