// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 03/10/2025
// Número de ejercicio: 4
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cout << "Ingrese el tamaño de los vectores: ";
    cin >> n;
    vector<int> a(n), b(n), c(n);

    cout << "Vector 1: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Numero "<< i+1 << ": ";
        cin >> a[i];
    }

    cout << "Vector 2: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Numero "<< i+1 << ": ";
        cin >> b[i];
    }

    cout << "Prodcto de los vectores: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Multiplicacion "<< i+1 << ": ";
        c[i]=a[i]*b[i];
        cout << c[i] << endl;
    }
    return 0;
}