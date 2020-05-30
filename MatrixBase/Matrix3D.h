#include "MatrixBase.h"

#pragma once

class Matrix3D : public MatrixBase
{
public:
	Matrix3D();
	int element(unsigned int i, unsigned int j) const override;
	int& element(unsigned int i, unsigned int j) override;
private:
	static const int size = 3;
	int matrix[size * size];
};
