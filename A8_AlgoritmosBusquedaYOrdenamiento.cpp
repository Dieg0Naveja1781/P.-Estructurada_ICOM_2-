#include <iostream> // Incluye la biblioteca estandar de C++
#include <stdlib.h>
#include <vector>

/* Declaramos las variables de tipo entero, caracter y el vector */
int i, menuPrincipal, eleccionMenu, eleccionOpcion1, eleccionOpcion2, eleccionOpcion1_1, posicionEditar, valorNuevo, posicionEliminar, numeroAleatorio, sumaDeElementos, contador = 0;
bool ordenado =  false;
char eleccionOpcion1A, eleccionOpcion1B, eleccionOpcion1C; 
std::vector<int> vectorPrincipal(50, 0);

/* Función para mostrar el menú principal del programa y guarda la respuesta del usuario */
int mostrarMenu()
{
    std::cout<< "\n""******************************************\n";
    std::cout<< "\t\tMENU PRINCIPAL.""\n";
    std::cout<< "Elige una de las opciones y presiona la tecla correspondiente. \n\n";
    std::cout<< "1. Mostrar lista de valores.""\n";
    std::cout<< "2. Ordenar y buscar valores.""\n";
    std::cout<< "3. Agregar, editar o eliminar un valor.""\n";
    std::cout<< "4. Mostrar sumatoria de todos los elementos.""\n";
    std::cout<< "5. Vaciar el arreglo.""\n";
    std::cout<< "6. Salir del programa.""\n";
    std::cout<< "\n""******************************************\n";
    std::cout<< ">> ";
    std::cin>> eleccionMenu;
  
    //Retorna la opción elegida por el usuario para evaluarla
    return eleccionMenu;
}

void mostrarValores()
{
    std::cout<< "\n Mostrando lista de los valores actuales: ""\n";
    std::cout<< "\n---------------------------------------------------------------------------------\n";

    // Ciclo para mostrar los valores actuales del vector. La variable contador sirve para imprimir en caso de que se eliminen valores
    for (i = 0; i < 50 + contador; i++)
    {
      std::cout<< i<< ". "<< "( "<< vectorPrincipal[i]<< " )"<< " ";
    }
    std::cout<< "\n---------------------------------------------------------------------------------\n";
}

void bubbleSort(std::vector<int> &array)
{
  for (i = 0; i < 50 - 1; i++)
  {
    bool cambio = false;

    for (int j = 0; j < 50 - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
        cambio = true;
      }
    }

    if (cambio == false)
    {
      i = 50;
    }
  }
}

int particion(std::vector <int> &array, int eleMenor, int eleMayor)
{
  /*if (eleMenor == eleMayor)
  {
    return eleMenor;
  }*/
  
  int pivote = array[eleMayor - 1];  // tomamos el último elemento como pivote
  i = eleMenor - 1;
  int temporal;

  for (int j = 0; j < eleMayor; j++)
  {
    if (array[j] <= pivote)
    {
      temporal = array[i + 1];
      array[i + 1] = array[j];
      array[j] = temporal;
      i++;
    }
  }
  
  /* Intercambiamos el pivote co el último elemento más pequeño */
  temporal =  array[i + 1];
  array[i + 1] = array[eleMayor];
  array[eleMayor] = temporal;

  return i + 1;
}

void quickSort(std::vector<int> &array, int eleMenor, int eleMayor)
{
  std::cout<< "Hola.";
  if (eleMenor < eleMayor)
  {
    int piv = particion(array, eleMenor, eleMayor);
    
    quickSort(array, eleMenor, piv - 1);
    quickSort(array, piv + 1, eleMayor);
  }
  std::cout<< "Adios.";
}

bool ordenarArreglo()
{
  std::cout<< "\n""------------Ordenar------------\n";

  std::cout<< "Elige el metodo de ordenamiento.""\n";
  std::cout<< "[1]. Bubble Sort.\n";
  std::cout<< "[2]. Quick Sort.\n";
  std::cout<< ">> ";
  std::cin>> eleccionOpcion2;

  if (eleccionOpcion2 == 1)
  {
    bubbleSort(vectorPrincipal);
  }
  else if (eleccionOpcion2 == 2)
  {
    quickSort(vectorPrincipal, 0, 50);
    std::cout<< "\nCompletado.\n";
  }

  ordenado = true;

  std::cout<< "Resultado: \n";

  mostrarValores();

  return ordenado;
}

int busquedaBinaria(std::vector<int> &array, int eleBuscar, int eleMin, int eleMax)
{
  if (ordenado == false)
  {
    std::cout<< "\nERROR. El arreglo debe estar ordenado si quieres buscar un elemento en el. Por favor, ingresa la opcion 'ordenar' en la opcion 2.\n";
  }
  else if (ordenado == true)
  {
    while (eleMin <= eleMax)
    {
      int eleMedio = (eleMax - eleMin) / 2;

      if (array[eleMedio] == eleBuscar)
      {
        return eleMedio;
      }
      // Si el elemento a buscar es menor al medio del vector.
      else if (array[eleMedio] > eleBuscar)
      {
        eleMax = eleMedio -  1;
      }
      else 
      {
        eleMin = eleMedio +  1;
      }
    }
  }

  return -1;
}

