// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/08/2025
// Número de ejercicio: 12
#include <iostream>
using namespace std;
int main() 
{
    system("chcp 65001");
    int numero=0;
    do 
    {
        cout << "Ingrese un número entre 1 y 5: ";
        cin >> numero;
        if (numero < 1 || numero > 5) 
        {
            cout << "El número ingresado es inválido. Ingrese otro valor" << endl;
        }
    } 
    while (numero < 1 || numero > 5);
    cout << "El número ingresado es válido " << endl;
    return 0;
}
