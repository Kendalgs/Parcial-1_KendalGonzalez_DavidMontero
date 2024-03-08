#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "std.h"
#include "utiles.h"
#include "listaPlaylist.h"



class interfaz
{
public:
	interfaz();
	virtual ~interfaz();
	virtual void mostrarOpciones();
	virtual int seleccionarOpcion();
	virtual void mostrarMenu();
private:
	listaPlaylist* _listaPlaylist;
	static const string archivo;


};

#endif

