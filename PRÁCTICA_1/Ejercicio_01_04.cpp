// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
int main ()
{
    float radio=0;
    float volumen=0;
    float pi=3.1416;
    cout<<"Para hallar el volumen de una esfera, ingrese el radio: ";
    cin>> radio;
    volumen=(4*pi*radio*radio*radio)/3;
    cout<<"El volumen de la esfera es: ";
    cout<<volumen;
    return 0;
}