// Titulo..: programa sobrecarga01.cpp
// Objetivo: demostración de sobrecarga de operadores

#include <iostream>
using namespace std;

class Pareja {
public:
    double a, b;

    // constructor parametrizado
    Pareja(const double a,const double b)
    {
        this->a = a;
        this->b = b;
    }
};

// Sobrecarga del operador +
Pareja& operator +(const Pareja &p1,const Pareja &p2)
{
  return *(new Pareja(p1.a + p2.a, p1.b + p2.b) );
}

int main()
{
    Pareja A(50, 75 );
    Pareja B(150, 175 );
    Pareja C = A + B;

    cout << "A = " << A.a << ',' << A.b << "\n";
    cout << "B = " << B.a << ',' << B.b << "\n";
    cout << "C = " << C.a << ',' << C.b << "\n";

    return 0;

}
