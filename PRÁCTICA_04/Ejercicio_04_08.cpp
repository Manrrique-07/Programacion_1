// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 8
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    srand(time(0));
    int n;
    cout << "Ingrese la cantidad de productos vendidos: ";
    cin >> n;

    double totalBruto = 0;
    cout << "\n--- Lista de precios de los productos ---\n";
    for (int i = 1; i <= n; i++) {
        double precio = 20 + rand() % 31; 
        cout << "Producto " << i << ": " << precio << " Bs\n";
        totalBruto += precio;
    }

    double iva = totalBruto * 0.13;
    double totalConIVA = totalBruto + iva;
    double descuento = 0;

    if (totalConIVA > 2500) {
        descuento = totalConIVA * 0.05;
        totalConIVA -= descuento;
    }

    cout << "\nMonto total sin IVA: " << totalBruto << " Bs";
    cout << "\nIVA (13%): " << iva << " Bs";
    cout << "\nDescuento aplicado: " << descuento << " Bs";
    cout << "\nMonto final a pagar: " << totalConIVA << " Bs\n";

    cout << "\nEl pago del IVA al Servicio de Impuestos Nacionales es: " << iva << " Bs\n";

    return 0;
}