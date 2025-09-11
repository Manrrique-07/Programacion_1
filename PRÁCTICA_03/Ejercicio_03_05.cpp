// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;
float promedioPonderado(int notas[], int pesos[], int n) 
{
    int sumaPesos = 0;
    float sumaPonderada = 0;
    for (int i = 0; i < n; i++) 
    {
        sumaPonderada += notas[i] * pesos[i];
        sumaPesos += pesos[i];
    }
    return sumaPonderada / sumaPesos;
}
int main() 
{
    srand(time(0)); 
    const int N = 4;
    int notas[N];
    int pesos[N] = {10, 20, 30, 40};
    cout << "Notas generadas aleatoriamente:\n";
    for (int i = 0; i < N; i++) 
    {
        notas[i] = 1 + rand() % 100;
        cout << "Nota " << (i + 1) << ": " << notas[i] 
             << " (Peso " << pesos[i] << ")\n";
    }
    float promedio = promedioPonderado(notas, pesos, N);
    cout << "\nEl promedio ponderado es: " << promedio << endl;
    return 0;
}