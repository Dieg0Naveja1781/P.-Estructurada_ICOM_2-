/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 21/2/24
PROGRAMA: Calculadora de Matrices
Universidad De Guadalajara // Centro Universitario de los Altos // Ing. en Computación // 2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: Super mega potente calculadora que permite que el usuario pueda crear sus propias Matrices, modificarlas a su gusto y realizar operaciones como suma, resta o multiplicación.
----------------------- */

#include <iostream> // Librería estándar de C++
#include <stdlib.h> // Librería para utilizar la función rand()


// Variables para la manipulación de Matrices
int numeroDeFilas1, numeroDeColumnas1, numeroDeFilas2, numeroDeColumnas2, contadorMatriz1, contadorMatriz2 = 0;
int h, i, j, eleccMatriz, filaAgregar, columnaAgregar, valorNuevo,filaEditar, columnaEditar, filaBorrar, columnaBorrar,
    sumaMatriz1, sumaMatriz2, resultadoMatriz, filaMultiplicar1, columnaMultiplicar1, filaMultiplicar2, columnaMultiplicar2 = 0;

// Variables para el manejo de menús  y opciones del usuario
int menu, eleccionMenuP, eleccAgregarValor, eleccMenuOP2, elccMenuOP3, eleccMultiplicacion, numerosAleatorios;
int minimoAleatorio = -100, limiteAleatorio =  100; // Establecimiento de los valores mínimos y límite del rango de números aleatorios
char seguirAgregando;   // Permite que el usuario decida si desea continuar agregando elementos a las Matrices o no

// Declaración de matrices con tamaño máximo de 10 filas y columnas
int matriz1[10][10], matriz2[10][10];

// Función para que el usuario defina el tamaño de las matrices
void declararMatrices()
{
    std::cout<< "\n*Por favor, indica la cantidad de filas y columnas que tendra la primera matriz. Minimo 2 filas y 2 columnas, maximo 10.* \n";
    std::cout<< "\n--> Filas: ";
    std::cin>> numeroDeFilas1;
    // Guarda la respuesta del usuario  en la variable 'numeroDeFilas1' y  verifica si cumple con el mínimo de filas
    while (numeroDeFilas1 < 2 || numeroDeFilas1 > 10)
    {
        // Si no cumple con la condición muestra un mensaje de error
        std::cout<< "\nERROR. La matriz debe tener al menos 2 filas y maximo 10. Por favor, intentalo de nuevo: ";
        std::cin>> numeroDeFilas1;
    }
    
    // Pide la cantidad de columnas y lo verifica
    std::cout<< "\n--> Columnas: ";
    std::cin>> numeroDeColumnas1;
    while (numeroDeColumnas1 < 2 || numeroDeColumnas1 > 10)
    {
        // Mensaje de error
        std::cout<< "\nERROR. La matriz debe tener al menos 2 columnas y maximo 10. Por favor, intentalo de nuevo: ";
        std::cin>> numeroDeColumnas1;
    }
    
    // Guarda los datos de la segunda matriz
    std::cout<< "\n*Por favor, indica la cantidad de filas y columnas que tendra la segunda matriz. Minimo 2 filas y 2 columnas, maximo 10.* \n";
    std::cout<< "--> Filas: ";
    std::cin>> numeroDeFilas2;
    // Verifica que cumpla con los requisitos
    while (numeroDeFilas2 < 2 || numeroDeFilas2 > 10)
    {
        std::cout<< "\nERROR. La matriz debe tener al menos 2 filas y maximo 10. Por favor, intentalo de nuevo: ";
        std::cin>> numeroDeFilas2;
    }

    // Guarda la cantidad de columnas
    std::cout<< "\n--> Columnas: ";
    std::cin>> numeroDeColumnas2;
    // Verifica que cumpla con los requisitos
    while (numeroDeColumnas2 < 2 || numeroDeColumnas2 > 10)
    {
        std::cout<< "\nERROR. La matriz debe tener al menos 2 columnas y maximo 10. Por favor, intentalo de nuevo: ";
        std::cin>> numeroDeColumnas2;
    }

    // Ciclo for que se encarga de llenar las filas de la Matriz 1
    for ( i = 0; i < numeroDeFilas1; i++) 
    {
        for ( j = 0; j < numeroDeColumnas1; j++) 
        {
            matriz1[i][j] = 0;
        }
    }

    // Ciclo for que llena la  Matriz 2
    for ( i = 0; i < numeroDeFilas2; i++) 
    {
        for ( j = 0; j < numeroDeColumnas2; j++) 
        {
            matriz2[i][j] = 0;
        }
    }
}

