// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;
float Conversion(float grados) 
{
    return ((9.0/5.0) * grados) + 32; 
}
int main() 
{
    float grados_celcius, grados_fahrenheit;
    system("chcp 65001"); 
    cout << "Ingrese los grados en Celsius: ";
    cin >> grados_celcius;
    grados_fahrenheit = Conversion(grados_celcius);
    cout << grados_celcius << " °C equivalen a " << grados_fahrenheit << " °F" ;
    return 0;
}