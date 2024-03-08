#ifndef CANCION_H
#define CANCION_H

#include "std.h"

class Usuario
{
protected:
    string nombre;
    string tipoSuscripcion;

public:
    Usuario(string = "", string = "");
    Usuario(const Usuario& orig);
    virtual ~Usuario();
    Usuario(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, Usuario*);
    static bool serialize(ofstream&, Usuario*);

    virtual void setNombre(string);
    virtual void setTipoSuscripcion(string);
    virtual string getNombre() const;
    virtual string getTipoSuscripcion() const;
    virtual string toString() const;
};

#endif // !CANCION_H