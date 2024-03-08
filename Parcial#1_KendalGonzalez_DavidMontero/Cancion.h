#ifndef CANCION_H
#define CANCION_H

#include "std.h"

class Cancion
{
    protected:
        string nombre;
        string artista;
        int duracion;

    public:
        Cancion(string = "", string = "", int = 0);
        Cancion(const Cancion& orig);
        virtual ~Cancion();
        Cancion(ifstream&);
        virtual bool guardar(ofstream&);
        static void deserialize(ifstream&, Cancion*);
        static bool serialize(ofstream&, Cancion*);

        virtual void setNombre(string);
        virtual void setArtista(string);
        virtual void setDuracion(int);
        virtual string getNombre() const;
        virtual string getArtista() const;
        virtual int getDuracion() const;
        virtual string toString() const;
    };

#endif // !CANCION_H