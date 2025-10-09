// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 9
// Problema planteado:
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string oracion;
    
    cout << "Ingrese una oracion: ";
    getline(cin, oracion);

    stringstream ss(oracion);
    string palabra;
    vector<string> palabras;

    while (ss >> palabra) {
        palabras.push_back(palabra);
    }

    cout << "Oracion invertida: ";
    for (int i = palabras.size() - 1; i >= 0; i--) {
        cout << palabras[i];
        if (i != 0) cout << " "; 
    }
    cout << endl;

    return 0;
}