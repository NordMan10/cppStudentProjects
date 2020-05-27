#include "MatrixBase.h"

MatrixBase::MatrixBase(unsigned int iSize) : m_size(iSize) 
{
	matrix = new int[m_size * m_size];
};

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMult)
{
	for (auto i = 0; i < m_size * m_size; i++)
	{
		matrix[i] = matrix[i] * iMult;
	}
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (auto i = 0; i < m_size * m_size; i++)
	{
		matrix[i] = matrix[i] + iAdd.matrix[i];
	}
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	auto count = iMatrix.size();
	for (auto i = 0; i < count; i++)
	{
		for (auto j = 0; j < count; j++)
		{
			stream << iMatrix.element(i, j) << " ";
		}
		stream << std::endl;
	}
	return stream;
}