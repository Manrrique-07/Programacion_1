// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 03/10/2025
// Número de ejercicio: 7
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar();
void mostrar (vector<int> arr);

int main()
{
    vector<int> arr = ingresar();
    mostrar(arr);
    return 0;
}

vector<int> ingresar()
{
    int i = 0;
    vector<int> arr;
    int a = 1;
    
    while(i < 10 && a >= 0)
    {
        cout << "ingrese el valor " << i + 1 << ":\n";
        cin >> a;
        if(a < 0)
        {
            continue;
        } else 
        {
            arr.push_back(a);
            i++;
        }
    }
    
    return arr;
}

void mostrar (vector<int> arr)
{
    for(int i :  arr)
    {
        cout << i << "\t";
    }
}