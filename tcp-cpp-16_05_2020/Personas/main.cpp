#include <fstream>
#include <iostream>

#include "Empleado.h" //Esta al mismo nivel que el main

#define ARG_TXT_ENT 1
#define ARG_TXT_SAL 2

using namespace std;

int main(int argc, char* argv[])
{
    Empleado emp;

    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream empleadosAEnt(&fbEnt);

    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream empleadosASal(&fbSal);

    while(empleadosAEnt.peek() != EOF)
    {
        empleadosAEnt >> emp;
        emp.setSueldo(emp.getSueldo() * 1.30); //Subo un 30% el sueldo
       // empleadosAEnt.ignore[]; //Saca un caracter (enter) del buffer.
        empleadosASal << emp << endl;
    }

    fbEnt.close();
    fbSal.close();

    return 0;
}

