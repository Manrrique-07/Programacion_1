// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main() 
{
    int N;
    cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
    cin >> N;
    srand(time(0)); 
    long long suma = 0; 
    int mayor = 0, menor = 1001; 
    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 1000 + 1; 
        cout << num << " "; 
        suma += num;
        if (num > mayor) mayor = num;
        if (num < menor) menor = num;
    }
    double promedio = (double)suma / N;
    cout << "Sumatoria: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor valor: " << mayor << endl;
    cout << "Menor valor: " << menor << endl;
    return 0;
}