void agregarValores()
{
  // Ciclo que agrega un valor al vector. 
  for (i = 0; i < 50 + contador; i++)
  {
    std::cout<< "\n""Ingresa un valor : ";
    std::cin>> vectorPrincipal[i];

    // Pregunta al usuario para asegurarse de que ingrese todos los valores que desee hasta llegar al límite
    std::cout<<  "\n""Deseas agregar mas? S / N : ";
    std::cin>> eleccionOpcion1A;

    // Condicional para comprobar la respuesta del usuario y volver al menú en caso de que lo desee
    if (eleccionOpcion1A == 'N' ||  eleccionOpcion1A == 'n')
    {
      i = 50;
    }
  }

  // Mensaje que se muestra en caso de haber llenado todos los espacios del Vector
  if (i == 50)
  {
    std::cout<< "\n Haz llenado todos los espacios disponibles de almacenamiento. Te sugerimos ver la lista de valores para una mejor comprension \n";
  }
}

void valoresAleatorios()
{
  std::cout<< "\nRellenando espacios... \n""Resultado: \n";

  for (i = 0; i < 50; i++)
  {
    numeroAleatorio = 1  + rand() % 201; /* Genera números aleatorios entre 1 y 200 */

    // Si la posición actual de la Matriz no tiene un elemento (0) se agrega el número aleatorio generado
    if (vectorPrincipal[i] == 0)
    {
      vectorPrincipal[i] = numeroAleatorio;
    }
  }

  mostrarValores();
}

void editarValores()
{
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
}

void eliminarValores()
{
  do
  {
    // Llama la función para mostrar los valores disponibles para editar
    mostrarValores();

    std::cout<< "\n""Escribe el indice del valor que deseas eliminar: ";
    std::cin>> posicionEliminar;

    // Actualiza la variable contador para "omitir" el valor eliminado en las operaciones posteriores
    contador = contador - 1;

    vectorPrincipal[posicionEditar] = 0;

    // Le pregunta al usuario si quiere eliminar otro elemento
    std::cout<< "\n Eliminar otro valor? S / N : ";
    std::cin>> eleccionOpcion1C;

  } while (eleccionOpcion1C == 'S' || eleccionOpcion1C == 's');
}

// Función para mostrar un submenú que permite agregar, editar o eliminar un dato del vector
void subMenuOP3()
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

      std::cout<< "1. Agregar valores uno por uno \n""2. Agregar valores aleatorios \n";
      std::cout<< ">> ";
      std::cin>> eleccionOpcion1_1;

      if (eleccionOpcion1_1 == 1)
      {
        agregarValores();
      }
      else if (eleccionOpcion1_1 == 2)
      {
        valoresAleatorios();
      }
      break;

    case 2:
      std::cout<< "\n""------------Editar un valor------------\n";
      editarValores();
      break;

    case 3:
      std::cout<< "\n""------------Eliminar un valor------------\n";
      eliminarValores();
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
  for (i = 0; i < 50 + contador; i++)
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

  // Función que vacía todos los elementos del vector
  vectorPrincipal.clear();
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
        std::cout<< "\n------------Ordenar y buscar valores------------\n";
        std::cout<< "Elige y presiona la tecla correspondiente: \n";
        std::cout<< "(1) Ordenar.\n";
        std::cout<< "(2) Buscar un valor.\n";
        std::cout<< ">> ";
        std::cin>> eleccionOpcion2;

        if (eleccionOpcion2 == 1)
        {
          ordenarArreglo();
        }
        else if (eleccionOpcion2 == 2)
        {
          std::cout<< "\n------------Buscar valores------------\n";

          std::cout<< "Ingrese el valor a buscar: \n";
          std::cout<< "Buscar ---> ";
          int valorBuscar;
          std::cin>> valorBuscar;

          int resultadoBusqueda = busquedaBinaria(vectorPrincipal, valorBuscar, 0, 50);

          if (resultadoBusqueda != -1)
          {
            std::cout<< "\nSe encontro el valor " << valorBuscar << " en la posicion " << resultadoBusqueda << ". \n";
            
            std::cout<< "\n---------------------------------------------------------------------------------\n";
            for (int i = 0; i < 50 + contador; i++)
            {
              if (vectorPrincipal[i] == valorBuscar)
              {
                std::cout<< "--> "<< i<< ". "<< "*( "<< vectorPrincipal[i]<< " )*"<< " <--"<<" ";
              }
              else
              {
                std::cout<< i<< ". "<< "( "<< vectorPrincipal[i]<< " )"<< " ";
              }
            }
            std::cout<< "\n---------------------------------------------------------------------------------\n";
          }
          else
          {
            std::cout<< "\nNo se encontro el valor ingresado. \n";
          }
        }

        break;

      case 3:
        subMenuOP3();

        break;

      case 4:
        sumaDelVector();

        break;

      case 5:
        vaciarVector();

        break;
      
      case 6:
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