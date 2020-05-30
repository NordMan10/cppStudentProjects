#include "MatrixBase.h"

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMult)
{
	for (auto i = 0; i < m_size; i++)
		for (auto j = 0; j < m_size; j++)
			element(i, j) = element(i, j) * iMult;
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (auto i = 0; i < m_size; i++)
		for (auto j = 0; j < m_size; j++)
			element(i, j) = element(i, j) + iAdd.element(i, j);
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
