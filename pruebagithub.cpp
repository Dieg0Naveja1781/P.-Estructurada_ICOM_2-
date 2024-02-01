#include <iostream>

int contador;
int a = 1, x;

int main ()
{
    for (int i = 0; i <= 50; i++)
    {
        std::cout<< "Contando... "<< i<< "\n";
    }
    
    std::cout<< "\n""Ahora con una variable global/local: ";

    for (contador = 0; contador <= 99; contador++)
    {
        std::cout<< "--> "<< contador<< "\n";
    }

    do
    {
        std::cout<< "Hola";
        ++contador;
        std::cout<< contador<<"\n";
        ++contador;
    } while (contador < 10);

    std::cout<< "\n""El valor de i es: "<<contador;

    x = contador + a;
    
}