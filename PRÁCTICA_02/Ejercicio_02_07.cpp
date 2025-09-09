// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <cstdlib>  
#include <ctime>   
using namespace std;
int main() 
{
    system("chcp 65001");
    int N;
    cout << "Ingrese la cantidad total de niños: ";
    cin >> N;
    srand(time(0));
    int n1 = rand() % (N + 1);          
    int n2 = rand() % (N - n1 + 1);     
    int n3 = rand() % (N - n1 - n2 + 1); 
    int totalNiños = n1 + n2 + n3;
    int totalPañales = (n1 * 6) + (n2 * 3) + (n3 * 2);
    cout << "\nDistribucion generada:" << endl;
    cout << "Niños de 1 año: " << n1 << " (6 pañales c/u)" << endl;
    cout << "Niños de 2 años: " << n2 << " (3 pañales c/u)" << endl;
    cout << "Niños de 3 años: " << n3 << " (2 pañales c/u)" << endl;
    cout << "Total niños asignados: " << totalNiños << " de " << N << endl;
    cout << "\nConsumo total de pañales por día: " << totalPañales << endl;
    return 0;
}