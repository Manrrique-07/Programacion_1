// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Student
{
    int cedula;
    char nombre [30];
    char apellido [30];
    int edad;
    char profesion [30];
    char lugar_nacimiento [30];
    char dirección [30];
    int telefono;
};

Student Llenar_datos_estudiante();
void Mostrar(vector<Student>Est);

int main()
{
    system("chcp 65001");
    vector<Student> Estudiante;
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cout << "Estudiante " << i+1 << endl;
        Estudiante.push_back(Llenar_datos_estudiante());
    }
    Mostrar(Estudiante);
    return 0;
}

Student Llenar_datos_estudiante()
{
    Student Estudiante;
    cout << "Ingrese la CI: ";
    cin >> Estudiante.cedula;
    cin.ignore();
    cout << "Ingrese el nombre: ";
    cin.getline(Estudiante.nombre,30);
    cout << "Ingrese el apellido: ";
    cin.getline(Estudiante.apellido,30);
    cout << "Ingrese la edad: ";
    cin >> Estudiante.edad;
    cin.ignore();
    cout << "Ingrese la profesion: ";
    cin.getline(Estudiante.profesion,30);
    cout << "Ingrese el lugar de nacimiento: ";
    cin.getline(Estudiante.lugar_nacimiento,30);
    cout << "Ingrese la dirección: ";
    cin.getline(Estudiante.dirección,30);
    cout << "Ingrese el teléfono: ";
    cin >> Estudiante.telefono;
    cin.ignore();
    return Estudiante;
}

void Mostrar(vector<Student>Est)
{
    cout << "-------DATOS-DE-ESTUDIANTES-------" <<endl;
    for (int i = 0; i < Est.size(); i++)
    {
        cout << "\t---Estudiante " << i+1 << "---" << endl;
        cout << "\tCI: " << Est[i].cedula << endl;
        cout << "\tNombre: " << Est[i].nombre << endl;
        cout << "\tApellido: " << Est[i].apellido << endl;
        cout << "\tEdad: " << Est[i].edad << endl;
        cout << "\tProfesión: " << Est[i].profesion << endl;
        cout << "\tLugar de nacimiento: " << Est[i].lugar_nacimiento << endl;
        cout << "\tDirección: " << Est[i].dirección << endl;
        cout << "\tTeléfono: " << Est[i].telefono << endl;
    }
}