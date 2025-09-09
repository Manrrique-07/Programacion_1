// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 6
#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <cmath>   
using namespace std;
bool esPrimo(int num) 
{
    if (num <= 1) return false; 
    if (num == 2) return true;  
    if (num % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(num); i += 2) 
    {
        if (num % i == 0) return false;
    }
    return true;
}
int main() 
{
    int N;
    cout << "Ingrese la cantidad de numeros aleatorios a generar: ";
    cin >> N;
    srand(time(0)); 
    int contadorPrimos = 0;
    cout << "\nNumeros generados:\n";
    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 10000 + 1; 
        cout << num << " ";
        if (esPrimo(num)) 
        {
            contadorPrimos++;
        }
    }
    cout << "\n\nCantidad de numeros primos encontrados: " << contadorPrimos << endl;
    return 0;
}