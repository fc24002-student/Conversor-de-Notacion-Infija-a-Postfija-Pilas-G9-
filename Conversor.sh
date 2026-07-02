#!/bin/bash

# Detecta de forma segura la ruta real de esta carpeta sin importar los espacios
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Abre la terminal nativa de XFCE, se mete a build-linux y lanza el programa
xfce4-terminal --title="Conversor GP9 - Estructura de Datos" --working-directory="$DIR/build-linux" -e "./TestConversor"
