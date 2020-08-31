#include <iostream>
#include "FechaException.h"
#include "Fecha.h"

using namespace std;


const int Fecha::matAcumDias[2][12] =
{/// E  F   M   A    M    J    J    A    S    O    N    D
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, ///A�o no bisiesto
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335} ///A�o bisiesto
};
///Dia del a�o: 160 --> 160 - 151 = 9 => dia: 9, mes: 6
///Dia del a�o: 151 --> 151 - 120 = 31 => dia: 31, mes: 5


Fecha::Fecha(int diaRel)
{
	if(diaRel <= 0)
		throw FechaException("La fecha es inferior a la minima admitida (1/1/1601)");

	this->diaRel = diaRel;
}


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
	///TODO: pasar dma a diaRel.

	if(!esFechaValida(dia, mes, anio))
	{
		throw FechaException("La fecha es invalida");
	}

	this->diaRel = dmaADiaRel(dia, mes, anio);
}

Fecha::Fecha(const char* fechaStr)
{
    int dia, mes, anio;

    sscanf(fechaStr, "%d/%d/%d", &dia, &mes, &anio);

	if(!esFechaValida(dia, mes, anio))
	{
		throw FechaException("La fecha es invalida");
	}

	this->diaRel = dmaADiaRel(dia, mes, anio);
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
    static int dias [2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                        {31,29,31,30,31,30,31,31,30,31,30,31}};

        if(anio>9999 || anio<0)
            return 0;
        if(mes>12)
            return 0;

        if((anio%4==0 && anio%100!=0 ) || anio%400==0)
        {
            if(dia > dias[1][(mes)-1])
                return 0;
        }
        else
        {
            if(dia > dias[0][(mes)-1])
                return 0;
        }

	return true;

}


int Fecha::dmaADiaRel(int dia, int mes, int anio)
{
	int cantAnios = anio - 1601;
	int diaRelativo = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400 + diaDelAnio(dia, mes, anio);
	return diaRelativo;
}


void Fecha::getDma(int& dia, int& mes, int& anio) const
{
	int cantAnios = this->diaRel / 365;

	int diaRelCalc = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;

	while(diaRelCalc >= this->diaRel)
	{
		cantAnios--;
		diaRelCalc = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	}

	anio = 1601 + cantAnios;

	int diaDelAnio = this->diaRel - diaRelCalc;

	int filaAcum = esBisiesto(anio)? 1 : 0;

	mes = 0;

	while(diaDelAnio > matAcumDias[filaAcum][mes])
	{
		mes++;
	}

	dia = diaDelAnio - matAcumDias[filaAcum][mes-1];
}


int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return matAcumDias[esBisiesto(anio)? 1 : 0][mes-1] + dia; //DEVUELVE CUANTOS DIAS TRANSCURRIERON DESDE ENERO HASTA LA FECHA INGRESADA
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha suma(this->diaRel + dias);
	return suma;
}


void Fecha::sumarDias(int dias)
{
	this->diaRel += dias;
}


Fecha& Fecha::operator +=(int dias)
{
	this->diaRel += dias;
	return *this;
}


Fecha Fecha::operator +(int dias) const
{
	Fecha suma(this->diaRel + dias);
	return suma;
}


/*
int Fecha::diaDeLaSemana()
{
	return 0;
}
int Fecha::diferencia(Fecha f)
{
	return this->diaRel - f.diaRel;
}
*/


Fecha operator +(int dias, const Fecha& f)
{
	Fecha suma(f.diaRel + dias);
	return suma;
}

bool ::Fechoperator >(const Fecha& f2) const
{
    return this->diaRel > f2.diaRel;
}

ostream& operator <<(ostream& sal, const Fecha& f)
{
	int d, m, a;
	f.getDma(d, m, a);
	sal << d << '/' << m << '/' << a;
	return sal;
}


istream& operator >>(istream& ent, Fecha& f)
{
	int d, m, a;
	char c;

	ent >> d >> c >> m >> c >> a;

	if(!Fecha::esFechaValida(d, m, a))
		throw FechaException("La fecha ingresada es inv�lida");

	f.diaRel = Fecha::dmaADiaRel(d, m, a);

	return ent;
}
