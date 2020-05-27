#include <fstream>

#pragma once

class MatrixBase
{
public:
	MatrixBase() = delete;
	unsigned int size() const;
	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;
	void operator*=(int iMult);
	void operator+=(MatrixBase& iAdd);
protected:
	MatrixBase(unsigned int iSize);
	int* matrix;
private:
	const unsigned int m_size;
};

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix); // ��� ���� ����� ������� friend-������� ������?
