#ifndef ITERADOR_H
#define	ITERADOR_H

// Definición de la plantilla de clase iterador
template <class T>
class iterador {
public:
    // Constructor por defecto
    iterador();
    // Destructor virtual
    virtual ~iterador();
    // Método virtual puro para verificar si hay más elementos
    virtual bool masElementos() const = 0;
    // Método virtual puro para obtener el próximo elemento
    virtual T* proximoElemento() = 0;

    virtual void eliminar() = 0;

};

// Implementación del constructor por defecto
template<class T>
iterador<T>::iterador() {
}

// Implementación del destructor
template<class T>
iterador<T>::~iterador() {
}

#endif	/* ITERADOR_H */
