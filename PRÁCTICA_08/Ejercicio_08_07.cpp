// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 22/10/2025
// Número de ejercicio: 7

#include <iostream>

using namespace std;

int Suma(int numero,int n);

int main()
{
    int num=1;
    int N=0;
    cout<<"Ingresar el valor de N: ";
    cin>>N;
    cout<<Suma(num,N);
    return 0;
}

int Suma(int numero,int n)
{
    int suma=0;
    if (numero>n)
    {
        return 0;
    }
    else
    {
        suma=suma+(numero*numero);
        return suma+Suma(numero+1,n);
    }
}