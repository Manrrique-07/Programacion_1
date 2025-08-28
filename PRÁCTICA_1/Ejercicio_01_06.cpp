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
    int numero=0;
    cout << "Ingrese el valor de un número entero: ";
    cin >> numero;
    if (numero>0)
    {
        cout<<"El número ingresado es POSITIVO";
    }
    else if (numero<0)
    {
        cout<<"El número ingresado es NEGATIVO";
    }
    else
    {
        cout<<"El número ingresado es CERO";
    } 
    return 0;
}