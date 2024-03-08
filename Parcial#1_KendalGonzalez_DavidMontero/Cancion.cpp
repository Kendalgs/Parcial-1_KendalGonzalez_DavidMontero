#include "Cancion.h"
#include "sstring.h"

Cancion::Cancion(string nom, string art, int d) : nombre(nom), artista(art), duracion(d) {

}

Cancion::Cancion(const Cancion& orig) {
    this->nombre = orig.getNombre();
    this->artista = orig.getArtista();
    this->duracion = orig.getDuracion();
}

// Destructor por defecto
Cancion::~Cancion() {
}

Cancion::Cancion(ifstream& entrada1) {
    deserialize(entrada1, this);
}

bool Cancion::guardar(ofstream& salida1) {
    return serialize(salida1, (Cancion*)this);
}


void Cancion::deserialize(ifstream& entrada1, Cancion* c) {
    c->nombre = sstring::deserialize(entrada1);
    c->artista = sstring::deserialize(entrada1);
    c->duracion = sstring::deserializeInt(entrada1);

    if (!entrada1.good())
        throw - 1;
}

bool Cancion::serialize(ofstream& salida1, Cancion* u) {
    sstring::serialize(salida1, u->nombre);
    sstring::serialize(salida1, u->artista);
    sstring::serializeInt(salida1, u->duracion);
    return salida1.good();
}

void Cancion::setNombre(string n) {
    nombre = n;
}

void Cancion::setArtista(string tS) {
    artista = tS;
}

void Cancion::setDuracion(int tS) {
    duracion = tS;
}

string Cancion::getNombre() const {
    return this->nombre;
}

string Cancion::getArtista() const {
    return this->artista;
}

int Cancion::getDuracion() const {
    return this->duracion;
}

string Cancion::toString() const {
    stringstream r;
    r << GREEN << "Cancion:" << RESET << endl;
    r << "Nombre: " << this->getNombre() << endl;
    r << "Artista: " << this->getArtista() << endl;
    r << "Duracion: " << this->getDuracion() << endl;

    return r.str();
}
