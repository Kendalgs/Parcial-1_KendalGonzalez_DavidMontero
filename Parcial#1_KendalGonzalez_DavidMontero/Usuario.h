#ifndef USUARIO_H
#define USUARIO_H

#include "std.h"

class Usuario
{
protected:
	string Username;
	string Nombre;
	string TipoSubscripcion;

public:
	// Constructores
	Usuario();
	Usuario(
		string uUsername,
		string uNombre,
		string uTipoSubscripcion
	);

	// Destructor
	~Usuario();

	// Getters
	string getUsername();
	string getNombre();
	string getTipoSubscripcion();

	// Setters
	void setUsername(string uUsername);
	void setNombre(string uNombre);
	void setTipoSubscripcion(string uTipoSubscripcion);

	// Otros Metodos
	string toString() const;
	string archivoUsuario();
};

#endif // !USUARIO_H