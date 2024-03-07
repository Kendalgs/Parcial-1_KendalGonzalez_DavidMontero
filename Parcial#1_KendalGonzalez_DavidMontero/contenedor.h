#ifndef CONTENEDOR_H
#define	CONTENEDOR_H

#include "std.h"
#include "iterador.h"

// Declaración de la plantilla de clase contenedor
template <class T>
class contenedor {
public:
    // Constructor por defecto
    contenedor();

    // Destructor virtual
    virtual ~contenedor();

    // Método virtual puro para verificar si el contenedor está vacío
    virtual bool vacio() const = 0;

    // Método virtual puro para obtener el número de elementos en el contenedor
    virtual int numElementos() const = 0;

    // Método virtual puro para agregar un elemento al contenedor
    virtual void agregar(T*) = 0;

    // Método virtual puro para eliminar un elemento del contenedor
    virtual void eliminar() = 0;

    // Método virtual puro para agregar un elemento al inicio del contenedor
    virtual void agregarInicio(T*) = 0;

    // Método virtual puro para agregar un elemento al final del contenedor
    virtual void agregarFinal(T*) = 0;

    // Método virtual puro para obtener un iterador del contenedor
    virtual iterador<T>* obtenerIterador() const = 0;

    // Método virtual puro para obtener una representación en cadena del contenedor
    virtual string toString() const = 0;
};

// Implementación del constructor por defecto de la clase contenedor
template<class T>
contenedor<T>::contenedor() {
}

// Implementación del destructor virtual de la clase contenedor
template<class T>
contenedor<T>::~contenedor() {
}

#endif	/* CONTENEDOR_H */
