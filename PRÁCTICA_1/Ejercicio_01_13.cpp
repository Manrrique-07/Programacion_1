// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/08/2025
// Número de ejercicio: 13
#include <iostream>
using namespace std;
int main() 
{
    system("chcp 65001");
    int N=0;
    int suma = 0;
    int i;
    cout << "Ingrese el valor de N:";
    cin >> N;
    for (i = 1; i <= N; i=i+1) 
    {
        suma = suma + i;
    }
    cout << "La suma de 1 hasta " << N << " es: " << suma << endl;
    return 0;
}