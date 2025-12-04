// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int BuscarOcurrencias(const string& frase);

int main() 
{
    string frase;

    cout << "Ingrese la palabra o frase a buscar: ";
    getline(cin, frase);

    int total = BuscarOcurrencias(frase);

    if (total != -1)
    {
        cout << "\nLa frase \"" << frase << "\" aparece " << total << " veces en el archivo.\n";
    }
    return 0;
}

int BuscarOcurrencias(const string& frase)
{
    ifstream archivo("datos.txt");

    if (!archivo) 
    {
        cout << "Error: no se pudo abrir el archivo datos.txt\n";
        return -1;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        size_t pos = linea.find(frase);

        while (pos != string::npos) 
        {
            contador++;
            pos = linea.find(frase, pos + frase.length());
        }
    }

    archivo.close();
    return contador;
}