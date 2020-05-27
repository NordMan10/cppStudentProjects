#include "MatrixBase.h"

#pragma once

class Matrix3D : public MatrixBase
{
public:
	Matrix3D(unsigned int iSize);
	int element(unsigned int i, unsigned int j) const override;
	int& element(unsigned int i, unsigned int j) override;
};

