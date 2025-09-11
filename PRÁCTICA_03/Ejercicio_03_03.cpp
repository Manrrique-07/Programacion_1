// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
bool Capicua(int numero) 
{
    int original = numero;
    int invertido = 0;
    while (numero > 0) 
    {
        int digito = numero % 10;         
        invertido = invertido * 10 + digito; 
        numero /= 10;                        
    }
    return original == invertido;
}
int main() 
{
    int n;
    cout << "Ingrese un número: ";
    cin >> n;
    if (Capicua(n)) 
    {
        cout << n << " es capicúa." << endl;
    } 
    else 
    {
        cout << n << " no es capicúa." << endl;
    }
    return 0;
}