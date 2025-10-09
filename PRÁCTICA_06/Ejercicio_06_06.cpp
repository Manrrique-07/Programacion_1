// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 6
// Problema planteado:
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0)); 

    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    vector<int> calificaciones(N);

    for (int i = 0; i < N; i++) {
        calificaciones[i] = rand() % 101; 
    }

    int reprobado = 0, regular = 0, bueno = 0, excelente = 0;

    for (int i = 0; i < N; i++) 
    {
        int cal = calificaciones[i];
        if (cal <= 59)
        {
            reprobado++;
        }
        else if (cal <= 79) 
        {
            regular++;
        }
        else if (cal <= 89) 
        {
            bueno++;
        }
        else 
        {
            excelente++;
        }
    }

    cout << "Resultados:" << endl;
    cout << "Reprobado   (0-59): " << (reprobado * 100.0 / N) << "%" << endl;
    cout << "Regular    (60-79): " << (regular * 100.0 / N) << "%" << endl;
    cout << "Bueno      (80-89): " << (bueno * 100.0 / N) << "%" << endl;
    cout << "Excelente (90-100): " << (excelente * 100.0 / N) << "%" << endl;

    return 0;
}