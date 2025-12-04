// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 6

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> leerArchivo(const string& nombreArchivo);
vector<string> filtrarAltasTemperaturas(const vector<string>& lineas, float limite);
void guardarArchivo(const string& nombreArchivo, const vector<string>& lineas);

int main() 
{
    float limite;

    cout << "Ingrese la temperatura límite (N): ";
    cin >> limite;

    vector<string> lineas = leerArchivo("temperaturas.txt");

    if (lineas.empty()) 
    {
        cout << "No se pudo abrir el archivo temperaturas.txt" << endl;
        return 1;
    }

    vector<string> filtradas = filtrarAltasTemperaturas(lineas, limite);

    guardarArchivo("altas_temperaturas.txt", filtradas);

    cout << "Archivo altas_temperaturas.txt generado correctamente." << endl;

    return 0;
}

vector<string> leerArchivo(const string& nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    vector<string> lineas;
    string linea;

    if (!archivo) 
    {
        return {}; 
    }

    while (getline(archivo, linea)) 
    {
        lineas.push_back(linea);
    }

    archivo.close();
    return lineas;
}

vector<string> filtrarAltasTemperaturas(const vector<string>& lineas, float limite) 
{
    vector<string> filtradas;

    for (const string& linea : lineas) 
    {
        stringstream ss(linea);
        string ciudad;
        float temp;

        ss >> ciudad >> temp;

        if (temp > limite) 
        {
            filtradas.push_back(linea);
        }
    }

    return filtradas;
}

void guardarArchivo(const string& nombreArchivo, const vector<string>& lineas) 
{
    ofstream salida(nombreArchivo);

    for (const string& linea : lineas) 
    {
        salida << linea << endl;
    }

    salida.close();
}