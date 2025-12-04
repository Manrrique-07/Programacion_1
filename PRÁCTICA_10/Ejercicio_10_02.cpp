// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contarPalabrasEnLinea(const string &linea);
int contarPalabrasArchivo(const string &nombreArchivo);

int main() 
{
    string nombreArchivo = "texto.txt";

    int total = contarPalabrasArchivo(nombreArchivo);

    if (total != -1) 
    {
        cout << "El archivo contiene " << total << " palabras." << endl;
    }

    return 0;
}

int contarPalabrasEnLinea(const string &linea) 
{
    int contador = 0;
    bool dentroPalabra = false;

    for (char c : linea) {
        if (c != ' ' && c != '\t') 
        {
            if (!dentroPalabra) 
            {
                contador++;
                dentroPalabra = true;
            }
        } 
        else 
        {
            dentroPalabra = false;
        }
    }
    return contador;
}

int contarPalabrasArchivo(const string &nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    string linea;
    int totalPalabras = 0;

    if (!archivo.is_open()) 
    {
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    while (getline(archivo, linea)) 
    {
        totalPalabras += contarPalabrasEnLinea(linea);
    }

    archivo.close();
    return totalPalabras;
}