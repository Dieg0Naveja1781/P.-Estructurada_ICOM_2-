#include <iostream>
#include <stdlib.h>
#include <vector>

std::vector<char> conjunto1(5, ' '), conjunto2(5, ' ');
char elementoNuevo, elementoAleatorio, seguirModificando;

int i, j, elementosConjunto1, elementosConjunto2, indiceEditar, indiceBorrar = 0, minimoAleatorio = 33, limiteAleatorio =  126; // Establecimiento de los valores mínimos y límite del rango de números aleatorios;
int eleccionMenuPrin, eleccConjunto, eleccSubMenu2, cicloMenu;

void declararConjuntos()
{
    std::cout<< "-> Ingresa la cantidad maxima de elementos que tendra el primer conjunto. Minimo 5.\n";
     std::cin>> elementosConjunto1;
    while (elementosConjunto1 < 5)
    {
        std::cout<< "\nERROR. El conjunto debe tener al menos 5 elementos. Por favor, intentalo de nuevo: ";
        std::cout<< "--> ";
        std::cin>> elementosConjunto1;
    }
    
    std::cout<< "-> Ingresa la cantidad maxima de elementos que tendra el segundo conjunto. Minimo 5.\n";
     std::cin>> elementosConjunto2;
    while (elementosConjunto2 < 5)
    {
        std::cout<< "\nERROR. El conjunto debe tener al menos 5 elementos. Por favor, intentalo de nuevo: ";
        std::cout<< "--> ";
        std::cin>> elementosConjunto2;
    }

    conjunto1.resize(elementosConjunto1, ' ');
    conjunto2.resize(elementosConjunto2, ' '); 
}

int menuPrincipal()
{
    std::cout<< "\n********************************************************************\n";
    std::cout<< "\t\tMENU PRINCIPAL.\n";
    std::cout<< "Elige una de las opciones y presiona la tecla correspondiente. \n";
    std::cout<< "(1). Mostrar elementos de los Conjuntos. \n";
    std::cout<< "(2). Agregar, borrar o editar un elemento de un Conjunto. \n";
    std::cout<< "(3). Realizar operaciones de Conjuntos. \n";
    std::cout<< "(4). Vaciar todos los elementos de un Conjunto. \n";
    std::cout<< "(5). Salir del programa. \n";
    std::cout<< "********************************************************************\n";
    std::cout<< ">> ";
    std::cin>> eleccionMenuPrin;

    // Retorna la elección del usuario para ser evaluada
    return eleccionMenuPrin;
}

