// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 14
#include <iostream>
using namespace std;
int main() 
{
    system("chcp 65001");
    int N;
    cout << "Ingrese el valor de N:";
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {       
        for (int j = 1; j <= i; j++) 
        {   
            cout << "*";
        }
        cout << endl;                
    }
    return 0;
}