// Menu principal del programa
int menuPrincipal()
{
    std::cout<< "\n********************************************************************\n";
    std::cout<< "\t\tMENU PRINCIPAL.\n";
    std::cout<< "Elige una de las opciones y presiona la tecla correspondiente. \n";
    std::cout<< "1- Mostrar valores de las Matrices. \n";
    std::cout<< "2- Agregar, borrar o editar el valor de una Matriz. \n";
    std::cout<< "3- Sumar, restar o multiplicar Matrices. \n";
    std::cout<< "4- Vaciar todos los elementos de una Matriz. \n";
    std::cout<< "5- Salir del programa. \n";
    std::cout<< "********************************************************************\n";
    std::cout<< ">> ";
    std::cin>> eleccionMenuP;

    // Retorna la elección del usuario para ser evaluada
    return eleccionMenuP;
}

// Función par mostrar los valores de la Matriz 1
void mostrarValoresM1()
{
    std::cout<< "\nMatriz 1. \n";

    // Imprime los valores de la Matriz 1
    std::cout<< "\n---------------------------------------------------------------------------------\n";
    // La variable 'h' se utiliza para imprimir el índice de las columnas de la Matriz
    for ( h = 0; h < numeroDeColumnas1; h++)
    {
        std::cout<< "\t"<< h<< ".";
    }

    // La variable 'i' imprime las filas. 'j' imprime las columnas
    for ( i = 0; i < numeroDeFilas1; i++)
    {
        std::cout<< "\n("<< i<< "*) \t";

        for ( j = 0; j < numeroDeColumnas1; j++)
        {
            std::cout<< matriz1[i][j]<< "\t";
        }
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

// Función par mostrar los valores de la Matriz 2
void mostrarValoresM2()
{
    std::cout<<"\nMatriz 2.\n";

    // Imprime los valores de la Matriz 2
    std::cout<< "\n---------------------------------------------------------------------------------\n";
    // La variable 'h' se utiliza para imprimir el índice de las columnas de la Matriz
    for ( h = 0; h < numeroDeColumnas2; h++)
    {
        std::cout<< "\t"<< h<< ".";
    }

    // La variable 'i' imprime las filas. 'j' imprime las columnas
    for ( i = 0; i < numeroDeFilas2; i++)
    {
        std::cout<< "\n("<< i<< "*) \t";

        for ( j = 0; j < numeroDeColumnas2; j++)
        {
            std::cout<< matriz2[i][j]<< "\t";
        }
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

// Función para elegir una matriz cuando el programa lo requiera
int eleccionDeMatriz()
{
    do
    { 
        std::cout<< "\n-------------------------------------------------------\n";
        std::cout<< "Elige una matriz y presiona el numero correspondiente: \n";
        std::cout<< "[1]: Matriz 1 \n";
        std::cout<< "[2]: Matriz 2 ""\n-------------------------------------------------------\n";
        std::cout<< ">> ";
        std::cin>>eleccMatriz;
    
        // Evalúa la elección de usuario y muestra la matriz correspondiente
        switch (eleccMatriz)
        {
        case 1:
            mostrarValoresM1();
            break;

        case 2:
            mostrarValoresM2();
            break;
        
        default: 
            std::cout<< "\n""Opcion Incorecta. Por favor, intentalo de nuevo. \n";
            break;
        }
    } while(eleccMatriz != 1 && eleccMatriz != 2);

    // Retorna la opción del usuario para ser evaluada
    return eleccMatriz;
}

// Función que agrega valores a una Matriz
void agregarValores()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Agregar valores /-/-/-/-/-/-/-/-/-/-/-/\n";

    // LLama la función para elegir una Matriz
    eleccionDeMatriz();

    // El usuario puede elegir entre dos opciones para agregar los valores
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Deseas agregar valores segun sus coordenadas? o deseas agregar valores de manera secuencial?\n";
    std::cout<< "1. Agregar por coordenadas.\n";
    std::cout<< "2. Agregar por orden. (Fila-Columna)";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">>  ";
    std::cin>> eleccAgregarValor;
            
    // Según la opción que elija el usuario se agregan los valores
    if(eleccAgregarValor == 1)
    {
        // Se agregan valores hasta que el usuario decida salir
        do
        {
            std::cout<< "\n-----------Agregar por coordenadas-----------\n";

            std::cout<< "\n""Ingresa las coordenadas para agregar un valor. \n";
            std::cout<< "\n** Fila: ";
             std::cin>> filaAgregar;
            std::cout<< "\n** Columna: ";
             std::cin>> columnaAgregar;

            std::cout<< "\nIngresa el valor. \n"">> ";
            std::cin>> valorNuevo;

            // Agrega el valor a la Matriz que haya elegido el usuario
            if (eleccMatriz == 1)
            {
                matriz1[filaAgregar][columnaAgregar] = valorNuevo;
            }
            else if (eleccMatriz == 2)
            {
                matriz2[filaAgregar][columnaAgregar] = valorNuevo;
            }
            
            // Pregunta si quiere seguir agregando valores
            std::cout<< "\n""Agregar otro valor? S / N\n"">> ";
            std::cin>> seguirAgregando;
        } while (seguirAgregando == 'S' || seguirAgregando == 's');
        std::cout<<"\n--------------------------------------------------------------\n";
    }
    else if(eleccAgregarValor == 2)
    {
        std::cout<< "\n-----------Agregar por orden-----------\n";

        // Agrega los valores a la Matriz que haya elegido el usuario
        if (eleccMatriz == 1)
        {
            for ( i = 0; i < numeroDeFilas1; i++)
            {
                for ( j = 0; j < numeroDeColumnas1; j++)
                {
                    // Muestra la posición actual dode se gregará el valor
                    std::cout<< "\n""Estas en la fila "<< i<< ", columna "<< j;
                    std::cout<< "\n\n""Ingresa '0' para salir y regresar al menu.";
                    std::cout<< "\nIngresa el valor. \n"">> ";
                    std::cin>> valorNuevo;

                    matriz1[i][j] = valorNuevo;

                    // Evalúa si el usuario ingreso 0. Si cumple la condición regresa al menú
                    if (valorNuevo == 0)
                    {
                        i = numeroDeFilas1;
                        j = numeroDeColumnas1;
                    }
                }
            }
            std::cout<<"\n--------------------------------------------------------------\n";
        }
        else if (eleccMatriz == 2)
        {
            for ( i = 0; i < numeroDeFilas2; i++)
            {
                for ( j = 0; j < numeroDeColumnas2; j++)
                {
                    // Muestra la posición actual dode se gregará el valor
                    std::cout<< "\n""Estas en la fila "<< i<< ", columna "<< j;
                    std::cout<< "\n\n""Ingresa '0' para salir y regresar al menu.";
                    std::cout<< "\nIngresa el valor. \n"">> ";
                    std::cin >> valorNuevo;

                    matriz2[i][j] = valorNuevo;

                    // Evalúa si el usuario ingreso 0. Si cumple la condición regresa al menú
                    if (valorNuevo == 0)
                    {
                        i = numeroDeFilas2;
                        j = numeroDeColumnas2;
                    }
                }
            }
            std::cout<<"\n--------------------------------------------------------------\n";
        }       
    }
    else
    {
        std::cout<< "\nError. Opcion no valida\n";
    }
}

// Función que genera valores aleatorios a las matrices
void valoresAleatorios()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Agregar valores Aleatorios /-/-/-/-/-/-/-/-/-/-/-/\n";

    // Llama la función para elegir una Matriz
    eleccionDeMatriz();

    std::cout<< "\nRellenando espacios... \n""Resultado: \n";

    // Evalúa la eleccón del usuario y ejecuta la operación en la Matriz correspondiente
    switch (eleccMatriz)
    {
    case 1:
        for ( i = 0; i < numeroDeFilas1; i++)
        {
            for ( j = 0; j < numeroDeColumnas1; j++)
            {
                // Genera un número aleatorio entre -100 y 100
                numerosAleatorios = minimoAleatorio + rand() % (limiteAleatorio + 1 - minimoAleatorio);

                // Si la posición actual de la Matriz no tiene un elemento (0) se agrega el número aleatorio generado
                if (matriz1[i][j] == 0)
                {
                    matriz1[i][j] = numerosAleatorios;
                }
            }
        }

        mostrarValoresM1();
        
        break;

    case 2:
        for ( i = 0; i < numeroDeFilas2; i++)
        {
            for ( j = 0; j < numeroDeColumnas2; j++)
            {
                // Genera un número aleatorio entre -100 y 100
                numerosAleatorios = minimoAleatorio + rand() % (limiteAleatorio + 1 - minimoAleatorio);
                
                // Si la posición actual de la Matriz no tiene un elemento (0) se agrega el número aleatorio generado
                if (matriz2[i][j] == 0)
                {
                    matriz2[i][j] = numerosAleatorios;
                }
            }
        }

        mostrarValoresM2();

        break;
    
    default:
        std::cout<< "\nError! La opcion no es valida.\n";
        break;
    }
}

// Función para editar  los valores de la Matriz
void editarMatriz()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Editar valores /-/-/-/-/-/-/-/-/-/-/-/\n";

    // Llama la función para elegir una Matriz
    eleccionDeMatriz();

    do
    {
        // Pide los datos al usuario
        std::cout<< "\nElige la fila y columna del valor a editar. \n" ;
        std::cout<< "\n** Fila: ";
         std::cin>> filaEditar;
        std::cout<< "\n** Columna: ";
         std::cin>> columnaEditar;

        // Se ejecuta a operación en la Matriz que el usuario haya elegido
        if (eleccMatriz == 1)
        {
            std::cout<< "Ingresa el nuevo valor \n >> ";
            std::cin>> matriz1[filaEditar][columnaEditar];
        }   
        else if (eleccMatriz == 2)
        {
            std::cout<< "Ingresa el nuevo valor \n >> ";
            std::cin>> matriz2[filaEditar][columnaEditar];
        }

        // Pregunta si quiere editar más valores
        std::cout<< "\n""Editar otro valor? S / N \n"">> ";
        std::cin>> seguirAgregando;
    } while (seguirAgregando == 'S' || seguirAgregando == 's');
    std::cout<<"\n--------------------------------------------------------------\n";
}

// Función que elimina un elemento de una matriz
void eliminarValor()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Eliminar valores /-/-/-/-/-/-/-/-/-/-/-/\n";

    // LLama la función para elegir una Matriz
    eleccionDeMatriz();

    do
    {
        // Pide los datos al usuario
        std::cout<< "Escribe las coordenadas del valor que deseas eliminar. \n";
        std::cout<< "\n** Fila: ";
         std::cin>> filaBorrar;
        std::cout<< "\n** Columna: ";
         std::cin>> columnaBorrar;

        // Borra el elemento en la Matriz que el usuario eligió
        switch (eleccMatriz)
        {
        case 1:
            matriz1[filaBorrar][columnaBorrar] = 0;

            break;
        case 2:
            matriz2[filaBorrar][columnaBorrar] = 0;
        
        default:
            std::cout<< "Error, opcion no válida.\n";
            break;
        }

        std::cout<< "Elemento eliminado. \n";

        // Pregunta si quiere seguir eliminando valores
        std::cout<< "\n""Eliminar otro valor? S / N \n"">> ";
        std::cin>> seguirAgregando;
    } while (seguirAgregando == 'S' || seguirAgregando == 's');
    std::cout<<"\n--------------------------------------------------------------\n";
}

