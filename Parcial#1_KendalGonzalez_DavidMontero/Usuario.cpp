#include "Usuario.h"
#include "sstring.h"

Usuario::Usuario(string nom, string tS) : nombre(nom), tipoSuscripcion(tS) {

}

Usuario::Usuario(const Usuario& orig) {
    this->nombre = orig.getNombre();
    this->tipoSuscripcion = orig.getTipoSuscripcion();
}

// Destructor por defecto
Usuario::~Usuario() {
}

Usuario::Usuario(ifstream& entrada1) {
    deserialize(entrada1, this);
}

bool Usuario::guardar(ofstream& salida1) {
    return serialize(salida1, (Usuario*)this);
}

void Usuario::deserialize(ifstream& entrada1, Usuario* u) {
    u->nombre = sstring::deserialize(entrada1);
    u->tipoSuscripcion = sstring::deserialize(entrada1);

    if (!entrada1.good())
        throw - 1;
}

bool Usuario::serialize(ofstream& salida1, Usuario* u) {
    sstring::serialize(salida1, u->nombre);
    sstring::serialize(salida1, u->tipoSuscripcion);
    return salida1.good();
}

void Usuario::setNombre(string n) {
    nombre = n;
}

void Usuario::setTipoSuscripcion(string tS) {
    tipoSuscripcion = tS;
}

string Usuario::getNombre() const {
    return this->nombre;
}

string Usuario::getTipoSuscripcion() const {
    return this->tipoSuscripcion;
}

string Usuario::toString() const {
    stringstream r;
    r << BOLDRED << "Usuario:" << RESET << endl;
    r << "Nombre: " << this->getNombre() << endl;

    r << "Tipo Suscripcion: " << this->getTipoSuscripcion() << endl;

    return r.str();
}
