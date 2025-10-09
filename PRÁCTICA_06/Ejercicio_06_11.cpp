// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 11
// Problema planteado:
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() 
{
    string texto;
    char delimitador;

    cout << "Ingrese la cadena: ";
    getline(cin, texto);

    cout << "Ingrese el delimitador: ";
    cin >> delimitador;

    stringstream ss(texto);
    string token;

    cout << "Tokens encontrados:" << endl;
    while (getline(ss, token, delimitador)) 
    {  
        cout << token << endl;
    }

    return 0;
}