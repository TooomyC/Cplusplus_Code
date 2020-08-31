#ifndef PERSONAEXCEPTION_H
#define PERSONAEXCEPTION_H

#include <string>

#include <Cadena.h>
#include <Fecha.h>

using namespace std;

class PersonaException
{
   private:
		Cadena mensaje;

	public:
		FechaException(const Cadena& mensaje);

		const Cadena& getMensaje() const;
};

#endif // PERSONAEXCEPTION_H
