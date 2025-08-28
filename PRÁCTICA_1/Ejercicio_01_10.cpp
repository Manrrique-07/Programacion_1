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
    system("chcp 65001");
    int nota=0;
    cout << "Estimado usuario, ingrese su nota por favor: ";
    cin >> nota;
    if (nota>=51)
    {
        if (nota<60)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = C";
        }
        else if (nota<70)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = C+";
        }
        else if (nota<80)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = B";
        }
        else if (nota<90)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = B+";
        }
        else if (nota<95)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = A";
        }
        else if (nota<=100)
        {
            cout<<"Usted está APROBADO con CALIFICACIÓN = A+";
        }
    }
    else
    {
        cout<<"Usted está REPROBADO";
    }
    return 0;
}