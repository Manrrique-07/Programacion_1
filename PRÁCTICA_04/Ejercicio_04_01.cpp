// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
void IntercambiarValores(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}
int main() 
{
    int x, y;
    cout << "Ingrese el primer valor: ";
    cin >> x;
    cout << "Ingrese el segundo valor: ";
    cin >> y;
    cout << "Antes de intercambiar: x = " << x << ", y = " << y << endl;
    IntercambiarValores(x, y);
    cout << "Después de intercambiar: x = " << x << ", y = " << y << endl;
    return 0;
}