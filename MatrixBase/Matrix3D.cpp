#include "Matrix3D.h"

Matrix3D::Matrix3D(unsigned int iSize) : MatrixBase(iSize)
{
	auto count = size() * size();
	for (auto i = 0; i < count; i++)
	{
		matrix[i] = i + 1;
	}
};

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return matrix[i * size() + j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return matrix[i * size() + j];
}