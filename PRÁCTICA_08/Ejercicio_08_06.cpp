// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 22/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int Aleatorios(int min, int max);
void LlenarVector(vector<int>&vec, int n);
void MostrarVector(vector<int>&vec, int n);
int Comparar(vector<int>&v1, vector<int>&v2, int i, int &cont);

int main()
{
    system("chcp 65001");
    srand(time(0));
    int N=0;
    int cont=0;
    int i=0;
    cout<<"Ingrese el tamaño del vector: ";
    cin>>N;
    vector<int>vector1(N);
    vector<int>vector2(N);
    LlenarVector(vector1,N);
    MostrarVector(vector1,N);
    LlenarVector(vector2,N);
    MostrarVector(vector2,N);
    Comparar(vector1,vector2,i,cont);

    if (cont==N)
    {
        cout<<"Los vectores son iguales";
    }
    else
    {
        cout<<"Los vectores NO son iguales";
    }
    
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
        vec[i]=Aleatorios(9,9);
    }
}

void MostrarVector(vector<int>&vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int Comparar(vector<int>&v1, vector<int>&v2, int i, int &cont)
{
    if (i==v1.size())
    {
        return 0;
    }
    else
    {
        if (v1[i]==v2[i])
        {
            cont++;
            return Comparar(v1,v2,i+1, cont);
        }
        else
        {
            return 0;
        }
    }
}