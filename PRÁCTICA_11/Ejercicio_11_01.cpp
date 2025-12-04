// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 11-11-2025 
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct structEstudiante 
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct structNotas 
{
    char ci[10];
    char materia[30];
    int nota;
};

void ingresarEstudiante();
bool existeEstudiante(const char ci[]);
void ingresarNotas();
bool existeNota(const char ci[], const char materia[]);
void reporte();

int main() 
{
    int opcion;

    do 
    {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ingreso de datos estudiantes\n";
        cout << "2. Ingreso de materias y notas\n";
        cout << "3. Reporte de estudiantes y notas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) 
        {
            case 1: ingresarEstudiante(); break;
            case 2: ingresarNotas(); break;
            case 3: reporte(); break;
            case 4: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }

    } while (opcion != 4);

    return 0;
}

bool existeEstudiante(const char ci[]) 
{
    ifstream archivo("Estudiantes.bin", ios::binary);
    if (!archivo) 
    {
        return false;
    }

    structEstudiante e;
    while (archivo.read(reinterpret_cast<char*>(&e), sizeof(e))) 
    {
        if (strcmp(e.ci, ci) == 0) 
        {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void ingresarEstudiante() 
{
    structEstudiante e;

    cout << "Ingrese CI: ";
    cin.getline(e.ci, 10);

    if (existeEstudiante(e.ci)) 
    {
        cout << "Error: El estudiante con ese CI ya existe.\n";
        return;
    }

    cout << "Ingrese nombres: ";
    cin.getline(e.nombres, 30);

    cout << "Ingrese apellidos: ";
    cin.getline(e.apellidos, 30);

    ofstream archivo("Estudiantes.bin", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&e), sizeof(e));
    archivo.close();

    cout << "Estudiante registrado correctamente.\n";
}

bool existeNota(const char ci[], const char materia[]) 
{
    ifstream archivo("Notas.bin", ios::binary);
    if (!archivo) 
    {
        return false;
    }

    structNotas n;
    while (archivo.read(reinterpret_cast<char*>(&n), sizeof(n))) 
    {
        if (strcmp(n.ci, ci) == 0 && strcmp(n.materia, materia) == 0) 
        {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void ingresarNotas() 
{
    structNotas n;

    cout << "Ingrese CI del estudiante: ";
    cin.getline(n.ci, 10);

    if (!existeEstudiante(n.ci)) 
    {
        cout << "Error: El estudiante NO existe.\n";
        return;
    }

    cout << "Ingrese materia: ";
    cin.getline(n.materia, 30);

    if (existeNota(n.ci, n.materia)) 
    {
        cout << "Error: La materia ya tiene una nota registrada para este estudiante.\n";
        return;
    }

    cout << "Ingrese nota: ";
    cin >> n.nota;
    cin.ignore();

    ofstream archivo("Notas.bin", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&n), sizeof(n));
    archivo.close();

    cout << "Nota registrada correctamente.\n";
}

void reporte() 
{
    ifstream estFile("Estudiantes.bin", ios::binary);
    ifstream notasFile("Notas.bin", ios::binary);

    if (!estFile) 
    {
        cout << "No existen estudiantes registrados.\n";
        return;
    }

    cout << "\n===== REPORTE COMPLETO =====\n";

    structEstudiante e;
    structNotas n;

    while (estFile.read(reinterpret_cast<char*>(&e), sizeof(e))) 
    {
        cout << "\nCI: " << e.ci << endl;
        cout << "Nombre: " << e.nombres << " " << e.apellidos << endl;
        cout << "Notas:\n";

        bool tieneNotas = false;

        notasFile.clear();
        notasFile.seekg(0);

        while (notasFile.read(reinterpret_cast<char*>(&n), sizeof(n))) 
        {
            if (strcmp(e.ci, n.ci) == 0) 
            {
                cout << "  - " << n.materia << ": " << n.nota << endl;
                tieneNotas = true;
            }
        }

        if (!tieneNotas) 
        {
            cout << "  No tiene notas registradas.\n";
        }
    }

    estFile.close();
    notasFile.close();
}