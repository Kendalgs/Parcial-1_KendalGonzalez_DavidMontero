#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H

#include "std.h"
#include "iterador.h"
#include "nodo.h"

template <class T>
class iteradorLista : public iterador<T> {
public:
    // Constructor que recibe el primer nodo como parámetro
    iteradorLista(nodo<T>* primerNodo);

    // Destructor virtual
    virtual ~iteradorLista();

    // Método que verifica si hay más elementos en la lista
    virtual bool masElementos() const;

    // Método que devuelve el próximo elemento en la lista
    virtual T* proximoElemento();

    virtual void eliminarElemento();

private:
    // Puntero al nodo actual en la lista
    nodo<T>* cursor;
    nodo<T>* inicio;
};


template <class T>
void iteradorLista<T>::eliminarElemento() {
    if (cursor != nullptr) {
        // Guardamos una referencia al nodo anterior para poder actualizar sus enlaces
        nodo<T>* anterior = nullptr;

        // Recorremos la lista hasta encontrar el nodo actual
        nodo<T>* actual = this->inicio;
            while (actual != nullptr && actual != cursor) {
                anterior = actual;
                actual = actual->obtenerSiguiente();
            }

        // Si encontramos el nodo actual
        if (actual == cursor) {
            // Actualizamos los enlaces para eliminar el nodo
            if (anterior != nullptr) {
                anterior->fijarSiguiente(actual->obtenerSiguiente());
            }
            else {
                this->inicio = actual->obtenerSiguiente();
            }
            delete actual;
        }
    }
}


template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primerNodo) : iterador<T>() {
    // Inicializa el puntero al primer nodo
    cursor = primerNodo;
}

template <class T>
bool iteradorLista<T>::masElementos() const {
    // Verifica si el cursor apunta a un nodo válido
    return (cursor != NULL);
}

template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = NULL;
    // Verifica si hay más elementos en la lista
    if (masElementos()) {
        // Obtiene la información del nodo actual y avanza al siguiente nodo
        r = cursor->obtenerInfo();
        cursor = cursor->obtenerSiguiente();
    }
    return r;
}

template <class T>
iteradorLista<T>::~iteradorLista() {
    // No se realiza ninguna operación en el destructor por el momento
}

#endif	/* ITERADORLISTA_H */
