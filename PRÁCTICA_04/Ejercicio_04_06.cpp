// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;

bool esPrimo(int n) 
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() 
{
    system("chcp 65001");
    int num;
    cout << "Ingrese un número entero: ";
    cin >> num;

    int suma = 0, temp = num;
    while (temp > 0) {
        int dig = temp % 10;
        if (dig != 0) suma += dig;
        temp /= 10;
    }

    cout << "La suma de los dígitos distintos de cero es: " << suma << endl;

    if (esPrimo(suma))
        cout << "La suma es un número primo." << endl;
    else
        cout << "La suma no es un número primo." << endl;

    return 0;
}