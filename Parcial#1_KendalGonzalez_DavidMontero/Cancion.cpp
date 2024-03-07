#include "Cancion.h"

// Constructores
Cancion::Cancion() : Nombre("No definido"), Artista("No definido"), Duracion(0){}

Cancion::Cancion(
	string cNombre,
	string cArtista,
	int cDuracion
) {
	Nombre = cNombre;
	Artista = cArtista;
	Duracion = cDuracion;
}

// Destructor
Cancion::~Cancion() { }

// Getters
string Cancion::getNombre() { return Nombre; }
string Cancion::getArtista() { return Artista; }
int Cancion::getDuracion() { return Duracion; }

// Setters
void Cancion::setNombre(string cNombre) { Nombre = cNombre; }
void Cancion::setArtista(string cArtista) { Artista = cArtista; }
void Cancion::setDuracion(int cDuracion) { Duracion = cDuracion; }

string Cancion::toString() const
{
	stringstream valor;

	valor << "--  Nombre de Canción: " << Nombre << endl;
	valor << "--  Artista: " << Artista << endl;
	valor << "--  Duración: " << Duracion << " segundos" << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}