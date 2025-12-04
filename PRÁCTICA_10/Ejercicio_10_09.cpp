// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string cifrarCesar(const string& texto, int desplazamiento);
bool procesarArchivo(const string& entrada, const string& salida, int desplazamiento);

int main() 
{
    int desplazamiento = 3;

    if (procesarArchivo("mensaje.txt", "mensaje_cifrado.txt", desplazamiento)) 
    {
        cout << "Archivo cifrado correctamente (mensaje_cifrado.txt)." << endl;
    } else 
    {
        cout << "No se pudo abrir mensaje.txt" << endl;
    }

    return 0;
}

string cifrarCesar(const string& texto, int desplazamiento) 
{
    string resultado = "";

    for (char c : texto) 
    {
        if (c >= 'A' && c <= 'Z') 
        {  
            resultado += char((c - 'A' + desplazamiento) % 26 + 'A');
        }
        else if (c >= 'a' && c <= 'z') 
        {  
            resultado += char((c - 'a' + desplazamiento) % 26 + 'a');
        }
        else 
        {
            resultado += c;
        }
    }

    return resultado;
}

bool procesarArchivo(const string& entrada, const string& salida, int desplazamiento) 
{
    ifstream archivoEntrada(entrada);
    if (!archivoEntrada)
    {
         return false;
    }

    ofstream archivoSalida(salida);
    string linea;

    while (getline(archivoEntrada, linea)) 
    {
        archivoSalida << cifrarCesar(linea, desplazamiento) << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
    return true;
}