/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 21/2/24
PROGRAMA: Suma y modificación de Vectores
Universidad De Guadalajara // Centro Universitario de los Altos // Ing. en Computación // 2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: El usuario puede ingresar el tamaño del vector, llenarlo con números enteros y realizar operaciones matemáticas básicas sobre él (suma y modificación).
----------------------- */

#include <iostream> // Incluye la biblioteca estandar de C++

/* Declaramos las variables de tipo entero, caracter y el vector */
int i, menuPrincipal, eleccionMenu, eleccionOpcion1, posicionEditar, valorNuevo, posicionEliminar;
char eleccionOpcion1A, eleccionOpcion1B, eleccionOpcion1C; 
int sumaDeElementos, contador = 0;
int vectorPrincipal[10] = {};

/* Función para mostrar el menú principal del programa y guarda la respuesta del usuario */
int mostrarMenu()
{
  std::cout<< "\n""******************************************\n";
  std::cout<< "MENU PRINCIPAL""\n";
  std::cout<< "1. Mostrar lista de valores.""\n";
  std::cout<< "2. Agregar, editar o eliminar un valor.""\n";
  std::cout<< "3. Mostrar sumatoria de todos los elementos.""\n";
  std::cout<< "4. Vaciar el arreglo.""\n";
  std::cout<< "5. Salir del programa.""\n";
  std::cout<< "---------------------------------\n"<< ">> ";
    
  std::cin >> eleccionMenu;
  
  //Retorna la opción elegida por el usuario para evaluarla
  return eleccionMenu;
}

void mostrarValores()
{
  std::cout<< "\n Mostrando lista de los valores actuales: ""\n";

  // Ciclo para mostrar los valores actuales del vector. La variable contador sirve para imprimir en caso de que se eliminen valores
  for (int i = 0; i < 10 + contador; i++)
  {
    std::cout<< i<< ". "<< vectorPrincipal[i]<< "\n";
  }

}

// Función para mostrar un submenú que permite agregar, editar o eliminar un dato del vector
void subMenuOP2()
{
  std::cout<< "\n""******************************************\n";
  std::cout<< "Elige la operacion: ""\n";
  std::cout<< "1. Agregar un valor.""\n";
  std::cout<< "2. Editar un valor.""\n";
  std::cout<< "3. Eliminar un valor.""\n";
  std::cout<< "4. Regresar al menu anterior. ""\n";
  std::cout<< "---------------------------------\n"<< ">> ";
  
  std::cin>> eleccionOpcion1;

  // Ciclo para ejecutar la operación que desee el usuario
  switch (eleccionOpcion1)
  {
    case 1:
      std::cout<< "\n""------------Agregar un valor------------\n";
      
      // Ciclo que agrega un valor al vector. 
      for (i = 0; i < 10 + contador; i++)
      {
        std::cout<< "\n""Ingresa un valor : ";
        std::cin>> vectorPrincipal[i];

        // Pregunta al usuario para asegurarse de que ingrese todos los valores que desee hasta llegar al límite
        std::cout<<  "\n""Deseas agregar mas? S / N : ";
        std::cin>> eleccionOpcion1A;

        // Condicional para comprobar la respuesta del usuario y volver al menú en caso de que lo desee
        if (eleccionOpcion1A == 'N' ||  eleccionOpcion1A == 'n')
        {
          i = 10;
        }
      }

      // Mensaje que se muestra en caso de haber llenado todos los espcaios del Vector
      if (i == 10)
      {
        std::cout<< "\n Haz llenado todos los espacios disponibles de almacenamiento. Te sugerimos ver la lista de valores para una mejor comprension \n";
      }
      
      break;

    case 2:
      std::cout<< "\n""------------Editar un valor------------\n";

      do
      {
        // Llama la función para mostrar los valores disponibles para editar
        mostrarValores();

        // Pregunta el índice del dato que quiere editar y el valor nuevo
        std::cout<< "\n""Escribe el indice del valor que deseas editar: ";
        std::cin>> posicionEditar;

        std::cout<< "\n""Ingresa el nuevo valor: ";
        std::cin>> valorNuevo;

        // Asigna el nuevo valor a la posición indicada
        vectorPrincipal[posicionEditar] = valorNuevo;

        // Pregunta si desea seguir editando
        std::cout<< "\n Deseas editar otro valor? S / N : ";
        std::cin>> eleccionOpcion1B;

      } while (eleccionOpcion1B == 'S' || eleccionOpcion1B == 's');
      
      break;

    case 3:
      std::cout<< "\n""------------Eliminar un valor------------\n";

      do
      {
        // Llama la función para mostrar los valores disponibles para editar
        mostrarValores();

        std::cout<< "\n""Escribe el indice del valor que deseas eliminar: ";
        std::cin>> posicionEliminar;

        // Actualiza la variable contador para "omitir" el valor eliminado en las operaciones posteriores
        contador = contador - 1;

        // Ciclo que "elimina" el elemento de la posición indicada reorganizando el vector
        for (i = posicionEliminar; i < 10 + contador; i++)
        {
          vectorPrincipal[i] = vectorPrincipal[i+1];
        }

        // Le pregunta al usuario si quiere eliminar otro elemento
        std::cout<< "\n Eliminar otro valor? S / N : ";
        std::cin>> eleccionOpcion1C;

      } while (eleccionOpcion1C == 'S' || eleccionOpcion1C == 's');
      
      break;

    case 4:
      // Regresa al menú principal
      std::cout<< "\n Regresando al menu anterior...\n";

      break;
    
    default:
      // Mensaje de error en caso de eligir una opció incorrecta
      std::cout << "\n ERROR. Opcion no valida. Por favor, ingresa una opcion correcta \n";

      break;
  }
}

// Función para sumar todos los elementos del vector
void sumaDelVector()
{
  std::cout<< "\n""------------Suma de los elementos------------\n";

  // Ciclo para sumar todos los elementos del vector y mostrarlos por pantalla
  for (i = 0; i < 10 + contador; i++)
  {
    sumaDeElementos = sumaDeElementos + vectorPrincipal[i];

    std::cout<< vectorPrincipal[i]<< " + ";
  }

  std::cout<< "\n= " <<sumaDeElementos;
}

// Función para eliminar los elementos del vector
void vaciarVector()
{
  std::cout<< "\nVaciando el arreglo...\n";

  // Ciclo que vacía todos los elementos del vector
  for (i = 0; i < 10 + contador; i++)
  {
    vectorPrincipal[i] = 0;
  }
}

int main()
{
  // Ciclo principal del programa que llama las funciones según la opción elegida por el usuario
  do
  {
    mostrarMenu();
    //Establece la variable en 1 para siempre regresar al menú hasta que el usuario decida salir
    menuPrincipal = 1;

    switch (eleccionMenu)
    {
      case 1:
        mostrarValores();

        break;

      case 2:
        subMenuOP2();

        break;

      case 3:
        sumaDelVector();

        break;

      case 4:
        vaciarVector();

        break;

      case 5:
        std::cout<< "Saliendo del programa...\n";
        // Establece la variable en 2 para salir del programa
        menuPrincipal = 2;

        break;
      
      default:
        // Mensaje de error en caso de eligir una opció incorrecta
        std::cout << "ERROR. Opción no válida. Por favor, ingrese una opcion correcta. \n" ;

        break;
    }
  } while (menuPrincipal != 2);

  // Mensaje de despedida
  std::cout<< "Hasta pronto :D";  
}