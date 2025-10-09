// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 4
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

void MostrarVector(const vector<int>& v);
void RotarDerecha(vector<int>& v, int k);

int main()
{   int N = 0;
    int k = 0;
    cout << "Ingrese la cantidad de numeros: ";
    cin >> N;

    vector<int> numeros(N);

    for (int i = 0; i < N; i++)
    {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "Ingrese cuantas posiciones desea rotar a la derecha: ";
    cin >> k;
    RotarDerecha(numeros, k);

    cout << "Vector rotado:" << endl;
    MostrarVector(numeros);
    
    return 0;
}

void MostrarVector(const vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Numero " << i+1 << ": " << v[i] << endl;
    }
    
}

void RotarDerecha(vector<int>& v, int k)
{
    int n = v.size();
    k = k % n; 
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = v[i];
    }

    v = temp; 
}