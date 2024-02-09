/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 7/2/24
PROGRAMA: Serie de Fibonacci
Universidad De Guadalajara // Centro Universitario de los Altos // Ing. en Computación // 2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: El usuario ingresa un número para realizar la serie de Fibonacci hasta ese número o menor. Además de elegir con cual de los 3 ciclos lo ejecutará
----------------------- */

#include <iostream>

/* Variables  globales para usarlas en  las funciones */
int numeroIngresadoPorElUsuario, cicloElegidoPorElUsuario, decisionDelUsuario, numeroResultante, resultadoAnterior, contadorDelPrograma = 0;

/* Función para imprimir el número de la serie de Fibonacci siempre que cumpla la condición */
void comprobarValor()
{
    /* Evalúa la serie de Fibonacci para imprimir un número solamente si es menor o igual al del usuario */
    if (numeroResultante <= numeroIngresadoPorElUsuario)
    {
        std::cout<< numeroResultante<< "\n";
    }
}

/* Reestablece las variables a su valor inicial para evitar errores  en el siguiente uso */
void resetearVariables()
{
    numeroResultante = 0 + 1;
    resultadoAnterior = 0;
}

int main()
{
    /* Valores iniciales */
    numeroResultante = 0 + 1;


    /* Ciclo Do-while para repetir el programa hasta que el usuario  decida salir */
    do
    {
        /* Pide un número al usuario */
        std::cout<< "Ingresa un numero Entero";
        std::cout<< "\n"">> ";
        std::cin>> numeroIngresadoPorElUsuario;

        /* El usuario elige la condición a utilizar */
        std::cout<< "Que ciclo quieres utilizar?""\n""While: Oprime 1.""\n""Do-While: Oprime 2.""\n""For: Oprime 3.""\n";
            std::cin>> cicloElegidoPorElUsuario;
        
        /* Contador del programa */
        contadorDelPrograma = contadorDelPrograma + 1;

        std::cout<< "Comenzamos con 0 y 1""\n";

        /* Condicional switch para ejecutar el ciclo que el usuario haya elegido */
        switch (cicloElegidoPorElUsuario)
        {
            case 1:
                resetearVariables();

                while (numeroResultante <= numeroIngresadoPorElUsuario)
                {
                    /* Calcula la serie de Fibonacci sumando un numero con su anterior resultado */
                    resultadoAnterior =  numeroResultante - resultadoAnterior;

                    numeroResultante = numeroResultante + resultadoAnterior;

                    /* Antes de mostrar  un número en pantalla se evalúa si el número es menor al ingresado por el usuario */
                    comprobarValor();
                }
                
                break;

            case 2:
                resetearVariables();
                
                do
                {
                    /* Calcula la serie de Fibonacci sumando un numero con su anterior resultado */
                    resultadoAnterior =  numeroResultante - resultadoAnterior;

                    numeroResultante = numeroResultante + resultadoAnterior;

                    comprobarValor();

                } while (numeroResultante < numeroIngresadoPorElUsuario);

                break;

            case 3:
                resetearVariables();

                for (numeroResultante; numeroResultante <= numeroIngresadoPorElUsuario;)
                {
                    /* Calcula la serie de Fibonacci sumando un numero con su anterior resultado */
                    resultadoAnterior =  numeroResultante - resultadoAnterior;

                    numeroResultante = numeroResultante + resultadoAnterior;

                    comprobarValor();
                }
                
                break;
            
            default:    
                std::cout << "Error en el ingreso del ciclo. Ingrese una opción válida.""\n";

                break;
        }

        /* Pregunta al usuario si quiere volver a ejecutar el programa */
        std::cout<< "Volver a intentarlo?""\n""1: Si""\n""2: No""\n";
        std::cout<< ">>> ";
        std::cin>> decisionDelUsuario;
        std::cout<< "\n""************************************************************************""\n";

    } while (decisionDelUsuario != 2);

    /* Muestra las veces que se ha ejecutado el programa */
    std::cout<< "El programa se ejecuto "<< contadorDelPrograma<< " veces" "\n";
    
    std::cout<< "Bon appetite";
}