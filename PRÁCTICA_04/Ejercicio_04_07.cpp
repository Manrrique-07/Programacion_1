// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 17/09/2025
// Número de ejercicio: 7
#include <iostream>
using namespace std;

int MCD(int m, int n) 
{
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int MCM(int m, int n) 
{
    return (m * n) / MCD(m, n);
}

int main() 
{
    int m, n;
    cout << "Ingrese el primer número: ";
    cin >> m;
    cout << "Ingrese el segundo número: ";
    cin >> n;

    int mcd = MCD(m, n);
    int mcm = MCM(m, n);

    cout << "El MCD de " << m << " y " << n << " es: " << mcd << endl;
    cout << "El MCM de " << m << " y " << n << " es: " << mcm << endl;

    return 0;
}