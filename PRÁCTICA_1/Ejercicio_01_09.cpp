// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 9
#include <iostream>
using namespace std;
int main ()
{
    system("chcp 65001");
    int edad=0;
    cout << "Estimado usuario, ingrese su edad por favor: ";
    cin >> edad;
    if (edad<=12)
    {
        cout<<"Usted es considerado un NIÑO";
    }
    else if (edad<=18)
    {
        cout<<"Usted es considerado un ADOLESCENTE";
    }
    else if (edad>18 && edad<60)
    {
        cout<<"Usted es considerado una persona MAYOR DE EDAD";
    }
    else if (edad>=60)
    {
        cout<<"Usted es considerado un ADULTO MAYOR";
    }
    return 0;
}