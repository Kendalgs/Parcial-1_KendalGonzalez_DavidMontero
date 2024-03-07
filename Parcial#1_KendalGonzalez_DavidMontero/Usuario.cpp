#include "Usuario.h"

// Constructores
Usuario::Usuario() : Username("No definido"), Nombre("No definido"), TipoSubscripcion("No definido")
{ }
Usuario::Usuario(
	string uUsername,
	string uNombre,
	string uTipoSubscripcion
) {
	Username = uUsername;
	Nombre = uNombre;
	TipoSubscripcion = uTipoSubscripcion;
}

// Destructores
Usuario::~Usuario() { }

// Getters
string Usuario::getUsername() { return Username; }
string Usuario::getNombre() { return Nombre; }
string Usuario::getTipoSubscripcion() { return TipoSubscripcion; }

// Setters
void Usuario::setNombre(string uNombre) { Nombre = uNombre; }
void Usuario::setUsername(string uUsername) { Username = uUsername; }
void Usuario::setTipoSubscripcion(string uTipoSubscripcion) { TipoSubscripcion = uTipoSubscripcion; }

// Otros Metodos
string Usuario::toString() const
{
	stringstream valor;

	valor << "--  Username: " << Username << endl;
	valor << "--  Nombre: " << Nombre << endl;
	valor << "--  Tipo de Subscripcion: " << TipoSubscripcion << endl;
	valor << "----------------------------------------" << endl;

	return valor.str();
}

string Usuario::archivoUsuario()
{
	return string(Nombre + "/" + Username + "/" + TipoSubscripcion);
}