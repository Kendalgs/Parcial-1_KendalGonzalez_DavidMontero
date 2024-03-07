#ifndef CANCION_H
#define CANCION_H

#include "std.h"

class Cancion
{
protected:
	string Nombre;
	string Artista;
	int Duracion;

public:
	// Constructores
	Cancion();
	Cancion(
		string cNombre,
		string cArtista,
		int cDuracion
	);

	// Destructor
	~Cancion();

	// Getters
	string getNombre();
	string getArtista();
	int getDuracion();

	// Setters
	void setNombre(string cNombre);
	void setArtista(string cArtista);
	void setDuracion(int cDuracion);

	// Otros Metodos
	string toString() const;
};

#endif // !CANCION_H