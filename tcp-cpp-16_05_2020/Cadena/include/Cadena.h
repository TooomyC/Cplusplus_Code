#ifndef CADENA_H
#define CADENA_H

#define TAM_BUF 501

#include <vector>
#include <iostream>

#include <Fecha.h>


using namespace std;


class Cadena
{
private:
	char* cad;

	Cadena(char* cad);

	int cantDigitos(int num);

public:
	Cadena(const char* cad = NULL);
    Cadena(int num); ///AGREGADO CLASE 23/05
    Cadena(const Fecha& f); ///AGREGADO CLASE 30/05

	///Sólo si utilizo memoria dinámica
	Cadena(const Cadena& otra); ///Constructor de copia
	~Cadena();
	Cadena& operator =(const Cadena& otra);

	Cadena operator +(const Cadena& cad2) const;
	///Cadena operator +(const char* cad2) const; ///AGREGADO CLASE 16/05
	///Cadena operator +(char car) const; ///AGREGADO CLASE 16/05
	Cadena& operator +=(const Cadena& cad2);
	char& operator [](int subindice); ///AGREGADO CLASE 23/05 //No es const por si se modifica

	Cadena subcadena(int inicio, int fin) const;
	void split(char separador, vector<Cadena>& vSubcads) const;
	int getCantCaracteres() const;

	Cadena normalizar() const;
	Cadena& normalizar();
	Cadena reemplazar(const Cadena& que, const Cadena& por) const;
    Cadena& reemplazar(const Cadena& que, const Cadena& por);

	///friend Cadena operator +(const char* cad1, const Cadena& cad2);
	///friend Cadea operator +(const char* cad1, const char* cad2); ///AGREGADO CLASE 23/05
	///friend Cadena operator +(char* car, const Cadena& cad2); ///AGREGADO CLASE 16/05

	friend ostream& operator <<(ostream& sal, const Cadena& cad);
	friend istream& operator >>(istream& ent, Cadena& cad);
};


#endif // CADENA_H
