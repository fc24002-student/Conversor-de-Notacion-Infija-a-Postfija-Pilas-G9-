#ifndef CONVERSOR_H    // Verifica que este archivo no se incluya dos veces en la compilacion
#define CONVERSOR_H    // Define la macro para evitar inclusiones multiples

#include <string>      // Incluye la libreria string para usar std::string

// Clase encargada de convertir de notacion infija a notacion postfija
class Conversor {
public:
    // Metodo publico que recibe una expresion infija y devuelve una postfija
    // Cada operando se considera un caracter alfanumerico
    std::string infijaAPostfija(const std::string& expresion);
};

#endif // CONVERSOR_H   // Fin de la proteccion contra inclusiones multiples
