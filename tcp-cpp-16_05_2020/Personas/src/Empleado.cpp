#include "Empleado.h"

Empleado::Empleado(int dni, const Cadena& apellido, const Cadena& nombres, const Fecha& fechaNac, char sexo, const Fecha& fechaIngr, const Fecha& fechaBaja, float sueldo)

:Persona(dni, apellido, nombres, fechaNac, sexo), fechaIngr(fechaIngr), fechaBaja(fechaBaja), sueldo(sueldo)
{
    ///VALIDAR LAS 3 VARIABLES ///OTRA FORMA DE LLAMAR AL CONSTRUCTOR
    //this->fechaIngr = fechaIngr; ///QUE NO SEA MENOR A LA FECHA NAC
    //this->fechaBaja = fechaBaja; ///QUE NO SEA MENOR A LA FECHA NAC

    if(sueldo < 0) ///QUE NO SEA NEGATIVO
        throw
}

const Fecha& Empleado::getFechaIngr() const
{
    return this->fechaIngr;
}

void Empleado::setFechaIngr(const Fecha& fechaIngr)
{
    this->fechaIngr = fechaIngr;
}

const Fecha& Empleado::getFechaBaja() const
{
    return this->fechaBaja;
}

void Empleado::setFechaBaja(const Fecha& fechaBaja)
{
    this->fechaBaja = fechaBaja;
}

float Empleado::getSueldo() const
{
    return this->sueldo;
}

void Empleado::setSueldo(float sueldo)
{
    this->sueldo = sueldo;
}

ostream& operator <<(ostream& sal, const Empleado& e)
{
   return sal << (Persona&)e << '|' << e.getFechaIngr() << '|' << e.getFechaBaja() << '|' << e.getSueldo();

}

istream& operator >>(istream& ent, Empleado& e)
{
    ent >> (Persona&)e;

    char buffer[TAM_BUFF];

    ent.getl ine(buffer, TAM_BUF, '|');
    e.setFechaIngr(buffer);

    ent.getline(buffer, TAM_BUF, '|');
    e.setFechaBaja(buffer);

///    int posStream = ent.tellg();

    ent.getline(buffer, TAM_BUF);

/*    if(ent.fail())
    {
        ent.seekg(posStream, ent.beg);
        ent.getline(buffer, TAM_BUF, '\n');
    }
*/
    e.setSueldo(atof(buffer));

    return ent;
}

