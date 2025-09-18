// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;

void ModificarValores(int valor, int &referencia) 
{
    valor *= 2;
    referencia += 10;
    cout << "Dentro de la función -> valor: " << valor << ", referencia: " << referencia << endl;
}

int main() 
{
    int a, b;
    cout << "Ingrese el primer número (pasado por valor): ";
    cin >> a;
    cout << "Ingrese el segundo número (pasado por referencia): ";
    cin >> b;

    cout << "Antes de la función -> a: " << a << ", b: " << b << endl;
    ModificarValores(a, b);
    cout << "Después de la función -> a: " << a << ", b: " << b << endl;

    return 0;
}