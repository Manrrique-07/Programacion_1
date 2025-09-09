// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 3
#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main() 
{
    srand(time(0)); 
    int num = rand() % 10 + 1; 
    unsigned long long factorial = 1;
    for (int i = 1; i <= num; i++) 
    {
        factorial *= i;
    }
    cout << "Numero aleatorio generado: " << num << endl;
    cout << "Factorial de " << num << " es: " << factorial << endl;
    return 0;
}