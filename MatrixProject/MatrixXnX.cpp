#include "MatrixXnX.h"
#include <iostream>
#include <time.h>

MatrixXnX::MatrixXnX(const int iDim) : dimension(iDim)
{
	matrix = new int [iDim * iDim];
	for (auto i = 0; i < iDim * iDim; i++)
		matrix[i] = 0;
}

MatrixXnX::~MatrixXnX()
{
	delete matrix;
}

int MatrixXnX::element(const int i, const int j) const
{
	return matrix[i * dimension + j];
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
{
	srand(time(NULL));
	for (auto i = 0; i < dimension * dimension; i++)
		matrix[i] = minVal + std::rand() % (maxVal - minVal + 1);
}

void MatrixXnX::setElement(const int i, const int j, const int value)
{
	matrix[i * dimension + j] = value;
}

int MatrixXnX::sumPrincipalDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += element(i, i);
	return sum;
}

int MatrixXnX::sumSecondaryDiag() const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += element(i, dimension - i - 1);
	return sum;
}

int MatrixXnX::productPrincipalDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= element(i, i);
	return product;
}

int MatrixXnX::productSecondaryDiag() const
{
	int product = 1;
	for (auto i = 0; i < dimension; i++)
		product *= element(i, dimension - i - 1);
	return product;
}

int MatrixXnX::sumRow(const int iRow) const
{
	int sum = 0;
	for (auto i = 0; i < dimension; i++)
		sum += element(iRow, i);
	return sum;
}

int MatrixXnX::minColumn(const int iCol) const
{
	int min = std::numeric_limits<int>::max();
	for (auto i = 0; i < dimension; i++)
		if (element(i, iCol) < min)
			min = element(i, iCol);
	return min;
}

int MatrixXnX::maxColumn(const int iCol) const
{
	int max = std::numeric_limits<int>::min();
	for (auto i = 0; i < dimension; i++)
		if (element(i, iCol) > max)
			max = element(i, iCol);
	return max;
}

int MatrixXnX::getDimension() const
{
	return dimension;
}
