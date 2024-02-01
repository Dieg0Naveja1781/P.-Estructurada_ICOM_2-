
/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 29/1/24
PROGRAMA: Uso de caracteres de escape y cadenas de control
Universidad De Guadalajara//Centro Universitario de los Altos//Ing. en Computación//2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: Utiliza los diferentes caracteres como parte integral del programa
----------------------- */
#include <stdio.h>
#include <string>

int main()
{
    /* Estas son las variables */
    unsigned int muerte = 8989;
    unsigned int localizacion = 4923;
    double victoria = 8930;
    int nombre = 85494033;
    double nombre2 = 9349209;
    int numero3;
    char eleccionJaja;
    
    /* Y este es el programa ...*/
    printf("\"""\'""\t""Probando""\n");
    printf("\v""\a""probando""\n");

    printf("Tu pc esta infectada por un virus desconocido""\n");

    printf("\a""Este virus eliminara toda tu informacion. Para evitarlo, debes responder la siguiente ""\'""Encuesta""\'""\n");
    printf("Lo haras""\?""\v");
    printf("\n"">> S");
    printf("\n"">> N");
    printf("\n""\t"">> ");
    scanf("%c", &eleccionJaja);

    printf("\n""No importa lo que elijas. Vas a hacerlo...");
    
    printf("\n""1. Tus posibilidades de morir hoy son: ""%o", muerte); 
    printf("\n""Estas de acuerdo""\?""\v");
    printf("\n"">> S");
    printf("\n"">> N");
    scanf("%c", &eleccionJaja);

    printf("\n""2. Este es el color de tu pelo: ""%x", localizacion);
    printf("\n""Es correcto""\?""\v");
    printf("\n"">> S");
    printf("\n"">> N");
    scanf("%c", &eleccionJaja);

    printf("\n""3. Piensa en un numero y escribelo. Lo adivinare: ");
    scanf("%i", &numero3);
    printf("\n"">> ");
    printf("\n""...");  printf("\n"".....");    printf("\n"".....Pensando....");    printf("\n""...Tu numero es..");
    printf("\v""%d", numero3);

    printf("\n""He adivinado""\?""\v");
    printf("\n"">> S");
    printf("\n"">> N");
    scanf("%c", &eleccionJaja);

    printf("\n""JAJAJAJA. Lo sabia. Soy el mejor""\n");
    printf("\n""Y con esta es mi victoria numero ""%f", victoria);
    printf("\n""Espera...""\n""Quien es la persona detras de ti""\?");

    printf("\n""\\""No... No es posible");
    printf("\n""\\""\\""Espera... ESPERAAA""\\");
    printf("\n""\\""\\""\\""VOLVEREE POR T-""\\""\\""\\""\\");

    printf("\n""...");
    printf("\n""Reiniciando Sistema Operativo....");
    printf("\n""Bienvenido, ""%d", nombre); printf("D. ""%o", nombre);  printf("A. ""%g", nombre2);

    /* Perdón profe la neta no se que hice pero parece que funciona y pues lo importante es aprender verdad que tenga buen día */

  return 0;
}