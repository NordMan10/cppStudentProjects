#include "MatrixBase.h"

#pragma once

class Matrix2D : public MatrixBase
{
public:
	Matrix2D();
	int element(unsigned int i, unsigned int j) const override;
	int& element(unsigned int i, unsigned int j) override;
private:
	static const int size = 2;
	int matrix[size * size];
};
