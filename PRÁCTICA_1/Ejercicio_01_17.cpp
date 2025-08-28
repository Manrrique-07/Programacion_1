// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/08/2025
// Número de ejercicio: 17
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int num1=0;
    int num2=0;
    int i;
    int suma_1=0;
    int suma_2=0;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    for (i = 1; i < num1; i=i+1) 
    {
        if (num1 % i == 0) 
        {
            suma_1=suma_1+i;
        }
    }
    for (i = 1; i < num2; i=i+1) 
    {
        if (num2 % i == 0) 
        {
            suma_2=suma_2+i;
        }
    }
    if (suma_1 == num2 && suma_2 == num1) 
    {
        cout << "Se verifica que son números amigos" << endl;
    } 
    else 
    {
        cout << "Se verifica que no son números amigos" << endl;
    }
    return 0;
}