void mostrarElementosC1()
{
    std::cout<< "\nConjunto 1. \n";

    std::cout<< "\n---------------------------------------------------------------------------------\n";
    for ( i = 0; i < elementosConjunto1; i++)
    {
        std::cout<< i<< ". "<< "( "<< conjunto1[i]<< " )"<< " ";
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

void mostrarElementosC2()
{
    std::cout<< "\nConjunto 2. \n";

    std::cout<< "\n---------------------------------------------------------------------------------\n";
    for ( i = 0; i < elementosConjunto2; i++)
    {
        std::cout<< i<< ". "<< "( "<< conjunto2[i]<< " )"<< " ";
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

int elegirConjunto()
{
    do
    {
        std::cout<< "\n-------------------------------------------------------\n";
        std::cout<< "Elige el Conjunto y presiona el numero correspondiente: \n";
        std::cout<< "[1]: Conjunto 1 \n";
        std::cout<< "[2]: Conjunto 2 ";
        std::cout<< "\n-------------------------------------------------------\n";
        std::cout<< ">> ";
        std::cin>>eleccConjunto;
    
        // Evalúa la elección de usuario y muestra la matriz correspondiente
        switch (eleccConjunto)
        {
        case 1:
            mostrarElementosC1();
            break;

        case 2:
            mostrarElementosC2();
            break;
        
        default: 
            std::cout<< "\n""Opcion Incorecta. Por favor, intentalo de nuevo. \n";
            break;
        }
    } while(eleccConjunto != 1 && eleccConjunto != 2);

    // Retorna la opción del usuario para ser evaluada
    return eleccConjunto;
}

void agregarElementos()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Agregar elementos /-/-/-/-/-/-/-/-/-/-/-/\n";

    elegirConjunto();

    if (eleccConjunto == 1)
    {
        for ( i = 0; i < elementosConjunto1; i++)
        {
            std::cout<< "\n\n""Ingresa '0' para salir y regresar al menu.";
            std::cout<< "Ingresa un elemento --->> ";
            std::cin >> elementoNuevo;

            conjunto1.insert(conjunto1.begin() + i, elementoNuevo);

            // Evalúa si el usuario ingreso 0. Si cumple la condición regresa al menú
            if (elementoNuevo == '0')
            {
                i = elementosConjunto1;
            }
        }
    }
    else if (eleccConjunto == 2)
    {
        for ( i = 0; i < elementosConjunto2; i++)
        {
            std::cout<< "\n\n""Ingresa '0' para salir y regresar al menu.";
            std::cout<< "Ingresa un elemento --->> ";
            std::cin >> elementoNuevo;

            conjunto2.insert(conjunto2.begin() + i, elementoNuevo);

            // Evalúa si el usuario ingreso 0. Si cumple la condición regresa al menú
            if (elementoNuevo == '0')
            {
                i = elementosConjunto2;
            }
        }
    }
    else
    {
        std::cout<< "Opcion invalida.\n";
    }
}

void elementosAleatorios()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Agregar elementos Aleatorios /-/-/-/-/-/-/-/-/-/-/-/\n";

    // Llama la función para elegir un Conjunto
    elegirConjunto();

    std::cout<< "\nRellenando espacios... \n""Resultado: \n";

    switch (eleccConjunto)
    {
    case 1:
        for ( i = 0; i < elementosConjunto1; i++)
            {
                // Genera un caracter aleatorio siguiendo el código ASCII
                elementoAleatorio = minimoAleatorio + rand() % (limiteAleatorio - minimoAleatorio);

                // Si la posición actual de la Matriz no tiene un elemento ( ) se agrega el número aleatorio generado
                if (conjunto1[i] == ' ')
                {
                    conjunto1[i] = elementoAleatorio;
                }
            }

            mostrarElementosC1();
        break;

    case 2:
        for ( i = 0; i < elementosConjunto2; i++)
            {
                // Genera un caracter aleatorio siguiendo el código ASCII
                elementoAleatorio = minimoAleatorio + rand() % (limiteAleatorio - minimoAleatorio);

                // Si la posición actual de la Matriz no tiene un elemento ( ) se agrega el número aleatorio generado
                if (conjunto2[i] == ' ')
                {
                    conjunto2[i] = elementoAleatorio;
                }
            }

            mostrarElementosC2();
        break;
    
    default:
        std::cout<< "\nError! La opcion no es valida.\n";
        break;
    }
}

void editarElementos()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Editar elementos /-/-/-/-/-/-/-/-/-/-/-/\n";

    elegirConjunto();

    do
    {
        std::cout<< "Ingresa el indice del elemento a editar";
        std::cin>> indiceEditar;
        std::cout<< "Ingresa el nuevo elemento \n";
        /*std::cin>> elementoNuevo;*/

        if (eleccConjunto == 1)
        {
            std::cin>> conjunto1[indiceEditar];
        }
        else if (eleccConjunto == 2)
        {
            std::cin>> conjunto2[indiceEditar];
        }
        
        // Pregunta si quiere editar más valores
        std::cout<< "\n""Editar otro valor? S / N \n"">> ";
        std::cin>> seguirModificando;

    } while (seguirModificando == 'S' || seguirModificando == 's');
}

void borrarElementos()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Borrar elementos /-/-/-/-/-/-/-/-/-/-/-/\n";

    elegirConjunto();

    do
    {
        std::cout<< "\nEscribe el índice del elemento que deseas eliminar: ";
        std::cin >> indiceBorrar;

        if (eleccConjunto == 1)
        {
            conjunto1.erase(conjunto1.begin() + indiceBorrar);
        }
        else if (eleccConjunto == 2)
        {
            conjunto2.erase(conjunto2.begin() + indiceBorrar);
        }

        std::cout<< "Elemento eliminado. \n";

        std::cout<< conjunto1.size();

        // Pregunta si quiere seguir eliminando valores
        std::cout<< "\n""Eliminar otro valor? S / N \n"">> ";
        std::cin>> seguirModificando;
    } while (seguirModificando == 'S' || seguirModificando == 's');
    std::cout<<"\n--------------------------------------------------------------\n";
}

