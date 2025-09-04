// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 18
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int contador = 0;   
    int numero = 2;     
    cout << "Los 100 primeros números primos son:" << endl;
    while (contador < 100) 
    {
        bool primo = true;
        for (int i = 2; i < numero; i++) 
        {
            if (numero % i == 0) 
            {
                primo = false;
                break;
            }
        }
        if (primo) 
        {
            cout << numero << " ";
            contador+=1;
        }
        numero+=1;
    }
    cout << endl;
    return 0;
}