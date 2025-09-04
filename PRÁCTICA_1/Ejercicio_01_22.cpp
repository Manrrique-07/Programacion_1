// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 22
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero_1 = 0;
    int numero_2 = 0;
    cout << "Ingrese el primer número: ";
    cin >> numero_1;
    cout << "Ingrese el segundo número: ";
    cin >> numero_2;
    if (numero_1==0 || numero_2==0)
    {
        cout << "No hay multiplos de 0";
    }
    else
    {
        if (numero_1 % numero_2 == 0 || numero_2 % numero_1 == 0)
        {
            cout << "Los números son múltiplos entre sí";
        }
        else
        {
            cout << "Los números NO son múltiplos";
        }     
    }
    return 0;
}