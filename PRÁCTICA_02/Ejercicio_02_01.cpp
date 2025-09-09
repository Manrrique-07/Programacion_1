// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 1
#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main() 
{
    int n;
    cout << "Ingrese el numero de lanzamientos: ";
    cin >> n;
    srand(time(0));
    int cara2 = 0, cara4 = 0, cara6 = 0;
    for (int i = 0; i < n; i++) 
    {
        int dado = rand() % 6 + 1;  
        if (dado == 2) cara2++;
        else if (dado == 4) cara4++;
        else if (dado == 6) cara6++;
    }
    cout << "La cara 2 salio: " << cara2 << " veces\n";
    cout << "La cara 4 salio: " << cara4 << " veces\n";
    cout << "La cara 6 salio: " << cara6 << " veces\n";
    return 0;
}