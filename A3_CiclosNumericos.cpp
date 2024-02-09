/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 2/2/24
PROGRAMA: Ciclos Numericos
Universidad De Guadalajara//Centro Universitario de los Altos//Ing. en Computación//2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: El usuario ingresa un número y dependiendo de cual ingrese se imprimirá una serie de numeros de 5 en 5 o 10 en 10
----------------------- */

#include <stdio.h>

int validar (int d)
{
    do
    {
        if (d < 0)
        {
            printf("ERROR. Ingresa solo numeros enteros. Intentalo de nuevo.""\n");
            printf(">>> ");
                fflush(stdin);
                scanf("%i", &d);
        }
        
    } while (d < 0);
    
    return d;
}

int main ()
{
    /* Variables locales */
    int numeroDelUsuario, eleccionDelUsuario, controlDeCinco, controlDeDiez, cuentaDePrograma = 0;

    /* ciclo do-while que ejecuta todo el programa mientras el usuario no ingrese el 2 */
    do
    {
        /* Contador para registrar las veces que se ejecuta el programa */
        cuentaDePrograma = cuentaDePrograma + 1;
        
        /* Pedir los datos al usuario */
        printf("Escribe un numero ENTERO. Cualquiera.""\n");
        printf(">> ");
        scanf("%i", &numeroDelUsuario);
        validar(numeroDelUsuario);


        /* Condicionales if para evaluar los distintos casos */

        /* Caso del 0 al 500 */
        if ((0 <= numeroDelUsuario) && (500 >= numeroDelUsuario))
        {
            
            /* Ciclo para sumar de 5 en 5 */
            for (controlDeCinco = 5; controlDeCinco <= 500; controlDeCinco = controlDeCinco + 5)
            {
                printf("\n""%i", controlDeCinco);
            }

          /* Caso del 550 al 1000 */  
        } else if ((501 <= numeroDelUsuario) && (1000 >= numeroDelUsuario))
        {   
            /* Ciclo para sumar de 10 en 10 */
            for (controlDeDiez = 10; controlDeDiez <= 500; controlDeDiez = controlDeDiez + 10)
            {
                printf("\n""%i", controlDeDiez);
            }

          /* Caso del 1000 en adelante */  
        } else if (1001 <= numeroDelUsuario)
        {   
            /* Mensaje */
            printf("No se puede calcular el valor.");
        }
        
        /* Pregunta al usuario si quiere volver a ejecutar el programa */
        printf("\n""Deseas volverlo a hacer? Oprime 1 para Si / Oprime 2 para No" "\n");
        printf(">> ");
            scanf("%i", &eleccionDelUsuario);
            validar(eleccionDelUsuario);

        printf("\n""**********************************************************************""\n");

    } while (eleccionDelUsuario != 2);

    /* Muestra la cantidad de veces que se ejecuta el programa */
    printf("\n""El programa se ha ejecutado: ""%i", cuentaDePrograma);  printf(" veces");

    printf("\n""Hasta prontooo");

    return 0;
}