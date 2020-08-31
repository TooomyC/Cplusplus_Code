#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona
{
    private:
        int dni;
        Cadena apellido:
        Cadena nombres;
        Fecha fechaNac;
        char sexo;

    public:
        Persona(int dni = 0, const Cadena& apellido = "", const Cadena& nombres= "", const Fecha& fechaNac = Fecha(1, 1, 1601), char sexo = ' '); //Hay que respetar el orden.

        int getDni(); //los getters no reciben parametros
        void setDni(int dni); //recibe el dato que tiene que setear

        const Cadena& getApellido() const; //Tiene que ser const para que no me la modifiquen
        void setApellido(const Cadena& apellido);

        const Cadena& getNombres() const ;
        void setNombres(const Cadena& nombres);

        const Fecha& getFechaNac() const;
        void setFechaNac(const Fecha& fechaNac);

        char getSexo() const;
        void setSexo(const sexo);

};

ostream& operator <<(ostream& sal, const Persona& p);
istream& operator >>(istream& ent, Persona& p);


#endif // PERSONA_H
