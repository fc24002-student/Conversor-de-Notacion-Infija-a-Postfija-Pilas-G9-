#ifndef PILA_H            // Evita que el archivo se incluya mas de una vez (directiva de inclusion unica)
#define PILA_H

// Pila generica implementada con lista enlazada (sin usar la STL)
template<typename T>     // La pila sera generica: podra almacenar cualquier tipo T
class Pila {
private:
    // Estructura interna que representa un nodo de la lista enlazada
    struct Nodo {
        T valor;                     // Valor almacenado en el nodo (dato generico)
        Nodo* siguiente;             // Puntero al siguiente nodo en la pila

        // Constructor del nodo: recibe un valor y un puntero al siguiente nodo
        Nodo(const T& v, Nodo* s = nullptr)
            : valor(v), siguiente(s) {}
    };

    Nodo* cima;           // Puntero al nodo superior de la pila (top)
    int cantidad;         // Cantidad de elementos almacenados en la pila

public:
    // Constructor: inicializa la pila vacia, con cima en nullptr y cantidad en 0
    Pila() : cima(nullptr), cantidad(0) {}

    // Destructor: libera memoria quitando todos los nodos de la pila
    ~Pila() {
        while (!vacia())  // Mientras la pila tenga elementos
            pop();        // Llama a pop() para eliminar uno por uno
    }

    // Inserta un elemento en la cima de la pila
    void push(const T& v) {
        Nodo* n = new Nodo(v, cima); // Crea un nuevo nodo con valor v, apuntando al nodo actual de la cima
        cima = n;                    // Ahora la cima es el nuevo nodo
        ++cantidad;                  // Incrementa el contador de elementos
    }

    // Elimina el elemento en la cima de la pila
    void pop() {
        if (cima) {                  // Verifica que la pila no este vacia
            Nodo* tmp = cima;        // Guarda el nodo actual de la cima
            cima = cima->siguiente;  // Avanza la cima al siguiente nodo
            delete tmp;              // Libera memoria del nodo eliminado
            --cantidad;              // Reduce la cantidad de elementos
        }
    }

    // Devuelve el elemento en la cima sin eliminarlo
    T top() const {
        return cima->valor;          // Retorna el valor almacenado en la cima
                                     // (Se asume que la pila NO esta vacia)
    }

    // Indica si la pila esta vacia
    bool vacia() const {
        return cima == nullptr;      // Retorna true si no hay nodos en la pila
    }

    // Devuelve la cantidad de elementos en la pila
    int size() const {
        return cantidad;             // Retorna el contador de elementos
    }
};

#endif // PILA_H           // Fin del include guard
