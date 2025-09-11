// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <cstdlib>  
#include <ctime>     
using namespace std;
void procesarAlumnos(int N) 
{
    int edad, sumaEdades = 0, mayores18 = 0;
    int altura, sumaAlturas = 0, masAltos = 0;
    cout << "Lista de alumnos generados:\n";
    for (int i = 1; i <= N; i++) 
    {
        edad = 1 + rand() % 35;         
        altura = 120 + rand() % 81;      
        cout << "Alumno " << i << " -> Edad: " << edad << " años, Altura: " << altura << " cm" << endl;
        sumaEdades += edad;
        sumaAlturas += altura;
        if (edad > 18) mayores18++;
        if (altura > 175) masAltos++;
    }
    cout << "\nResultados:" << endl;
    cout << "Edad media: " << (float)sumaEdades / N << " años" << endl;
    cout << "Altura media: " << (float)sumaAlturas / N << " cm" << endl;
    cout << "Cantidad de alumnos mayores de 18: " << mayores18 << endl;
    cout << "Cantidad de alumnos con altura > 175 cm: " << masAltos << endl;
}
int main() 
{
    srand(time(0)); 
    int N;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> N;
    procesarAlumnos(N);
    return 0;
}