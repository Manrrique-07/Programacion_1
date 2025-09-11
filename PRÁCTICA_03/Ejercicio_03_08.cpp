// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 8
#include <iostream>
using namespace std;
int algoritmo (int corte, int dinero)
{
    if(dinero >= corte)
    {
        int cantidad = dinero / corte;
        return cantidad;
    } 
    else 
    {
        return 0;
    }
}
int main()
{
    int n;
    cout << "Ingrese la cantidad de dinero: " << endl;
    cin >> n;
    int c = algoritmo(200, n);
    if(c > 0)
    {
        cout << c << " billetes de 200 Bs" << endl;
        n = n - (c * 200);
    }
    c = algoritmo(100, n);
    if(c > 0)
    {
        cout << c << " billetes de 100 Bs" << endl;
        n = n - (c * 100);
    }
    c = algoritmo(50, n);
    if(c > 0)
    {
        cout << c << " billetes de 50 Bs" << endl;
        n = n - (c * 50);
    }
    c = algoritmo(20, n);
    if(c > 0)
    {
        cout << c << " billetes de 20 Bs" << endl;
        n = n - (c * 20);
    }
    c = algoritmo(10, n);
    if(c > 0)
    {
        cout << c << " billetes de 10 Bs" << endl;
        n = n - (c * 10);
    }
    c = algoritmo(5, n);
    if(c > 0)
    {
        cout << c << " billetes de 5 Bs" << endl;
        n = n - (c * 5);
    }
    c = algoritmo(2, n);
    if(c > 0)
    {
        cout << c << " billetes de 2 Bs" << endl;
        n = n - (c * 2);
    }
    c = algoritmo(1, n);
    if(c > 0){
        cout << c << " billetes de 1 Bs" << endl;
        n = n - (c * 1);
    }
    return 0;
}