// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 20
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero = 0;
    cout << "Ingrese un número: ";
    cin >> numero;
    int digitos = 0;
    while (numero != 0)
    {
        numero = numero / 10;
        digitos+=1;
    }
    cout << "La cantidad de dígitos del número ingresado es: " << digitos;
    return 0;
}