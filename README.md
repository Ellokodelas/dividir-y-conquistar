Aqui se encuentran los codigos pedidos en el ramo algortimos y complejidad semestre 02-2024

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                            alumno: Emilio Valdebenito                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
--------------------------------------------------Funciones make-------------------------------------------------

        generadoras
    make generar   // genera listas
    make generar_m // genera matrices

        multiplicacion/ordenar
    make   // se ejecuta para ordenar listas
    make m // se ejecuta para multiplicar matrices

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
------------------------------------Requisitos para ejecutar el programa----------------------------------------

    1.Tener alguna terminal relacionada con linux(ejemplo: wsl)
    2.Tener un aproximado de 100 MB libre.
    3.Descargar los archivos en una carpeta separada y propia

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
-----------------------------Si se quiere cambiar las cualidades de las listas----------------------------------
    
    Para cambiar como quieres las listas solo entre a generador.cpp y en su main salgran los siguientes variables

    max_size                 // numero para generar listas de ese largo
    ordered_lists            // numero de listas ordenadas
    semi_ordered_lists       // numero de listas semi ordenadas
    unordered_lists          // numero de listas desordenadas

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
---------------------------Si se quiere cambiar las cualidades de las matrices----------------------------------
        Para cambiar como quieres las listas solo entre a generador_m.cpp y en su main salgran los siguientes
        variables.

        filas1
        columnas1 
        filas2
        columnas2 
        n_matrices
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
-----------------------------------------------Instrucciones----------------------------------------------------

1.Verificar si existen los archivos "dataset.txt"(listas) y "dataset_m.txt"(matrices), si no existen estas se tiene
que usar el comando "make generar" (listas) o "make generar_m"(matrices) dependiendo el que falte.

2.Usar el comando "make" o "make m" en la consola.

3.Seguir las instrucciones que te dará la consola

4.Revisar los resultados en "resultados.txt" o "resultados_m.txt"(opcional)
