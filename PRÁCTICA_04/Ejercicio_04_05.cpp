// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;

int main() 
{
    double horas, tarifa, bonificacion;
    cout << "Ingrese las horas trabajadas: ";
    cin >> horas;
    cout << "Ingrese la tarifa por hora: ";
    cin >> tarifa;
    cout << "Ingrese la bonificación por hora extra: ";
    cin >> bonificacion;

    double salario, extra = 0;

    if (horas > 8) {
        salario = 8 * tarifa;
        extra = (horas - 8) * (tarifa + bonificacion);
    } else {
        salario = horas * tarifa;
    }

    cout << "Salario del trabajador: " << salario << endl;
    cout << "Salario por bonificación: " << extra << endl;
    cout << "Salario total: " << salario + extra << endl;

    return 0;
}