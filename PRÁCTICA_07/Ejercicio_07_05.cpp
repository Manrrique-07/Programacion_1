// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 15/10/2024
// Número de ejercicio: 5

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GenerarAleatorios(int min,int max)
{
    return (rand()%(max-min+1))+min;
}

void Impresion(int matr[100][100],int tam1, int tam2)
{
    for (int i = 0; i < tam1; i++)
    {
        for (int j = 0; j < tam2; j++)
        {
            cout<<matr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void Multiplicacion(int m1[100][100], int m2[100][100],int n, int m, int p,int prod[100][100])
{
    for (int i = 0; i <n ; i++)
    {
        for (int j = 0; j < p; j++)
        {
            prod[i][j]=0;
            for (int k = 0; k < m; k++)
            {
                prod[i][j]+=m1[i][k]*m2[k][j];
            }
        } 
    }
}
int main()
{
    srand(time(0));
    system("chcp 65001");
    int N=0;
    int M=0;
    int P=0;
    cout<<"Ingrese el valor de N: ";
    cin>>N;
    cout<<"Ingrese el valor de M: ";
    cin>>M;
    P=N;
    int matriz_1[100][100];
    int matriz_2[100][100];
    int matriz_producto[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matriz_1[i][j]=GenerarAleatorios(0,9);
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz_2[i][j]=GenerarAleatorios(0,9);
        }
    }
    cout<<"Primera matriz "<<N<<"x"<<M<<endl;
    Impresion(matriz_1,N,M);
    cout<<"Segunda matriz: "<<M<<"x"<<P<<endl;
    Impresion(matriz_2,M,N);
    Multiplicacion(matriz_1,matriz_2,N,M,P,matriz_producto);
    cout<<"Matriz producto: "<<N<<"x"<<P<<endl;
    Impresion(matriz_producto,N,P);
    return 0;
}