// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 15/10/2024
// Número de ejercicio: 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int GenerarAleatorios(int min,int max)
{
    return (rand()%(max-min+1))+min;
}

void Impresion(int matr[100][100],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

double Promedio (int mat[100][100],int tam,int sum)
{
    for (int i = 1; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            sum+=mat[i][j];
        }
    }
    return sum/(tam*tam);
}

int main()
{
    system("chcp 65001");
    srand(time(0));
    int A=0;
    int B=0;
    int N=0;
    cout<<"Ingrese el valor de A: ";
    cin>>A;
    cout<<"Ingrese el valor de B: ";
    cin>>B;
    cout<<"Ingrese el tamaño de la matriz: ";
    cin>>N;
    int matriz[100][100];
    int suma=0;
    int producto=1;
    double promedio=0;
    double sumatoria=0;
    double desviacion=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matriz[i][j]=GenerarAleatorios(A,B);
        }
    }
    for (int j = 0; j <N; j++)
    {
        suma+=matriz[0][j];
        producto*=matriz[N-1][j];
    }
    promedio=Promedio(matriz,N,suma);
    int mayor=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sumatoria+=(matriz[i][j]-promedio)*(matriz[i][j]-promedio);
            if (mayor<matriz[i][j])
            {
                mayor=matriz[i][j];                                                                                                                                     
            }
        }
    }
    desviacion=sqrt(sumatoria/(N*N));
    Impresion(matriz,N);
    cout<<"La suma de la primera fila: "<<suma<<endl;
    cout<<"El producto de la última fila es: "<<producto<<endl;
    cout<<"El elemento mayor es: "<<mayor<<endl;
    cout<<"La desviación estándar: "<<desviacion<<endl;
    return 0;
}