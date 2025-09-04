// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int main ()
{
    system("chcp 65001");
    float base=0;
    float altura=0;
    float area=0;
    cout << "Para hallar el area de un triángulo, ingrese la base: ";
    cin >> base;
    cout << "Ahora ingrese la altura del triángulo: ";
    cin >> altura;
    area = (base*altura)/2;
    cout << "El área del triángulo es: ";
    cout << area;
    return 0;
}