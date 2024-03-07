#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "std.h"
#include "utiles.h"


class interfaz
{
public:
	interfaz();
	virtual ~interfaz();
	virtual void mostrarOpciones();
	virtual int seleccionarOpcion();
	virtual void mostrarMenu();
private:
	/*PersonaLibro* _PersonaLibro;
	persona* _persona;
	libro* _libro;
	static const string archivo;
	static const string archivo1;
	static const string archivo2;*/

};

#endif

