// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 9

#include <iostream>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

struct Alumno 
{
    double T1, T2, T3, T4, EF;
    double NP; 
    double NF; 
};

Alumno ingresarDatos();
void estadisticas(const vector<Alumno>& alumnos, double& promedio, double& minNF, double& maxNF);
void mostrarResultados(const vector<Alumno>& alumnos, double promedio, double minNF, double maxNF);

int main() 
{
    int N;
    cout << "Ingrese el numero de alumnos: ";
    cin >> N;

    vector<Alumno> alumnos(N);

    for (int i = 0; i < N; i++) 
    {
        cout << "\nAlumno " << i + 1 << endl;
        alumnos[i] = ingresarDatos();
    }

    double promedio, minNF, maxNF;
    estadisticas(alumnos, promedio, minNF, maxNF);
    mostrarResultados(alumnos, promedio, minNF, maxNF);
    return 0;
}

Alumno ingresarDatos() 
{
    Alumno a;
    cout << "Ingrese T1: "; cin >> a.T1;
    cout << "Ingrese T2: "; cin >> a.T2;
    cout << "Ingrese T3: "; cin >> a.T3;
    cout << "Ingrese T4: "; cin >> a.T4;
    cout << "Ingrese EF: "; cin >> a.EF;

    a.NP = (a.T1 + a.T2 + a.T3 + a.T4) / 4.0;
    a.NF = 0.7 * a.NP + 0.3 * a.EF;

    return a;
}

void estadisticas(const vector<Alumno>& alumnos, double& promedio, double& minNF, double& maxNF) 
{
    minNF = 1000;  
    maxNF = -1000; 

    double suma = 0;

    for (const Alumno& a : alumnos) 
    {
        suma += a.NF;

        if (a.NF < minNF)
            minNF = a.NF;

        if (a.NF > maxNF)
            maxNF = a.NF;
    }
    promedio = suma / alumnos.size();
}

void mostrarResultados(const vector<Alumno>& alumnos, double promedio, double minNF, double maxNF) 
{
    cout << "\n--- RESULTADOS ---\n";
    for (int i = 0; i < alumnos.size(); i++) 
    {
        cout << "Alumno " << i + 1 << ": NF = " << alumnos[i].NF << endl;
    }

    cout << "\nPromedio de notas finales: " << promedio << endl;
    cout << "Nota mínima final: " << minNF << endl;
    cout << "Nota máxima final: " << maxNF << endl;
}