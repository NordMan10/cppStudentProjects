#include "MatrixBase.h"

#pragma once

class Matrix2D : public MatrixBase
{
public:
	Matrix2D(unsigned int iSize);
	int element(unsigned int i, unsigned int j) const override;
	int& element(unsigned int i, unsigned int j) override;
};

