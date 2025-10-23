// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 22/10/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;

int Fibonacci(int n);     // Prototipo de la función recursiva
void MostrarFibonacci(int n); // Función para mostrar la secuencia

int main()
{
    system("chcp 65001");
    int n = 0;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Secuencia de Fibonacci hasta " << n << ":\n";
    MostrarFibonacci(n);
    return 0;
}

int Fibonacci(int n)
{
    if (n == 0)
        return 0;  // Caso base 1
    else if (n == 1)
        return 1;  // Caso base 2
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2); // Paso recursivo
}

void MostrarFibonacci(int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << Fibonacci(i) << " ";
    }
}