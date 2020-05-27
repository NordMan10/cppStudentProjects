#include <iostream>
#include "main.h"
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    Matrix2D m2a = Matrix2D(2);
    Matrix2D m2b = Matrix2D(2);
    Matrix3D m3a = Matrix3D(3);
    Matrix3D m3b = Matrix3D(3);

    m2a.operator+=(m2b);
    cout << "m2a + m2b: " << endl << m2a << endl;

    m2a.operator*=(10);
    cout << "(m2a + m2b) * 10: " << endl << m2a << endl;

    m2b.operator+=(m2a);
    cout << "m2b + (m2a + m2b) * 10: " << endl << m2b << endl;

    m2b.operator*=(10);
    cout << "m2b * 10: " << endl << m2b << endl;

    m3a.operator+=(m3b);
    cout << "m3a + m3b: " << endl << m3a << endl;

    m3a.operator*=(10);
    cout << "(m3a + m3b) * 10: " << endl << m3a << endl;

    m3b.operator+=(m3a);
    cout << "m3b + (m3a + m3b) * 10: " << endl << m3b << endl;

    m3b.operator*=(10);
    cout << "m3b * 10: " << endl << m3b << endl;


    return 0;
}