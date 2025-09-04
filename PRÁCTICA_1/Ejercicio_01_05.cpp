// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;
int main ()
{
    system("chcp 65001");
    float centigrados=0;
    float kelvin=0;
    cout << "Ingrese el valor de grados centígrados que desea convertir: ";
    cin >> centigrados;
    kelvin=centigrados + 273.15;
    cout << "La conversión a grados Kelvin será: ";
    cout<<kelvin;
    return 0;
}