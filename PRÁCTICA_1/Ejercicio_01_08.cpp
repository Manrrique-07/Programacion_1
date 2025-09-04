// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 8
#include <iostream>
using namespace std;
int main ()
{
    system("chcp 65001");
    int numero=0;
    cout << "Ingrese el valor de un número entero: ";
    cin >> numero;
    if (numero%2==0)
    {
        cout<<"El número ingresado es PAR";
    }
    else
    {
        cout<<"El número ingresado es IMPAR";
    } 
    return 0;
}