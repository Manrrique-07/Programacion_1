// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 21
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero_1 = 0;
    int numero_2 = 0;
    int resultado = 0;
    int signo = 1;
    cout << "Ingrese el primer número: ";
    cin >> numero_1;
    cout << "Ingrese el segundo número: ";
    cin >> numero_2;
    if (numero_1 < 0)
    {
        numero_1 = -numero_1;
        signo*=-1;
    }
    if (numero_2 < 0)
    {
        numero_2=-numero_2;
        signo *= -1;
    }
    for (int i = 0; i < numero_2; i++)
    {
        resultado+=numero_1;
    }
    resultado*=signo;
    cout << "El resultado es: " << resultado;
    return 0;
}