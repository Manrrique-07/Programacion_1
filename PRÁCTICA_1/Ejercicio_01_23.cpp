// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 23
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero = 0;
    int digito = 0;
    cout << "Ingrese un número entero por favor: ";
    cin >> numero;
    cout << "El número al revés es: ";
    if (numero < 0)
    {
        cout << "-";
        numero = -numero;
    }
    while (numero > 0)
    {
        digito = numero % 10;
        cout << digito;
        numero = numero / 10;
    }
    return 0;
}