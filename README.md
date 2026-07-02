# Conversor de Notación Infija a Postfijo (G9) 🚀

¡Aplicación nativa de consola optimizada para su distribución y uso en entornos GNU/Linux!

---

## 📦 Descargas y Versión Estable
Para instalar la última versión oficial en tu sistema sin necesidad de compilar código, ve directamente a la sección de lanzamientos o usa el siguiente botón de descarga:

[![Descargar Paquete .deb](https://img.shields.io/badge/Descargar-.deb-blue?style=for-the-badge&logo=linux&logoColor=white)](https://github.com/ing-jos-flores/conversorG9_linux/releases/latest)
[![Versión](https://img.shields.io/badge/Version-1.0.0--stable-green?style=for-the-badge)](https://github.com/ing-jos-flores/conversorG9_linux/releases)

---

## 📝 Introducción y Origen del Proyecto
En el ámbito de la ciencia de la computación, la evaluación de expresiones aritméticas requiere de un orden estricto de precedencia de operadores. Mientras que los seres humanos utilizamos la notación tradicional de manera intuitiva, los sistemas informáticos procesan estas operaciones de forma mucho más eficiente utilizando estructuras lineales optimizadas. 

### 👥 ¿Cómo nace este proyecto?
Este software tiene un origen académico. Nació inicialmente como un proyecto universitario grupal, donde nuestro equipo (**Grupo 9**) asumió el reto de diseñar y programar una **librería en C++** capaz de resolver la lógica de conversión infija a postfija empleando la estructura de datos de **Pilas**. Para esta etapa inicial, se trabajó la configuración y el desarrollo del código utilizando el entorno de **Visual Studio**, aprovechando sus herramientas para estructurar la lógica base.

Posteriormente, de forma personal, decidí retomar el proyecto con el objetivo de llevarlo más allá del entorno de desarrollo de la cátedra. Utilizando **CMake** como sistema fundamental para la configuración, generación e implementación limpia de la librería y del programa ejecutable, me encargué del diseño, adaptación e integración exclusiva para entornos **Linux**, optimizando su ejecución y construyendo de forma independiente el paquete instalador nativo **`.deb`** para simplificar su distribución al usuario final.

## 🎯 Objetivos del Proyecto
* **Objetivo General:** Desarrollar una aplicación nativa en C++ capaz de transformar expresiones aritméticas de formato convencional a su equivalente lógico optimizado, garantizando la integridad de los datos y el manejo de errores.
* **Objetivo Específico:**
  1. Implementar de forma estricta el tipo de dato abstracto **Pila (Stack)** para gestionar la precedencia de operadores aritméticos en una arquitectura modular.

---

## 🧠 Marco Teórico: ¿Qué es Notación Infija y Postfija?

* **Notación Infija (Humana):** Es la forma clásica en la que escribimos las matemáticas. Se caracteriza porque los operadores se colocan **entre** los operandos. 
  * *Ejemplo:* `A + B` o `(A + B) * C`

* **Notación Postfija o Polaca Inversa (Computacional):** Es una notación lineal donde los operadores se colocan **después** de sus operandos correspondientes.
  * *Ejemplo:* `A B +` o `A B + C *`
  * *Ventaja:* **No necesita paréntesis ni reglas de precedencia complejas.** La computadora la puede leer de izquierda a derecha en una sola pasada lineal, lo que ahorra ciclos de procesamiento y memoria, siendo el estándar utilizado por compiladores y calculadoras avanzadas.

---

## 🛠️ ¿Qué hace realmente el programa?

El programa actúa como un **compilador/intérprete en miniatura** especializado en aritmética. Al ejecutarlo, realiza el siguiente flujo lógico:

1. **Captura y Limpieza:** Recibe la cadena de texto con la expresión infija insertada por el usuario.
2. **Validación de Sintaxis:** Analiza la cadena para asegurar que los paréntesis abran y cierren correctamente y que no existan errores matemáticos de entrada.
3. **Algoritmo de Shunting-yard (Conversión):** Utiliza una **Pila (Stack)** interna. Los operandos pasan directo a la salida, mientras que los operadores (`+`, `-`, `*`, `/`) se almacenan temporalmente en la pila y se van liberando según su nivel de jerarquía e importancia matemática.
4. **Despliegue de Resultados:** Muestra en pantalla la conversión limpia en notación postfija lista para ser evaluada por una unidad aritmética.

---

## ✨ Características Principales de esta Versión
- **Estructuras de Datos Avanzadas:** Implementación estricta y eficiente de **Pilas** en C++.
- **Interfaz Interactiva:** Consola intuitiva con un sistema robusto de validación de expresiones y manejo de errores de entrada.
- **Script de Ejecución Inteligente:** Lanzador automatizado (`.sh`) adaptativo para entornos de desarrollo local y sistemas ya instalados.
- **Identidad Visual Propia:** Icono personalizado de transformación de datos en alta resolución (128px) integrado nativamente en el sistema.
- **Distribución Nativa:** Paquete instalador `.deb` optimizado para distribuciones basadas en Debian y Ubuntu (como Linux Mint).

---

## 📦 Instrucciones de Instalación:
1. Descarga el archivo `.deb` que se encuentra abajo en la sección de **Assets** de la Release o mediante el botón de descarga superior.
2. Haz doble clic sobre el paquete descargado e instálalo utilizando tu gestor gráfico predeterminado (como GDebi).
3. Abre el menú de aplicaciones de tu sistema, busca **"Conversor Infijo a Postfijo (G9)"** ¡y listo!
4. ¡Pruébalo y comparte tu opinión! Si encuentras algún fallo, tienes sugerencias de mejora o quieres dejar tu opinión, **¡abre un "Issue" aquí en el repositorio!** Tu feedback es fundamental para seguir puliendo el conversor. 🚀
