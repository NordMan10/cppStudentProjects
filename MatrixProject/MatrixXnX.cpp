#include "MatrixXnX.h"
#include <iostream>
#include <time.h>

MatrixXnX::MatrixXnX(const int iDim)
{
	dimension = iDim;
	matrix = new int [iDim * iDim];
	for (auto i = 0; i < iDim * iDim; i++)
		matrix[i] = 0;
}

int MatrixXnX::element(const int i, const int j) const
{
	return matrix[i * dimension + j];
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(0));
	for (auto i = 0; i < dimension * dimension; i++)
		matrix[i] = minVal + rand() % (maxVal - minVal + 1);
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	matrix[i * dimension + j] = value;
}

int MatrixXnX::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i * dimension + i];
	return sum;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[i * dimension + dimension - i - 1];
	return sum;
}

int MatrixXnX::productPrincipalDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= matrix[i * dimension + i];
	return product;
}

int MatrixXnX::productSecondaryDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= matrix[i * dimension + dimension - i - 1];
	return product;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += matrix[iRow * dimension + i];
	return sum;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = INT32_MAX;
	for (auto i = iCol; i < dimension * dimension; i += dimension)
		if (matrix[i] < min)
			min = matrix[i];
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = INT32_MIN;
	for (auto i = iCol; i < dimension * dimension; i += dimension)
		if (matrix[i] > max)
			max = matrix[i];
	return max;
}

int MatrixXnX::getDimension() const
{
	return dimension;
}
