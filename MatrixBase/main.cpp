#include <iostream>
#include "main.h"
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    Matrix2D m2a;
    Matrix2D m2b;
    Matrix3D m3a;
    Matrix3D m3b;

    cout << "m2a: " << endl;
    cout << m2a << endl;
    cout << "m2b: " << endl;
    cout << m2b << endl;
    cout << "m3a: " << endl;
    cout << m3a << endl;
    cout << "m3b: " << endl;
    cout << m3b << endl;

    m2a += (m2b);
    cout << "m2a + m2b:" << endl;
    cout << m2a << endl;

    m2b *= (10);
    cout << "m2b * 10:" << endl;
    cout << m2b << endl;

    m3a += m3a;
    cout << "m3a + m3a:" << endl;
    cout << m3a << endl;

    m3b *= 4;
    cout << "m3a * 4:" << endl;
    cout << m3b << endl;
    
    return 0;
}