// Función que despliega un menú para la opción 2
void subMenuOp2()
{
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Elige una opcion: \n";
    std::cout<< "1. Agregar valor. \n";
    std::cout<< "2. Agregar valores aleatorios. \n";
    std::cout<< "3. Editar valor. \n";
    std::cout<< "4. Eliminar valor.";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">> ";
    std::cin>> eleccMenuOP2;

    // Ejecuta la función correspondiente a cada opción del menú
    switch (eleccMenuOP2)
    {
    case 1:
        agregarValores();
        break;

    case 2:
        valoresAleatorios();
        break;

    case 3:
        editarMatriz();
        break;

    case 4:
        eliminarValor();
        break;
    
    default:
        std::cout<< "\nOpcion no valida, intentelo de nuevo. \n";
        break;
    }  
}

// Funcion para sumar las Matrices
void sumaDeMatriz()
{
    std::cout<< "\n----------Suma de Matrices----------\n";

    sumaMatriz1 = 0, sumaMatriz2 = 0, resultadoMatriz = 0;

    // Ciclo que suma los elementos de la primera Matriz
    for ( i = 0; i < numeroDeFilas1; i++)
    {
        for ( j = 0; j < numeroDeColumnas1; j++)
        {
            sumaMatriz1 = matriz1[i][j] + sumaMatriz1;
        }
    }

    // Muestra el resultado
    std::cout<< "\nLa suma de los elementos de la primera matriz es: "<< sumaMatriz1<< "\n";

    // Ciclo que suma los elementos de la segunda Matriz
    for ( i = 0; i < numeroDeFilas2; i++)
    {
        for ( j = 0; j < numeroDeColumnas2; j++)
        {
            sumaMatriz2 = matriz2[i][j] + sumaMatriz2;
        }
    }

    // Muestra el resultado
    std::cout<< "\nLa suma de los elementos de la segunda matriz es: "<< sumaMatriz2<< "\n";

    resultadoMatriz = sumaMatriz1 + sumaMatriz2;

    // Muestra el resultado de la suma de ambas Matrices
    std::cout<<"\n--------------------------------------------------------------\n";
    std::cout<< "El resultado de la suma de las matrices es: "<< resultadoMatriz;
    std::cout<<"\n--------------------------------------------------------------\n";
}

