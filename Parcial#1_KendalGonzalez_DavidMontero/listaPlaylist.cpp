#include "listaPlaylist.h"
#include "Cancion.h"


//listaPlaylist::listaPlaylist() : lista<Cancion>() {}

listaPlaylist::~listaPlaylist() {
}

listaPlaylist::listaPlaylist(ifstream& entrada) : lista<Cancion>() {
    deserialize(entrada, this);
}

bool listaPlaylist::guardar(ofstream& salida) {
    return serialize(salida, (listaPlaylist*)this);
}


void listaPlaylist::deserialize(ifstream& entrada, listaPlaylist* g) {
    int cantC = -1;
    int i = 0;
    entrada.read((char*)&cantC, sizeof(cantC));

    while (entrada.good() && i < cantC) {
        try {
            Cancion* can = NULL;

            if (!entrada.good())
                throw - 1;

            can = new Cancion(entrada);

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
    return  duracionTotal;
}

void listaPlaylist::eliminarExceso() {
    while (totalCanciones() > 10) {
        iterador<Cancion>* i = this->obtenerIterador();
        while (i->masElementos()) {
            Cancion* cancion = (Cancion*)i->proximoElemento();
            if (cancion != nullptr) {
                i->eliminar();
                delete cancion;
                break; // Elimina solo una canción por iteración
            }
        }
    }
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
