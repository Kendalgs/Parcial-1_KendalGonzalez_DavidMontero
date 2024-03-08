#include "listaPlaylist.h"
#include "Cancion.h"


//listaPlaylist::listaPlaylist() : lista<Cancion>() {}

listaPlaylist::~listaPlaylist() {
}

listaPlaylist::listaPlaylist(ifstream& entrada1) : lista<Cancion>() {
    deserialize(entrada1, this);
}

bool listaPlaylist::guardar(ofstream& salida1) {
    return serialize(salida1, (listaPlaylist*)this);
}


void listaPlaylist::deserialize(ifstream& entrada1, listaPlaylist* g) {
    int cantC = -1;
    int i = 0;
    entrada1.read((char*)&cantC, sizeof(cantC));

    while (entrada1.good() && i < cantC) {
        try {
            Cancion* can = NULL;

            if (!entrada1.good())
                throw - 1;

            can = new Cancion(entrada1);

            if (can != NULL)
                g->agregarFinal(can);
        }
        catch (int) {
            cout << "Ocurrió un error de lectura en el archivo" << endl;
        }
        i++;
    }
}


void listaPlaylist::eliminar(string nombre, string artista) {
    iterador<Cancion>* i = this->obtenerIterador();
    while (i->masElementos()) {
        Cancion* cancion = (Cancion*)i->proximoElemento();
        if (cancion != NULL && cancion->getNombre() == nombre) {
            // Si se encuentra una coincidencia en el nombre, verificar el nombre del artista
            if (cancion->getArtista() == artista) {
                // Eliminar la canción y salir del bucle
                i->eliminar();
                break;
            }
        }
    }
}

int listaPlaylist::duracionTotal() const {
    int duracionTotal = 0;
    iterador<Cancion>* i = this->obtenerIterador();
    while (i->masElementos()) {
        Cancion* cancion = (Cancion*)i->proximoElemento();
        if (cancion != nullptr) {
            // Sumar la duración de la canción actual a la duración total
            duracionTotal += cancion->getDuracion();
        }
    }
    return  duracionTotal
}


int listaPlaylist::totalCanciones() const {
    int cantCanciones = 0;
    iterador<Cancion>* i = this->obtenerIterador();
    while (i->masElementos()) {
        Cancion* can = (Cancion*)i->proximoElemento();

        if (can != NULL) {
            cantCanciones++;
        }
    }
    return cantCanciones;
}

bool listaPlaylist::serialize(ofstream& salida, listaPlaylist* g) {
    int cantPersonas = 0;
    iterador<Cancion>* i = g->obtenerIterador();
    cantPersonas = g->totalCanciones();

    salida.write((char*)&cantPersonas, sizeof(cantPersonas));

    while (i->masElementos() && salida.good()) {
        Cancion* can = (Cancion*)i->proximoElemento();
        can->guardar(salida);
    }
    return salida.good();
}

string listaPlaylist::toString() const {
    stringstream r;
    iterador<Cancion>* i = this->obtenerIterador();
    while (i->masElementos()) {
        Cancion* can = (Cancion*)i->proximoElemento();
        r << can->toString() << "\n";
    }
    return r.str();
}
