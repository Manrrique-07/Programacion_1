// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 15/10/2024
// Número de ejercicio: 4

#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001");
    int n=0;
    cout<<"Ingrese el tamaño de la matriz: ";
    cin>>n;
    int matriz[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Ingrese el elemento "<<i+1<<","<<j+1<<": ";
            cin>>matriz[i][j];
        }  
    }
    cout<<"La matriz generada fué:"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matriz[i][j]<<" ";
        }  
        cout<<endl;
    }
}