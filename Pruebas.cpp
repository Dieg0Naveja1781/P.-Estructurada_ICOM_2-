#include <iostream>
#include <vector>

int indice, num = 0;

std::vector<int> numbers = {4, 6, 3, 1, 8};

int mostrarValoresRecursivos()
{
    if (indice == 5)
    {
        return -1; // Final de la recursion.
    }
    else
    {
        std::cout << numbers[indice] << " ";
        indice++;
        return mostrarValoresRecursivos();
    }
}

int mostrarValoresRecursivos2(int i)
{
    if (i == 5)
    {
        return 1; // Se termina el bucle.
    }
    else
    {
        std::cout<< numbers[i]<< " ";

        return  mostrarValoresRecursivos2(i + 1);
    }
}

int agregarValores(int i)
{
    if (i == 5)
    {
        return 1; // Se termina el bucle.
    }
    else
    {
        std::cout<< "Ingrese un numero: \n";
        std::cin>> num;
        numbers[i] = num;

        std::cout<< numbers[i]<< " \n";

        return  agregarValores(i + 1);
    }
}

int main()
{
    mostrarValoresRecursivos2(indice);

    std::cout<< "\n-----------------------------------\n";

    mostrarValoresRecursivos();

    std::cout<< "\n-----------------------------------\n";

    indice = 0;
    agregarValores(indice);

    std::cout<< "\n-----------------------------------\n";

    indice = 0;
    mostrarValoresRecursivos2(0);
}