#include <iostream>
#include <vector>

int particion(std::vector<int> &vector, int min, int max) 
{
    // Si el rango es de un solo elemento, la partición es trivial.
    if (min == max) return min;
    
    /* La variable 'p' se utiliza para llevar el puntero a la posición en donde se va a insertar el próximo elemento */
    /*
        Encuentra el pivot elegido entre los dos extremos del rango.
        El pivot se puede elegir como el último o el primer elemento del rango,
        pero en este caso lo elegimos como el último para que sea más fácil verificar
        si una parte de la lista está ordenada. Esto no afecta al algoritmo ya que
        cualquier elemento podría ser elegido como pivot.
    */
    int pivote = vector[max];
    int i = min - 1;

    for (int j = min; j < max; j++)
    {
        if (vector[j] <= pivote)
        {
            int temp =  vector[i + 1];
            vector[i + 1] = vector[j];
            vector[j] = temp;
            i++;
        } 
    }
    
    int temp = vector[i + 1];
    vector[i + 1] = vector[max];
    vector[max] = temp;

    return i + 1;
}

void quickSort(std::vector<int> &vector, int min, int max)
{
    if (min < max)
    {
        int pivot = particion(vector, min, max);

        quickSort(vector, min, pivot - 1);
        quickSort(vector, pivot +  1, max);
    } 
}

int main()
{
    std::vector<int> juanito = {5, 43, 6, 42, 7, 3, 89, 3, 120, 4, 104, 75, 92, 14, 162, 168, 184, 67, 122, 90, 30, 20, 83, 12, 32, 13, 42, 50, 89, 34};

    for (int i = 0; i < 30; i++)
    {
        std::cout<< juanito[i] << " ";
    }
    std::cout<< "\n-----------------------------------\n";

    quickSort(juanito, 0, 30);

    for (int i = 0; i < 30; i++)
    {
        std::cout<< juanito[i] << " ";
    }

    
}