void subMenuOp2()
{
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Elige una opcion: \n";
    std::cout<< "1. Agregar elementos. \n";
    std::cout<< "2. Agregar elementos aleatorios. \n";
    std::cout<< "3. Editar elemento. \n";
    std::cout<< "4. Eliminar elemento.";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">> ";
    std::cin>> eleccSubMenu2;

    // Ejecuta la función correspondiente a cada opción del menú
    switch (eleccSubMenu2)
    {
    case 1:
        agregarElementos();
        break;

    case 2:
        elementosAleatorios();
        break;

    case 3:
        editarElementos();
        break;

    case 4:
        borrarElementos();
        break;
    
    default:
        std::cout<< "\nOpcion no valida, intentelo de nuevo. \n";
        break;
    }
}

void vaciarConjunto()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/-/ Vaciar Conjuntos /-/-/-/-/-/-/-/-/-/-/-/\n";

    elegirConjunto();

    std::cout<< "\n""Vaciando el conjunto...";

    if (eleccConjunto == 1)
    {
        conjunto1.clear();
    }
    else if (eleccConjunto == 2)
    {
        conjunto2.clear();
    }
}

void OpUnion()
{
    std::cout<< "\n/-/-/-/-/-/-/-/-/-/-/- Union -/-/-/-/-/-/-/-/-/-/-/\n";

    std::cout<< "Uniendo Conjuntos.\n";

    std::vector<char> conjuntoUnion(elementosConjunto1 + elementosConjunto2, ' ');

    for ( i = 0; i < elementosConjunto1; i++)
    {
        conjuntoUnion.insert(conjuntoUnion.begin() + i, conjunto1[i]);
    }
    for ( i = elementosConjunto1 + 1; i < elementosConjunto2; i++)
    {
        conjuntoUnion.insert(conjuntoUnion.begin() + i, conjunto2[j]);

        j = j + 1;
    }

    std::cout<< "Resultado: \n";

    std::cout<< "\n""Union.\n";

    std::cout<< "\n---------------------------------------------------------------------------------\n";
    for ( i = 0; i < elementosConjunto1 + elementosConjunto2; i++)
    {
        std::cout<< i<< ". "<< "( "<< conjuntoUnion[i]<< " )"<< " ";
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

void OpInterseccion()
{

}

void OpDiferencia()
{

}

void OpComplemento()
{

}

void menuOperaciones()
{
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< "Elige una opcion: \n";
    std::cout<< ".:1:. Union de Conjuntos. \n";
    std::cout<< ".:2:. Interseccion de Conjuntos. \n";
    std::cout<< ".:3:. Diferencia de Conjuntos. \n";
    std::cout<< ".:4:. Complemento de un Conjunto.";
    std::cout<< "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    std::cout<< ">> ";
    std::cin>> eleccSubMenu2;

    // Ejecuta la función correspondiente a cada opción del menú
    switch (eleccSubMenu2)
    {
    case 1:
        OpUnion();
        break;

    case 2:
        OpInterseccion();
        break;

    case 3:
        OpDiferencia();
        break;

    case 4:
        OpComplemento();
        break;
    
    default:
        std::cout<< "\nOpcion no valida, intentelo de nuevo. \n";
        break;
    }
}

int main()
{
    declararConjuntos();

    do
    {
        menuPrincipal();
        cicloMenu = 1;

        switch (eleccionMenuPrin)
        {
        case 1:
            mostrarElementosC1();
            mostrarElementosC2();
            break;

        case 2:
            subMenuOp2();
            break;

        case 3:
            menuOperaciones();
            break;

        case 4:
            vaciarConjunto();
            break;

        case 5:
            std::cout<< "Merengue --Dijo Emiliano";

            cicloMenu = 0;
            break;
        
        default:
            break;
        }
    } while (cicloMenu != 0);
}