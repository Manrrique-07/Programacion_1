// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;
bool esBisiesto(int año) 
{
    return (año % 4 == 0 && (año % 100 != 0 || año % 400 == 0));
}
int diasEnMes(int año, int mes) 
{
    switch (mes) 
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return esBisiesto(año) ? 29 : 28;
        default:
            return -1;
    }
}
int main() 
{
    system("chcp 65001");
    int año, mes;
    cout << "Ingrese el año: ";
    cin >> año;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    int dias = diasEnMes(año, mes);
    if (dias == -1) 
    {
        cout << "Mes inválido." << endl;
    } else {
        cout << "El mes " << mes << " del año " << año << " tiene " << dias << " días." << endl;
    }
    return 0;
}