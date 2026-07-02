#include <iostream>      // Permite usar cout y cin
#include <string>        // Para manejar cadenas
#include "Conversor.h"   // Incluye la clase Conversor
#include <limits>        // Para numeric_limits

// Funcion que muestra el menu en pantalla
void mostrarMenu() {
    std::cout << "\n===== MENU DEL CONVERSOR =====\n";
    std::cout << "1. Convertir expresion infija a postfija\n";
    std::cout << "2. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    Conversor conv;      // Crea un objeto de la clase Conversor
    int opcion = 0;      // Variable para almacenar la opcion del menu

    do {
        mostrarMenu();   // Muestra el menu al usuario
        
        // ✅ CÓDIGO CORREGIDO - Manejo seguro de entrada
        if (!(std::cin >> opcion)) {
            // Si la entrada falla (usuario ingresó letras)
            std::cin.clear(); // Limpia el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer
            std::cout << "Error: Por favor ingrese solo numeros (1 o 2).\n";
            continue; // Vuelve al inicio del bucle
        }
        
        std::cin.ignore(); // Limpia el salto de linea en el buffer

        // Opcion 1: convertir expresion
        if (opcion == 1) {
            std::string linea;
            std::cout << "Ingrese expresion infija: ";
            std::getline(std::cin, linea);      // Lee toda la expresion

            std::string post = conv.infijaAPostfija(linea); // Convierte la expresion
            std::cout << "Notacion postfija: " << post << "\n";
        }

        // Opcion 2: salir
        else if (opcion == 2) {
            std::cout << "Saliendo del programa...\n";
        }

        // Cualquier otra opcion es invalida
        else {
            std::cout << "Opcion no valida. Por favor ingrese 1 o 2.\n";
        }

    } while (opcion != 2);    // Repite hasta elegir salir

    return 0;    // Fin del programa
}