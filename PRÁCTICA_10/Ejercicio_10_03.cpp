// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GuardarEstudiantes();
void MostrarEstudiantes();

int main()
{
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            GuardarEstudiantes();
            break;
        case 2:
            MostrarEstudiantes();
            break;
        case 3:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 3);

    return 0;
}

void GuardarEstudiantes()
{
    ofstream archivo("estudiantes.txt", ios::app);

    if (!archivo)
    {
        cout << "Error al abrir el archivo estudiantes.txt\n";
        return;
    }

    string nombre;
    int edad;
    float promedio;
    int cantidad;

    cout << "¿Cuantos estudiantes deseas ingresar? ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "\n--- Estudiante " << i + 1 << " ---\n";

        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Edad: ";
        cin >> edad;

        cout << "Promedio: ";
        cin >> promedio;

        // Guardar en archivo
        archivo << nombre << ";" << edad << ";" << promedio << "\n";
    }

    archivo.close();
    cout << "\nDatos guardados correctamente.\n";
}

void MostrarEstudiantes() 
{
    ifstream archivo("estudiantes.txt");

    if (!archivo) 
    {
        cout << "Error al abrir el archivo estudiantes.txt\n";
        return;
    }

    cout << "\n--- LISTA DE ESTUDIANTES ---\n\n";

    string linea;
    while (getline(archivo, linea)) 
    {
        if (linea != "") 
        {
            cout << linea << endl;
        } 
        else 
        {
            cout << endl;
        }
    }

    archivo.close();
}