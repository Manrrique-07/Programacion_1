// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 22/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int Aleatorios(int min, int max);
void LlenarVector(vector<int>&vec, int n);
void MostrarVector(vector<int>&vec, int n);
int Suma(vector<int>&vect, int i);

int main()
{
    system("chcp 65001");
    srand(time(0));
    int N=0;
    cout<<"Ingrese el tamaño del vector: ";
    cin>>N;
    vector<int>vector(N);
    LlenarVector(vector,N);
    MostrarVector(vector,N);
    cout<<endl;
    cout<<"La suma de los elementos del vector es: "<<Suma(vector,0);

    return 0;
}

int Aleatorios(int min, int max)
{
    return (rand()%(max-min+1))+min;
}

void LlenarVector(vector<int>&vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        vec[i]=Aleatorios(0,9);
    }
}

void MostrarVector(vector<int>&vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<vec[i]<<" ";
    }
}

int Suma(vector<int>&vect, int i)
{
    int suma=0;
    if (i==vect.size())
    {
        return 0;
    }
    else
    {
        suma= suma + vect[i];
        return suma+Suma(vect,i+1);
    }
}