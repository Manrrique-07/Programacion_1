// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 7
// Problema planteado:
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  

using namespace std;

int main() 
{
    srand(time(0)); 

    int N;
    cout << "Ingrese la cantidad de pixeles: ";
    cin >> N;

    vector<int> imagen(N);

    for (int i = 0; i < N; i++) 
    {
        imagen[i] = rand() % 256; 
    }

    vector<int> conteo(26, 0);

    for (int i = 0; i < N; i++) 
    {
        int rango = imagen[i] / 10;
        if (rango > 25) 
        {
            rango = 25;
        } 
        conteo[rango]++;
    }

    cout << "CONTEO DE PIXELES POR RANGO" << endl;
    for (int i = 0; i < 26; i++) {
        int inicio = i * 10;
        int fin;
        if (i == 25)
        {
            fin = 255;
        }
        else
        {
            fin = inicio + 9;
        }
        cout << inicio << "-" << fin << ": " << conteo[i] << " pixeles" << endl;
    }

    return 0;
}