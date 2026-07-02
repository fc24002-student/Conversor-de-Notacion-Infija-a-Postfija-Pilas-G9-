#!/bin/bash

# DETECTA LA RUTA DONDE ESTA EL SCRIPT 
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# EJECUCION DEL PROGRAMA 
if [ -f "$DIR/build-linux/TestConversor" ]; then
    # EN ENTORNO DE DESARROLLO 
    cd "$DIR/build-linux"
    ./TestConversor
else
    # INSTALADO EN EL SISTEMA MEDIANTE EL .deb
    # A EATAR EN /usr/bin, SE INVOCA Y ABRE DIRECTAMENTE 
    TestConversor
fi

# PAUSA UNIVERSAL EVITA QYE SE CIERRE CUALQUIER TERMINAL QUE EL USUARIO ESTE USANDO EN UN MILISEGUNDO
echo ""
echo "------------------------------------------------"
echo -n "Proceso finalizado. Presione [Enter] para salir..."

# BUCLE PARA QUE SOLO ACEPTE EN ENTER DEL USUARIO Y NO OTROS CARACTERES DONDE SI DETECTA QUE EL CARACTER NO ES UN SALTO DE LINEA ENTER LO IGNORARA Y SEGUIRA ESPERANDO EL ENTER
while read -r -s -N 1 char; do
    if [[ "$char" == $'\n' || "$char" == "" ]]; then
        break
    fi
done
