// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 10

#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Fraccion 
{
    int numerador;
    int denominador;
};

struct FraccionSimplificada 
{
    int numerador;
    int denominador;
};

int MCD(int a, int b);
FraccionSimplificada ReducirFraccion(Fraccion f);

int main() 
{
    Fraccion f;
    cout << "Ingrese numerador: ";
    cin >> f.numerador;
    cout << "Ingrese denominador: ";
    cin >> f.denominador;

    FraccionSimplificada fs = ReducirFraccion(f);

    cout << "Fraccion simplificada: " 
         << fs.numerador << "/" << fs.denominador << endl;

    return 0;
}

int MCD(int a, int b) 
{
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

FraccionSimplificada ReducirFraccion(Fraccion f) 
{
    FraccionSimplificada fs;

    int mcd = MCD(f.numerador, f.denominador);

    fs.numerador = f.numerador / mcd;
    fs.denominador = f.denominador / mcd;

    return fs;
}