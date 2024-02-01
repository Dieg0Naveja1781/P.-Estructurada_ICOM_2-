/* --------------------
NOMBRE: Diego Armando Naveja López
FECHA: 24/1/24
PROGRAMA: Datos del usuario
Universidad De Guadalajara//Centro Universitario de los Altos//Ing. en Computación//2° Semestre
PROFESOR: Carlos Javier Cruz Franco
DESCRIPCIÓN: Un programa que le pide datos al usuario y los muestra en pantalla
----------------------- */

//Librerías para usar el comando <<cin>> y <<cout>>, y para declarar variables tipo <<string>>
#include <iostream>
#include <string>

//Variables de tipo string
std::string nombre, lugarDeResidencia, fechaDeNacimiento, carrera, edad, semestre;

int main()
{
    /* Instrucciones del programa */
    std::cout <<"Hola. A continuacion te pedire tus datos para comprobar que sean correctos. Ingresa lo que se te pide por favor.""\n""Ingresa solo numeros cuando se te indique con la letra N, y texto cuando se te indique con la letra T. No pongas acentos.";

    /* Pide la información al usuario y la guarda en las variables correspondientes. Utiliza la función <<getline()>> */
    std::cout <<"\n""Nombre completo (T): ""\n";
        getline(std::cin, nombre);
        std::cout<<"\n""--------------------------------------""\n";
    std::cout <<"Edad (N): ""\n";
        getline(std::cin, edad);
        std::cout<<"\n""--------------------------------------""\n";
    std::cout <<"Lugar de residencia actual (T): ""\n";
        getline(std::cin, lugarDeResidencia);
        std::cout<<"\n""--------------------------------------""\n";
    std::cout <<"Fecha de nacimiento (T): ""\n";
        getline(std::cin, fechaDeNacimiento);
        std::cout<<"\n""--------------------------------------""\n";
    std::cout <<"Carrera que estas estudiando (T): ""\n";
        getline(std::cin, carrera);
        std::cout<<"\n""--------------------------------------""\n";
    std::cout <<"Semestre que cursas (N): ""\n";
        getline(std::cin, semestre);
        
    
    /* Muestra por pantalla la información ingresada por el usuario */
    std::cout <<"Tus datos son los siguientes: ";
    std::cout<<"\n""-*****************************************""\n";

    std::cout <<"\n""Nombre: "<<nombre;
    std::cout <<"\n""Edad: "<<edad;
    std::cout <<"\n""Lugar de residencia: "<<lugarDeResidencia;
    std::cout <<"\n""Fecha de nacimiento: "<<fechaDeNacimiento;
    std::cout <<"\n""Carrera: "<<carrera;
    std::cout <<"\n""Semestre actual: "<<semestre;
}