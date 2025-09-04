// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 25
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero = 0;
    char si_no;
    do
    {
        cout << "Ingrese el número del que desea ver la tabla: ";
        cin >> numero;
        cout << "La tabla de multiplicar es: " << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << numero << " * " << i << " = " << numero*i << endl;
        }
        cout << "¿Desea calcular otra tabla? (s/n)" << endl;
        cin >> si_no;
    } 
    while (si_no == 's');
    return 0;
}