// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 08/09/2025
// Número de ejercicio: 4
#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;
int main() 
{
    srand(time(0)); 
    int numeroSecreto = rand() % 51; 
    int intentos = 5;
    int min = 0, max = 50;
    int intento;
    cout << "Estoy pensando un numero entre 0 y 50\n";
    for (int i = 1; i <= intentos; i++) 
    {
        cout << "Intento " << i << " ? ";
        cin >> intento;
        if (intento == numeroSecreto) 
        {
            cout << "Felicitaciones... Adivinaste el numero " << endl;
            return 0; 
        } 
        else 
        {
            if (intento < numeroSecreto) 
            {
                min = intento;
            } 
            else 
            {
                max = intento; 
            }
            cout << "El numero esta entre " << min << " y " << max << endl;
        }
    }
    cout << "\nLo siento, no adivinaste el numero. Era: " << numeroSecreto << endl;
    return 0;
}