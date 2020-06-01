#include "Matrix3x3.h"
#include "MatrixProject.h"
#include "MatrixXnX.h"

using namespace std;	

void StartFirst()
{
    Matrix3x3 matrix;
    matrix.fillRandomElements(-10, 10);

    cout << "==============Static===============: " << endl;

    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout << "Diag sum:" << endl;
    cout << " Principal: " << matrix.sumPrincipalDiag() << " Secondary: " << matrix.sumSecondaryDiag() << endl;
    cout << "Diag product:" << endl;
    cout << " Principal: " << matrix.productPrincipalDiag() << " Secondary: " << matrix.productSecondaryDiag() << endl;

    cout << "String sum:" << endl;
    for (auto i = 0; i < 3; i++)
        cout << i + 1 << ": " << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (auto j = 0; j < 3; j++)
        cout << j + 1 << ": " << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (auto j = 0; j < 3; j++)
        cout << j + 1 << ": " << matrix.minColumn(j) << endl;
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

    cout << "String sum:" << endl;
    for (int i = 0; i < matrix.getDimension(); i++)
        cout << i + 1 << ": " << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (int j = 0; j < matrix.getDimension(); j++)
        cout << j + 1 << ": " << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (int j = 0; j < matrix.getDimension(); j++)
        cout << j + 1 << ": " << matrix.minColumn(j) << endl;
}

int main()
{
    StartFirst();
    StartSecond();
	return 0;
}
