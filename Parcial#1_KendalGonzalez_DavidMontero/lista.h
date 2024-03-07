#ifndef LISTA_H
#define	LISTA_H

#include "iteradorLista.h"
#include "nodo.h"
#include "contenedor.h"
#include "sstring.h"


template <class T>
class lista : public contenedor<T> {
public:
    // Constructor predeterminado
    lista();

    // Constructor de copia
    lista(const lista& orig);

    // Destructor
    virtual ~lista();

    // Métodos heredados de la clase contenedor
    virtual bool vacio() const;
    virtual int numElementos() const;
    virtual void agregar(T*);
    virtual void eliminar();
    virtual void agregarInicio(T*);
    virtual void agregarFinal(T*);
    virtual iterador<T>* obtenerIterador() const;
    virtual string toString() const;
    virtual bool guardar(ofstream&);

private:
    nodo<T>* primerNodo; // Puntero al primer nodo de la lista
    nodo<T>* ultimoNodo; // Puntero al último nodo de la lista
    int k;               // Contador de elementos en la lista
};

template<class T>
lista<T>::lista() {
    primerNodo = NULL;
    ultimoNodo = NULL;
    k = 0;
}

template<class T>
lista<T>::~lista() {
    // Destructor vacío ya que la liberación de memoria se maneja en otros métodos
}

template<class T>
bool lista<T>::vacio() const {
    return primerNodo == NULL;
}

template<class T>
int lista<T>::numElementos() const {
    return k;
}

template<class T>
void lista<T>::agregar(T* nuevaInfo) {
    // Cuando se agrega un elemento a una lista
    // que está inicialmente vacía, hay que fijar
    // el apuntador al último nodo.

    bool iniciandoLista = vacio();

    primerNodo = new nodo<T>(nuevaInfo, primerNodo);
    if (iniciandoLista) {
        ultimoNodo = primerNodo;
    }
    k++;
}

template<class T>
void lista<T>::eliminar() {
    // Elimina todos los elementos de la lista y libera la memoria
    if (!vacio()) {
        iterador<T>* i = obtenerIterador();
        while (i->masElementos()) {
            T* e = i->proximoElemento();
            delete e;
        }
        delete i;
    }
}

template<class T>
void lista<T>::agregarInicio(T* nuevaInfo) {
    // Agrega un elemento al inicio de la lista
    agregar(nuevaInfo);
}

template<class T>
void lista<T>::agregarFinal(T* nuevaInfo) {
    if (!vacio()) {
        // Si la lista no está vacía, la operación no afecta
        // al primer nodo, pero se debe actualizar el apuntador
        // al último nodo.

        ultimoNodo->fijarSiguiente(new nodo<T>(nuevaInfo, NULL));
        ultimoNodo = ultimoNodo->obtenerSiguiente();
        k++;

    }
    else {
        // Si la lista está vacía, agregar al inicio o
        // al final es la misma operación.
        agregar(nuevaInfo);
    }
}

template<class T>
iterador<T>* lista<T>::obtenerIterador() const {
    // Devuelve un iterador para recorrer la lista
    return new iteradorLista<T>(primerNodo);
}

template<class T>
string lista<T>::toString() const {
    // Convierte la lista a una cadena de texto
    stringstream r;
    nodo<T>* cursor = primerNodo;
    bool esPrimerElemento = true;
    while (cursor != NULL) {
        if (!esPrimerElemento) {
            r << "\n";
        }
        r << cursor->obtenerInfo()->toString();
        cursor = cursor->obtenerSiguiente();
        esPrimerElemento = false;
    }
    return r.str();
}

template<class T>
bool lista<T>::guardar(ofstream& salida) {
    nodo<T>* actual = primerNodo;
    while (actual != NULL) {
        salida << actual->obtenerInfo()->toString() << endl;
        actual = actual->obtenerSiguiente();
    }
    return salida.good();
}

#endif	/* LISTA_H */
