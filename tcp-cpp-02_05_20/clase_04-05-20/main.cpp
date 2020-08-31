#include <iostream>
#include <fstream>
#include "Fecha.h"
#include "FechaException.h"

using namespace std;

/**
{
    float a;

    cin >> a;

    cout << "El valor de a es:" << a << endl;


    try
    {
        Fecha fHoy(18,4,2020);
    }
    catch(FechaException& ex)
    {
        cout << ex.getMensaje() << endl;
        return 1;
    }



        Fecha fHoy(18,4,2020);


        Fecha fManiana(19,4,2020);
      //  fHoy.sumarDias(30);

        int d,m,a;

     //   (fHoy+=30).getDma(d,m,a);
      //  fHoy.operator+=(30);

      //  fHoy.getDma(d,m,a);
        cout <<"Fecha + 30: " << d << "/" << m << "/" << a << endl;

        Fecha fFinMayo(31,5,2020);
        fFinMayo.getDma(d,m,a);
        cout <<"Fecha Fin Mayo: " << d << "/" << m << "/" << a << endl;

        Fecha fFinAnio(31,12,2020);
        fFinAnio.getDma(d,m,a);
        cout <<"Fecha Fin Anio: " << d << "/" << m << "/" << a << endl;

        Fecha fSuma= fFinMayo+30;
        fSuma.getDma(d,m,a);
        cout <<"Fecha fin Mayo + 30 dias: " << d << "/" << m << "/" << a << endl;

    //   int dif= fHoy.diferencia(fManiana);
    //   cout << "Dia de la semana de hoy: " <<fHoy.diaDeLaSemana()<< endl;


     //   fhoy.sumarDias(30);
        const Fecha fConst(25,4,2020);
        fConst.sumarDias(30);


        return 0;
*/ ///HASTA ACA FUE LA CLASE DEL SABADO 25-04-2020

int main(int argc, char* argv[]) //CLASE DEL SABADO 02-05-2020
{
	if(argc != 2)
	{
		cout << "Cantidad de parámetros incorrecta" << endl;
		return 1;
	}

/**
    float a;

    cin >> a;

    cout << "El valor de a es: " << a << endl;
*/
/**
	try
	{
		Fecha fHoy(18, 4, 2020);
	}
	catch(FechaException& ex)
	{
		cout << ex.getMensaje() << endl;

		return 1;
	}

	Fecha fManiana(19, 4, 2020);

///	fHoy.sumarDias(30);

	int d, m, a;

///	(fHoy += 30).getDma(d, m, a);

///	fHoy.operator +=(30);

///	fHoy.getDma(d, m, a);

	cout << "Fecha + 30: " << d << '/' << m << '/' << a << endl;

	Fecha fFinMayo(31, 5, 2020);

	fFinMayo.getDma(d, m, a);

	cout << "Fecha Fin Mayo: " << d << '/' << m << '/' << a << endl;

	Fecha fFinAnio(31, 12, 2020);
	fFinAnio.getDma(d, m, a);
	cout << "Fecha Fin Anio: " << d << '/' << m << '/' << a << endl;

	Fecha fSuma = fFinMayo + 30;

	fSuma.getDma(d, m, a);

	cout << "Fecha fin Mayo + 30: " << d << '/' << m << '/' << a << endl;

//	int dif = fHoy.diferencia(fManiana);

//	cout << "Dia de la semana de hoy: " << fHoy.diaDeLaSemana() << endl;

///	fHoy.sumarDias(30);


	const Fecha fConst(25, 4, 2020);

	fConst.sumarDias(30);
*/

	try
	{
	/**
		Fecha fHoy(2, 5, 2020);

		Fecha fsuma = fHoy + 30;

		cout << fHoy << " + 30: " << fsuma << endl;

		fsuma = 30 + fHoy;

		cout << fHoy << " + 30: " << fsuma << endl;

		cout << "Ingrese una fecha:" << endl;
		cin >> fHoy;

		cout << "fHoy: " << fHoy << endl;
	*/

		filebuf fb;
		if(fb.open(argv[1], ios::in) == NULL) //ios::in ES PARA LECTURA
		{
			cout << "No se pudo abrir el archivo" << endl;
			return 3;
		}

		char enter;
		Fecha fLect;

		istream fechasA(&fb);

		cout << "Leyendo archivo " << argv[1] << ": " << endl;

		char peek; //METODO DEFINIDO PARA ARCHIVOS, TRAE PROXIMO CARACTER DEL FINAL DE ARCHIVO
		while((peek = fechasA.peek()) != EOF)
		{
			cout << "peek: " << peek << endl;
			fechasA >> fLect; //fLect = Fecha Lectura //SOBRECARGA DE OPERADOR MAYOR MAYOR, ES PARA INGRESAR DATOS DE UN ARCHIVO DESDE TECLADO, HACIA UNA VARIABLE.
			fechasA >> enter; //enter = \n
			cout << fLect << endl;
		}

		fb.close();
	}
	catch(FechaException& ex)
	{
		cout << ex.getMensaje() << endl;
		return 2;
	}




    return 0;
}

