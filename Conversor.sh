#!/bin/bash

# DETECTA LA RUTA DONDE ESTA EL SCRIPT 
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# EJECUCION DEL PROGRAMA 
if [ -f "$DIR/build-linux/TestConversor" ]; then
    # EN ENTORNO DE DESARROLLO 
    xfce4-terminal --title="Conversor GP9 - Estructura de Datos" --working-directory="$DIR/build-linux" -e "./TestConversor"
else
    # INSTALADO EN EL SISTEMA EL .deb
    xfce4-terminal --title="Conversor GP9 - Infija a Postfija" -e "TestConversor"
fi
