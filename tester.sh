#!/bin/bash

LIBFT_PATH="../libft"
GNL_PATH="../gnl"


control = 0

#Prueba libft
# Verifica si el argumento es exactamente "-libft"
if [[ "$1" == "-libft" ]]; then
    # Verifica si el directorio existe -d
    if [ -d "$LIBFT_PATH" ]; then
		cd "$LIBFT_PATH"
    	echo -e "\n--Listado de $LIBFT_PATH--\n"
    	ls -la
    	echo -e "\n--Fin Listado--\n"
		echo -e "--Make--\n"
		make fclean
		echo
		make
		MAKE_OUTPUT=$(make re 2>&1)
		MAKE_OUTPUT=$(make 2>&1)
        if echo "$MAKE_OUTPUT" | grep -q "Nothing to be done for 'all'"; then
			echo
            echo -e "✅ No hay relink make -nobonus. \n"
			((control++))
        else
            echo -e "⚠️  Hay relink make -nobonus. \n"
            echo "$MAKE_OUTPUT"  # Muestra la salida completa de make
			echo
			((control--))
		fi

		if [[ "$2" == "-bonus" ]]; then
			make bonus
			MAKE_OUTPUT=$(make bonus 2>&1)
			if echo "$MAKE_OUTPUT" | grep -q "Nothing to be done for 'bonus'"; then
				echo
            	echo -e "✅ No hay relink make -bonus. \n"
				((control++))
        	else
				echo
            	echo -e "⚠️  Hay relink make -bonus. \n"
				echo "$MAKE_OUTPUT"
				echo
				((control--))
			fi
		fi
		echo -e "--Fin Make-- \n"
		cd - > /dev/null 2>&1
		
		cd libft
		echo "--Pruebas Main--"
		cc main.c -L../libft -lft
		if [[ $control == 2 ]]; then
			./a.out 2
		else
			if [[ $control == 1 ]]; then
			./a.out 1
			else
				echo "❌ Error relink❌"
			fi
		fi
    else
        echo "Error: El directorio 'libft' no existe."
        exit 1
    fi
    exit 0
else
    echo "Uso: $0 -libft || -libft -bonus"
fi



#Prueba get next line
if [[ "$1" == "-gnl" ]]; then
    # Verifica si el directorio existe -d
    if [ -d "$GNL_PATH" ]; then
        echo "Listado de $GNL_PATH:"
        ls -la $GNL_PATH
    else
        echo "Error: El directorio 'gnl' no existe."
        exit 1
    fi
    exit 0
else
    echo "Uso: $0 -gnl || -gnl -bonus"
	#Aqui para el programa borrar si quiero añadir otro
    exit 1
fi
