#pragma once
#include "std.h"
#include "lista.h"
#include "Cancion.h"


class listaPlaylist : public lista<Cancion> {
public:
    listaPlaylist();
    virtual ~listaPlaylist();
    listaPlaylist(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, listaPlaylist*);
    static bool serialize(ofstream&, listaPlaylist*);
    int totalCanciones() const;
    virtual string toString() const;
    void eliminar(string nombre, string artista);
    int duracionTotal() const;
    void eliminarExceso();
};



