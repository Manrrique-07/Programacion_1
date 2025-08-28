// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/08/2025
// Número de ejercicio: 15
#include <iostream>
using namespace std;
int main() 
{
    int N;
    int i;
    double nota=0.0;
    double suma=0.0;
    cout << "Ingrese la cantidad de notas: ";
    cin >> N;
    for (i = 1; i <= N; i=i+1) 
    {
        cout << "Ingrese la nota " << i << ": ";
        cin >> nota;
        suma = suma + nota; 
    }
    double promedio = suma / N;
    cout << "El promedio general es: " << promedio << endl;
    return 0;
}