// Función para restar las Mareices
void restaDeMatriz()
{
    std::cout<< "\n----------Resta de Matrices----------\n";

    sumaMatriz1 = 0, sumaMatriz2 = 0, resultadoMatriz = 0;
    
    // Ciclo que suma los elementos de la primera Matriz
    for ( i = 0; i < numeroDeFilas1; i++)
    {
        for ( j = 0; j < numeroDeColumnas1; j++)
        {
            sumaMatriz1 = matriz1[i][j] + sumaMatriz1;
        }
    }

    // Muestra el resultado de la primera Matriz
    std::cout<< "\nLa suma de los elementos de la primera matriz es: "<< sumaMatriz1<< "\n";

    // Ciclo que suma los elementos de la segunda Matriz
    for ( i = 0; i < numeroDeFilas2; i++)
    {
        for ( j = 0; j < numeroDeColumnas2; j++)
        {
            sumaMatriz2 = matriz2[i][j] + sumaMatriz2;
        }
    }

    // Muestra el resultado de la segunda Matriz
    std::cout<< "\nLa suma de los elementos de la segunda matriz es: "<< sumaMatriz2;

    resultadoMatriz = sumaMatriz1 - sumaMatriz2;

    // Muestra el resultado de la resta de ambas Matrices
    std::cout<<"\n--------------------------------------------------------------\n";
    std::cout<< "\nEl resultado de la resta de las matrices es: "<< resultadoMatriz;
    std::cout<<"\n--------------------------------------------------------------\n";
}

