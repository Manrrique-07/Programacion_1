// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 22/10/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

int Euclides(int n1, int n2);

int main()
{
    system("chcp 65001");
    int n=0;
    int m=0;
    cout<<"Ingrese el número 1: ";
    cin>>n;
    cout<<"Ingrese el número 2: ";
    cin>>m;
    cout<<Euclides(n,m);
    return 0;
}

int Euclides(int n1, int n2)
{
    if (n1%n2==0)
    {
        return n2;
    }
    else
    {
        return Euclides(n2,n1%n2);
    }
}