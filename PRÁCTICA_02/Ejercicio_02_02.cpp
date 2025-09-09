// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 2
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
    int caras = 0, cruces = 0;
    for (int i = 0; i < n; i++)
    {
        int moneda = rand() % 2; 
        if (moneda == 0) 
            caras++;
        else 
            cruces++;
    }
    double porcentajeCaras = (caras * 100.0) / n;
    double porcentajeCruces = (cruces * 100.0) / n;
    cout << "Caras: " << caras << " (" << porcentajeCaras << "%)\n";
    cout << "Cruces: " << cruces << " (" << porcentajeCruces << "%)\n";
    return 0;
}