// Función para multiplicar las Matrices
void  multiplicacionDeMatriz()
{
    std::cout<< "\n----------Multiplicacion de Matrices----------\n";

    // Muestra las opciones al usuario
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Elige una opcion: \n";
    std::cout<< "1. Multiplicar elemento por elemento. \n";
    std::cout<< "2. Multiplicar fila por columna. \n";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">> ";
    std::cin>> eleccMultiplicacion;

    // Ejecuta la operación que eligió el usuario
    switch (eleccMultiplicacion)
    {
    case 1:
        resultadoMatriz = 0;

        mostrarValoresM1();

        // Pide los datos de la primera Matriz al usuario
        std::cout<< "\n""Ingresa las coordenadas del valor de la primera matriz. \n";
        std::cout<< "** Fila: ";
         std::cin >> filaMultiplicar1;
        std::cout << "\n** Columna: ";
         std::cin >> columnaMultiplicar1;

        mostrarValoresM2();

        // Pide los datos de la segunda Matriz al usuario
        std::cout<< "\n""Ingresa las coordenadas del valor de la segunda matriz. \n";
        std::cout<< "** Fila: ";
         std::cin >> filaMultiplicar2;
        std::cout << "\n** Columna: ";
         std::cin >> columnaMultiplicar2;

        // Multiplica los dos elementos
        resultadoMatriz =  matriz1[filaMultiplicar1][columnaMultiplicar1] * matriz2[filaMultiplicar2][columnaMultiplicar2];

        // Muestra el resultado de la multiplicación
        std::cout<<"\n--------------------------------------------------------------\n";
        std::cout<< "El resultado de la multiplicacion de "<< matriz1[filaMultiplicar1][columnaMultiplicar1]<< " por "<< matriz2[filaMultiplicar2][columnaMultiplicar2]<< " es: "<< resultadoMatriz;
        std::cout<<"\n--------------------------------------------------------------\n";
        break;

    case 2:
        // Verifica si es posible realizar la operación, en caso contrario muestra un mensaje y regresa al menú
        if (numeroDeColumnas1 == numeroDeFilas2)
        {
            std::cout<< "\nMultiplicando... \n";

            // Crea una nueva matriz para guardar la multiplicación
            int matrizResultante[numeroDeFilas1][numeroDeColumnas2];

            // Ciclo que multiplica las filas de la primera Matriz por las columnas de la segunda Matriz
            for ( i = 0; i < numeroDeFilas1; i++)
            {
                // La variable 'h' nos sirve para controlar las columnas que se van multiplicando y para ir guardando los resultados en las columnas correspondientes de la Matriz resultante
                for ( h = 0; h < numeroDeColumnas2; h++)
                {
                    // Reestablece el valor de la variable para evitar que siga conteniendo valores antiguos
                    resultadoMatriz = 0;

                    for ( j = 0; j < numeroDeFilas2; j++)
                    {
                        // Multiplica la fila de la Matriz 1 por todas las columnas de la Matriz 2. Y así sucesivamente
                        resultadoMatriz = resultadoMatriz + (matriz1[i][j] * matriz2[j][h]);
                    }
                    
                    // Guarda el resultado de la multiplicación en un espacio de la Matriz resultante
                    matrizResultante [i][h] = resultadoMatriz;
                }
            }
            
            std::cout<<"\n--------------------------------------------------------------\n";
            std::cout<< "Los resultados de la multiplicacion fila-columna son: \n";
            // Muestra los resultados en forma de lista
            for ( i = 0; i < numeroDeFilas1; i++)
            {
                for ( j = 0; j < numeroDeColumnas2; j++)
                {
                    std::cout<< "--. "<< matrizResultante[i][j]<< "\n";
                }
            }
            std::cout<<"--------------------------------------------------------------\n";
            std::cout<< "\nQue si los convertimos en una matriz quedaria: \n";

            // Muestra los resultados acomodados en una nueva Matriz            
            std::cout<< "\nMatriz Resultante. \n";

            std::cout<< "\n---------------------------------------------------------------------------------\n";
            for ( h = 0; h < numeroDeColumnas2; h++)
            {
                std::cout<< "\t"<< h<< ".";
            }

            for ( i = 0; i < numeroDeFilas1; i++)
            {
                std::cout<< "\n("<< i<< "*) \t";

                for ( j = 0; j < numeroDeColumnas2; j++)
                {
                    std::cout<< matrizResultante[i][j]<< "\t";
                }
            }
            std::cout<< "\n---------------------------------------------------------------------------------\n";
        }
        else
        {
            // Mnesaje de error en caso de que no sea posible mutiplicar las Matrices
            std::cout<< "\n""Ups. Parece que matematicamente nos posible multiplicar estas matrices de esta manera...\n";
        }
        break;
    
    default:
        std::cerr<< "Error! opcion  no valida.\n";
        break;
    }
}

