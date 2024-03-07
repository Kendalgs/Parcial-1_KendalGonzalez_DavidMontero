#include "listaPlaylist.h"

// Constructor
listaPlaylist::listaPlaylist(
	string listNombre,
	Usuario* listUsuario,
	Cancion* listCancion
) {
	setNombre(listNombre);
	setUsuario(listUsuario);
	setCancion(listCancion);
}

// Destructor
listaPlaylist::~listaPlaylist() { }

// Getters
string listaPlaylist::getNombre() { return Nombre; }
Usuario* listaPlaylist::getUsuario() { return _usuario; }
Cancion* listaPlaylist::getCancion() { return _cancion; }

// Setters
void listaPlaylist::setUsuario(Usuario* listUsuario) { _usuario = listUsuario; }
void listaPlaylist::setCancion(Cancion* listCancion) { _cancion = listCancion; }
void listaPlaylist::setNombre(string listNombre) { Nombre = listNombre; }

// Otros Metodos
string listaPlaylist::toString() const
{
	stringstream valor;

	valor << "--  Lista de Reproducción: " << Nombre << endl;
	valor << "--  Creado por: " << _usuario->getUsername() << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}

string listaPlaylist::archivoPlaylist()
{
	return string(Nombre + "/" + _usuario->getNombre() + "/" + _usuario->getUsername() + "/" + _usuario->getTipoSubscripcion() + "/" + _cancion->getNombre() + +"/" + _cancion->getArtista() + "/" + to_string(_cancion->getDuracion()));
}