// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;

double ConvertirCelsiusAFahrenheit(double celsius) 
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double MayorTemperatura(double t1, double t2) 
{
    return (t1 > t2) ? t1 : t2;
}

int main() 
{
    double c1, c2;
    cout << "Ingrese la primera temperatura en Celsius: ";
    cin >> c1;
    cout << "Ingrese la segunda temperatura en Celsius: ";
    cin >> c2;

    double f1 = ConvertirCelsiusAFahrenheit(c1);
    double f2 = ConvertirCelsiusAFahrenheit(c2);

    cout << "La primera temperatura en Fahrenheit: " << f1 << endl;
    cout << "La segunda temperatura en Fahrenheit: " << f2 << endl;
    cout << "La mayor temperatura en Fahrenheit es: " << MayorTemperatura(f1, f2) << endl;

    return 0;
}