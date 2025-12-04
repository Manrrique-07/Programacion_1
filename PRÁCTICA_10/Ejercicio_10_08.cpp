// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 8

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int contarLineas(const string& nombreArchivo);
int contarPalabras(const string& nombreArchivo);
int contarCaracteres(const string& nombreArchivo);

int main() 
{
    string nombreArchivo = "documento.txt";

    int lineas = contarLineas(nombreArchivo);
    int palabras = contarPalabras(nombreArchivo);
    int caracteres = contarCaracteres(nombreArchivo);

    if (lineas == -1 || palabras == -1 || caracteres == -1) 
    {
        cout << "No se pudo abrir el archivo documento.txt" << endl;
        return 1;
    }

    cout << "Total de líneas: " << lineas << endl;
    cout << "Total de palabras: " << palabras << endl;
    cout << "Total de caracteres: " << caracteres << endl;

    return 0;
}

int contarLineas(const string& nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    if (!archivo) return -1;

    string linea;
    int contador = 0;

    while (getline(archivo, linea)) 
    {
        contador++;
    }

    archivo.close();
    return contador;
}

int contarPalabras(const string& nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    if (!archivo) return -1;

    string palabra;
    int contador = 0;

    while (archivo >> palabra) 
    {
        contador++;
    }

    archivo.close();
    return contador;
}

int contarCaracteres(const string& nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    if (!archivo) return -1;

    char caracter;
    int contador = 0;

    while (archivo.get(caracter)) 
    {
        contador++;
    }

    archivo.close();
    return contador;
}