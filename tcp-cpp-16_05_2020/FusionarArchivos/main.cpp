#include <fstream>
#include <iostream>
#include <Cadena.h>

#define ARG_TXT_ENT_1 1
#define ARG_TXT_ENT_2 2
#define ARG_TXT_SAL 3

#define TODO_OK 0
#define ERROR_ARCH 1

using namespace std;

int main(int argc, char* argv[])
{
/*    ///TODO: Validar cantidad de argumentos (argc y argv).

    //Cadena hola("Hola");
    //const Cadena& cad = Cadena("Hola");

    filebuf fbEnt1;
    if(!fbEnt1.open(argv[ARG_TXT_ENT_1], ios::in))
    {
        cout << Cadena("Error abriendo archivo 1") + (const char*)argv[ARG_TXT_ENT_1] << endl; ///Se castea el argv porque no es constante.
        return ERROR_ARCH;
    }

    istream archEnt1(&fbEnt1);

    filebuf fbEnt2;
    if(!fbEnt2.open(argv[ARG_TXT_ENT_2], ios::in))
    {
        cout << "Error abriendo archivo 2" << argv[ARG_TXT_ENT_2] << endl;
        return ERROR_ARCH;
    }

    istream archEnt2(&fbEnt2); ///ISTREAM PARA ESCRIBIR

    filebuf fbSal;
    if(!fbSal.open(argv[ARG_TXT_SAL], ios::in))
    {
        cout << "Error abriendo archivo 3" << argv[ARG_TXT_SAL] << endl;
        return ERROR_ARCH;
    }

    ostream archSal(&fbSal); ///OSTREAM PARA LEER

    Cadena linea1, linea2;
    Cadena lineaConcat;

    while(archEnt1.peek() != EOF && archEnt2.peek() != EOF) ///El metodo/funcion Peek devuelve el proxima caracter del archivo. Si no hay caracter, devuelve la constante del EOF (End Of File)
    {
        archEnt1 >> linea1;
        archEnt2 >> linea2;

        lineaConcat = linea1 + "|" + linea2;
        archSal << lineaConcat;
    }

    fbEnt1.close();
    fbEnt2.close();
    fbSal.close();
*/

Cadena cad("233423434|Perez|Juan|12/3/2009|M");

vector <cadena> vCampos;
cad.split ('|', vCampos);

for(vector<Cadena>::iterator i = vCampos.begin(); i < vCampos.end(); i++) //El metodo begin devuelve un iterador, que esta apuntando al primer elemento del vector o lista.
{
    cout << *i << endl; ///Imprime todos los campos.
}


return 0;
}
