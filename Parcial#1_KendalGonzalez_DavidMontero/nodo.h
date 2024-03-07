#ifndef NODO_H
#define NODO_H

template <class T>
class nodo {
public:
    // Constructor que inicializa un nodo con la información dada y el siguiente nodo en la secuencia.
    nodo(T* nuevaInfo, nodo<T>* siguiente);

    // Destructor que se encarga de liberar los recursos asociados al nodo.
    virtual ~nodo();

    // Método para obtener la información almacenada en el nodo.
    virtual T* obtenerInfo() const;

    // Método para obtener el siguiente nodo en la secuencia.
    virtual nodo<T>* obtenerSiguiente() const;

    // Método para establecer el siguiente nodo en la secuencia.
    virtual void fijarSiguiente(nodo<T>* siguiente);

private:
    // Puntero a la información almacenada en el nodo.
    T* info;

    // Puntero al siguiente nodo en la secuencia.
    nodo<T>* siguiente;
};

// Implementación del constructor de la clase nodo.
template <class T>
nodo<T>::nodo(T* nuevaInfo, nodo<T>* siguiente) {
    info = nuevaInfo;
    this->siguiente = siguiente;
}

// Implementación del destructor de la clase nodo.
template <class T>
nodo<T>::~nodo() {
    // El destructor está vacío ya que no hay recursos adicionales para liberar.
}

// Implementación del método para obtener la información almacenada en el nodo.
template <class T>
T* nodo<T>::obtenerInfo() const {
    return info;
}

// Implementación del método para obtener el siguiente nodo en la secuencia.
template <class T>
nodo<T>* nodo<T>::obtenerSiguiente() const {
    return siguiente;
}

// Implementación del método para establecer el siguiente nodo en la secuencia.
template <class T>
void nodo<T>::fijarSiguiente(nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

#endif	/* NODO_H */
