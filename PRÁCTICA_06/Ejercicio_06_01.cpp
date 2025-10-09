// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 1
// Problema planteado:
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void MostrarLista(vector<int>num);
double Promedio(vector<int>num);
double Desviacion(vector<int>num, double promedio);

int main()
{
    
    vector<int>edades;
    int edad=0;
    double prom = 0;
    double S = 0;
    do
    {
        cout << "Ingrese la edad: ";
        cin >> edad; 
        edades.push_back(edad); 
    } while (edad != -1);
    MostrarLista(edades);
    prom = Promedio(edades);
    S=Desviacion(edades, prom);
    cout << "Desviacion tipica: " << S;
    return 0;
}
void MostrarLista(vector<int>num)
{
    
    for (int i = 0; i < num.size() - 1; i++)
    {
        cout << "Edad " << i+1 << ": " << num[i] << endl;
    }
    
}
double Promedio(vector<int>num)
{
    double suma = 0;
    double promedio = 0;
    for (int i = 0; i < num.size() - 1; i++)
    {
        suma = suma + num[i];
    }
    promedio = suma / (num.size()-1);
    return promedio;
}
double Desviacion(vector<int>num, double promedio)
{
    double cuadrado = 0;
    double resta = 0;
    double sumatoria = 0;
    double Varianza = 0;
    for (int i = 0; i < num.size() - 1; i++)
    {
        resta = num[i] - promedio;
        cuadrado = resta * resta;
        sumatoria = sumatoria + cuadrado;
    }
    Varianza=sumatoria/(num.size()-1);
    return sqrt(Varianza);
}