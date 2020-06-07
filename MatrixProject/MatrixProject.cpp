#include "Matrix3x3.h"
#include "MatrixProject.h"
#include "MatrixXnX.h"
#include <iostream>

using namespace std;	

void StartFirst()
{
    Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);

    cout << "==============Static===============: " << endl;

    for (auto i = 0; i < matrix.getDimension(); i++)
    {
        for (auto j = 0; j < matrix.getDimension(); j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout << "Diag sum:" << endl;
    cout << " Principal: " << matrix.sumPrincipalDiag() << " Secondary: " << matrix.sumSecondaryDiag() << endl;
    cout << "Diag product:" << endl;
    cout << " Principal: " << matrix.productPrincipalDiag() << " Secondary: " << matrix.productSecondaryDiag() << endl;

    cout << "String 1 sum:" << matrix.sumRow(0) << endl;
    cout << "Column 1 max:" << matrix.maxColumn(0) << endl;
    cout << "Column 1 min:" << matrix.minColumn(0) << endl;
    cout << endl << endl;
}
void StartSecond()
{
    MatrixXnX matrix = MatrixXnX(4);
    matrix.fillRandomElements(-10, 10);
    cout << "===============Dynamic:=============== " << endl;
    for (int i = 0; i < matrix.getDimension(); i++)
    {
        for (int j = 0; j < matrix.getDimension(); j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout << "Diag sum:" << endl;
    cout << " Principal: " << matrix.sumPrincipalDiag() << " Secondary: " << matrix.sumSecondaryDiag() << endl;
    cout << "Diag product:" << endl;
    cout << " Principal: " << matrix.productPrincipalDiag() << " Secondary: " << matrix.productSecondaryDiag() << endl;

    cout << "String 1 sum:" << matrix.sumRow(0) << endl;
    cout << "Column 1 max:" << matrix.maxColumn(0) << endl;
    cout << "Column 1 min:" << matrix.minColumn(0) << endl;
}

int main()
{
    StartFirst();
    StartSecond();
	return 0;
}
