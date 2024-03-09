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
        // Obtener un iterador para recorrer la lista de canciones
        iterador<Cancion>* i = this->obtenerIterador();
        while (i->masElementos()) {
            Cancion* cancion = (Cancion*)i->proximoElemento();
            if (cancion != nullptr) {
                // Eliminar la canción actual
                i->eliminarElemento();
                delete cancion;
                 // Salir del bucle para eliminar solo una canción por iteración
            }
        }
    }
}


void listaPlaylist::eliminarNombre(string nombre) {
    iterador<Cancion>* i = this->obtenerIterador();
    while (i->masElementos()) {
        Cancion* cancion = i->proximoElemento();
        if (cancion != nullptr && cancion->getNombre() == nombre) {
            // Si se encuentra una coincidencia en el nombre se elimina
            
            i->eliminarElemento();
            delete cancion;
            
            // Avanzar al siguiente elemento
            continue;
        }
    }
    delete i; // Liberar memoria del iterador
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
