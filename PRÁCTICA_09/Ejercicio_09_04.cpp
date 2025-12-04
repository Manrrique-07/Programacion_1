// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 4

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct empleado
{
    char nombre [30];
    char genero [30];
    double salario;
};

empleado Llenar_datos_empleado();
int menor_salario(vector<empleado>&empl);
int mayor_salario(vector<empleado>&empl);
void Mostrar(vector<empleado>empl, int indice);

int main()
{   system("chcp 65001");
    vector<empleado> empl;
    int N;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        cout << "Empleado " << i+1 << endl;
        empl.push_back(Llenar_datos_empleado());
    }
    cout << "EMPLEADO CON MENOR SALARIO" << endl;
    Mostrar(empl, menor_salario(empl));
    cout << "EMPLEADO CON MAYOR SALARIO" << endl;
    Mostrar(empl, mayor_salario(empl));
    return 0;
}

empleado Llenar_datos_empleado()
{
    empleado empl;
    cout << "Ingrese el nombre: ";
    cin.getline(empl.nombre,30);
    cout << "Ingrese el género: ";
    cin.getline(empl.genero,30);
    cout << "Ingrese el salario: ";
    cin >> empl.salario;
    cin.ignore();
    return empl;
}

int menor_salario(vector<empleado>&empl)
{
    double min_sal = 10000;
    int ind = 0;
    for (int i = 0; i < empl.size(); i++)
    {
        if (empl[i].salario < min_sal)
        {
            min_sal = empl[i].salario;
            ind = i;
        }
    }
    return ind;
}

int mayor_salario(vector<empleado>&empl)
{
    double max_sal = 0;
    int ind = 0;
    for (int i = 0; i < empl.size(); i++)
    {
        if (empl[i].salario > max_sal)
        {
            max_sal = empl[i].salario;
            ind = i;
        }
    }
    return ind;
}

void Mostrar(vector<empleado>empl, int indice)
{
    cout << "\tNombre: " << empl[indice].nombre << endl;
    cout << "\tGénero: " << empl[indice].genero << endl;
    cout << "\tSalario: " << empl[indice].salario << endl;
}