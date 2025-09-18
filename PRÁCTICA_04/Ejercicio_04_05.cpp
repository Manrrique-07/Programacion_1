// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
double CalcularSalario(double horasTrabajadas, double tarifaHora, double &bonificacion) {
    const double HORAS_MIN = 8;
    double salario = 0;
    bonificacion = 0;

    if (horasTrabajadas > HORAS_MIN) {
        double horasExtra = horasTrabajadas - HORAS_MIN;
        salario = HORAS_MIN * tarifaHora;
        bonificacion = horasExtra * tarifaHora * 1.5;  
        salario += bonificacion;
    } else {
        salario = horasTrabajadas * tarifaHora;
    }

    return salario;
}

int main() {
    double horas, tarifa, bonificacion;
    
    cout << "Ingrese las horas trabajadas: ";
    cin >> horas;
    cout << "Ingrese la tarifa por hora: ";
    cin >> tarifa;

    double salarioTotal = CalcularSalario(horas, tarifa, bonificacion);

    cout << "Salario del trabajador: " << salarioTotal << endl;
    if (bonificacion > 0)
        cout << "Bonificación por horas extra: " << bonificacion << endl;
    else
        cout << "No tiene bonificación por horas extra." << endl;

    return 0;
}