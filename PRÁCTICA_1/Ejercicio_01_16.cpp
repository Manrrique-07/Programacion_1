// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/08/2025
// Número de ejercicio: 16
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int numero;
    int i;
    int contador = 0; 
    cout << "Ingrese un número: ";
    cin >> numero;
    if (numero <= 1) 
    {
        cout << "No es un número primo" << endl;
    } 
    else 
    {
        for (i = 2; i < numero; i=i+1) 
        {
            if (numero % i == 0) 
            {
                contador=contador+1;  
            }
        }
        if (contador == 0) 
        {
            cout << "Es un número primo" << endl;
        } 
        else 
        {
            cout << "No es un número primo" << endl;
        }
    }
    return 0;
}