// Muestra un menú para la opción 3
void subMenuOp3()
{
    // Muestra las operaciones y guarda la elección del usuario
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Elige una opcion: \n";
    std::cout<< "1. Sumar Matrices.\n";
    std::cout<< "2. Restar Matrices.\n";
    std::cout<< "3. Multiplicar Matrices.";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">> ";
    std::cin>> elccMenuOP3;

    // Realiza la operación que eligió el usuario
    switch (elccMenuOP3)
    {
    case 1:
        sumaDeMatriz();
        break;

    case 2:
        restaDeMatriz();
        break;

    case 3:
        multiplicacionDeMatriz();
        break;

    default:
        std::cerr << "\n""Error! Opcion no valida.\n";
        break;
    }
}

//Función para vaciar los elementos de una Matriz
void vaciarMatriz()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Vaciar Matriz /-/-/-/-/-/-/-/-/-/-/-/\n";

    // LLama la función para elegir una Matriz
    eleccionDeMatriz();

    std::cout<< "\nVaciando Matriz... \n";

    // Realiza la operación en la Matriz correspondiente
    switch (eleccMatriz)
    {
    case 1:
        // Ciclo que establece todos los valores de la Matriz en 0
        for (i = 0; i < numeroDeFilas1; i++)
        {
            for (j = 0; j < numeroDeColumnas1; j++)
            {
                matriz1[i][j] = 0;
            }
        }

        break;

    case 2:
        // Ciclo que establece todos los valores de la Matriz en 0
        for (i = 0; i < numeroDeFilas2; i++)
        {
            for (j = 0; j < numeroDeColumnas2; j++)
            {
                matriz2[i][j] = 0;
            }
        }
        break;
    
    default:
        std::cerr << "Error! No se ha seleccionado ninguna Matriz.\n";
        break;
    }
}

int main()
{
    // LLama la función para que el usuario elija las filas y columnas de ambas matrices.
    declararMatrices();

    // Ciclo que ejecuta el programa hasta que el usuario decidda salir
    do
    {
        // Muestra el menú
        menuPrincipal();
        // Establece la variable en 1 para que el programa se ejecute continuamente
        menu = 1;

        // Realiza las operaciones según lo elegido por el usuario
        switch (eleccionMenuP)
        {
        case 1:
            mostrarValoresM1();
            mostrarValoresM2();
            break;
        
        case 2:
            subMenuOp2();
            break;

        case 3:
            subMenuOp3();
            break;

        case 4:
            vaciarMatriz();
            break;

        case 5:
            // Muestra un mensaje de despedida y termina el programa
            std::cout<< "\n""No llores porque termino, sonrie porque llego a ocurrir. \n-Dr. Seuss""\n";
            // Establece la variable ne 0 para terminar el programa
            menu = 0;
            break;

        default:
            std::cout << "Opcion no valida.\n" ;
            break;
        }
    } while (menu != 0);
}