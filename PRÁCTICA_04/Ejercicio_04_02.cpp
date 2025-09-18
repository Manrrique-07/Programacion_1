// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 2
#include <iostream>
#include <cmath>
using namespace std;

double CalcularVolumen(double radio, double altura = 10) 
{
    return M_PI * radio * radio * altura;
}

int main() 
{
    double r, h;
    cout << "Ingrese el radio: ";
    cin >> r;
    cout << "Ingrese la altura (0 para usar la altura por defecto): ";
    cin >> h;

    if (h == 0)
        cout << "Volumen = " << CalcularVolumen(r) << endl;
    else
        cout << "Volumen = " << CalcularVolumen(r, h) << endl;

    return 0;
}