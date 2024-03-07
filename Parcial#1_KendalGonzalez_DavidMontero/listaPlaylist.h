#ifndef LISTAPLAYLIST_H
#define LISTAPLAYLIST_H

#include "lista.h"
#include "Usuario.h"
#include "Cancion.h"

class listaPlaylist
{
protected:
	string Nombre;
	Cancion* _cancion;
	Usuario* _usuario;

public:
	// Constructor
	listaPlaylist(string listNombre, Usuario* listUsuario, Cancion* listCancion);

	// Destructor
	~listaPlaylist();

	// Getters
	string getNombre();
	Usuario* getUsuario();
	Cancion* getCancion();

	// Setters
	void setUsuario(Usuario* listUsuario);
	void setCancion(Cancion* listMusica);
	void setNombre(string listNombre);

	// Otros Metodos
	string toString() const;
	string archivoPlaylist();
};

#endif // !LISTAPLAYLIST_H