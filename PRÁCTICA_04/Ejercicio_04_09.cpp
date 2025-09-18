// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 9
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    srand(time(0));
    int n;
    cout << "Ingrese el número de vendedoras: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        double sueldoBasico;
        cout << "\nVendedora " << i << endl;
        cout << "Ingrese el sueldo básico (según antigüedad): ";
        cin >> sueldoBasico;
        int productosVendidos = 8 + rand() % 6; 
        cout << "Productos vendidos: " << productosVendidos << endl;
        double totalVentas = 0;
        for (int j = 1; j <= productosVendidos; j++) {
            double precio = 20 + rand() % 31;
            totalVentas += precio;
        }

        double comision = totalVentas * 0.10;
        double sueldoTotal = sueldoBasico + comision;

        cout << "Total vendido: " << totalVentas << " Bs" << endl;
        cout << "Comisión (10%): " << comision << " Bs" << endl;
        cout << "Sueldo total: " << sueldoTotal << " Bs" << endl;
    }

    return 0;
}