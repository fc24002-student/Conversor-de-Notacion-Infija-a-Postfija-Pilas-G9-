#include "Conversor.h"          // Incluye la declaracion de la clase Conversor
#include "pila.h"               // Incluye la implementacion de la pila generica
#include <cctype>               // Incluye funciones como isalnum e isspace

// helpers locales
namespace {                     // Namespace anonimo: funciones visibles solo en este archivo
    bool esOperador(char c) {   // Funcion que verifica si un caracter es un operador
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    }

    int precedencia(char op) {  // Funcion que devuelve la precedencia de un operador
        switch(op) {
            case '^': return 4; // Mayor precedencia: potencia
            case '*':           // Multiplicacion
            case '/': return 3; // Division
            case '+':           // Suma
            case '-': return 2; // Resta
            default: return 0;  // Cualquier otro caracter no tiene precedencia
        }
    }

    bool esAsociativoDerecha(char op) {  // Indica si un operador es asociativo a la derecha
        return op == '^';                // Solo la potencia es asociativa a la derecha
    }
}

std::string Conversor::infijaAPostfija(const std::string& expresion) {
    Pila<char> pila;                     // Pila para almacenar temporalmente operadores
    std::string salida;                 // Cadena donde se guardara la expresion postfija

    for (size_t i = 0; i < expresion.size(); ++i) {  // Recorre cada caracter de la expresion
        char c = expresion[i];                       // Obtiene el caracter actual

        if (std::isspace(static_cast<unsigned char>(c))) continue;
        // Si es un espacio en blanco, simplemente lo ignora

        if (std::isalnum(static_cast<unsigned char>(c))) {
            // Si es un operando (letra o numero), se agrega directo a la salida
            salida.push_back(c);
        }
        else if (c == '(') {
            // Si es un parentesis que abre, lo apilamos
            pila.push(c);
        }
        else if (c == ')') {
            // Si es un parentesis que cierra, desapilamos hasta encontrar '('
            while (!pila.vacia() && pila.top() != '(') {
                salida.push_back(pila.top());  // Agrega operador a la salida
                pila.pop();                    // Lo quita de la pila
            }
            if (!pila.vacia() && pila.top() == '(') pila.pop(); // Elimina el '('
        }
        else if (esOperador(c)) {
            // Si el caracter es un operador (+, -, *, /, ^)
            while (!pila.vacia() && esOperador(pila.top())) {   // Mientras el tope sea operador
                char tope = pila.top();                         // Operador en la pila
                int pTop = precedencia(tope);                   // Precedencia del operador en la pila
                int pCur = precedencia(c);                      // Precedencia del operador actual

                // Determina si se debe desapilar antes de apilar el nuevo
                if ((!esAsociativoDerecha(c) && pTop >= pCur) ||
                    (esAsociativoDerecha(c) && pTop > pCur)) {
                    salida.push_back(tope);     // Mueve operador a la salida
                    pila.pop();                 // Lo quita de la pila
                } else break;                   // Si no, terminamos el ciclo
            }
            pila.push(c);                       // Finalmente apila el operador actual
        }
        // Cualquier otro caracter se ignora
    }

    // Al terminar la expresion, desapilamos lo que quede
    while (!pila.vacia()) {
        if (pila.top() != '(') salida.push_back(pila.top()); // Evita parentesis no balanceados
        pila.pop();                                           // Desapila cada operador
    }

    return salida;   // Devuelve la expresion final en notacion postfija
}
