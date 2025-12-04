// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct empleado
{
    char nombre[20];
    int id;
    double sueldo;
    int antiguedad;
};

empleado LLenar_datos();
void sueldo_mayor_a(double sueld, vector<empleado>empleados);
void Mostrar(int i, empleado trabajador);
void promedio_antiguedad(vector<empleado>empleados, int n);

int main()
{
    system("chcp 65001");
    vector<empleado>empleados;
    int N;
    double comparar_sueldo;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin.ignore();
        cout << "------EMPLEADO " << i << "-------" << endl;
        empleados.push_back(LLenar_datos());
    }   
    cout << endl;
    cout << "Ingrese un valor de sueldo: ";
    cin >> comparar_sueldo;
    sueldo_mayor_a(comparar_sueldo, empleados);
    promedio_antiguedad(empleados, N);
}

empleado LLenar_datos()
{
    empleado trabajador;
    cout << "Ingrese el nombre: ";
    cin.getline(trabajador.nombre, 20);
    cout << "Ingrese el ID: ";
    cin >> trabajador.id;
    cout << "Ingrese el sueldo: ";
    cin >> trabajador.sueldo;
    cout << "Ingrese la antiguedad en años: ";
    cin >> trabajador.antiguedad;
    return trabajador;
}

void sueldo_mayor_a(double sueld, vector<empleado>empleados)
{
    empleado trabajador;
    for (int i = 0; i < empleados.size(); i++)
    {
        if (empleados[i].sueldo > sueld)
        {
            Mostrar(i, empleados[i]);
        }
    }
}

void Mostrar(int i, empleado trabajador)
{
    cout << "EMPLEADO " << i+1 << endl;
    cout << "-----------------------------------" << endl;
    cout << "\tNombre: " << trabajador.nombre << endl;
    cout << "\tID: " << trabajador.id << endl;
    cout << "\tSueldo: " << trabajador.sueldo << endl;
    cout << "\tAntiguedad: " << trabajador.antiguedad << endl;
}

void promedio_antiguedad(vector<empleado>empleados, int n)
{
    double suma_antiguedad = 0;
    for (int i = 0; i < empleados.size(); i++)
    {
        suma_antiguedad = suma_antiguedad + empleados[i].antiguedad;
    }
    
    cout << "El promedio de los años de antiguedad es: " << suma_antiguedad/n;
}