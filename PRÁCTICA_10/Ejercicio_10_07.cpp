// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> leerArchivo(const string& nombreArchivo);
vector<string> calcularPromedios(const vector<string>& lineas);
void guardarArchivo(const string& nombreArchivo, const vector<string>& lineas);

int main() 
{
    vector<string> lineas = leerArchivo("calificaciones.txt");

    if (lineas.empty()) 
    {
        cout << "No se pudo abrir el archivo calificaciones.txt" << endl;
        return 1;
    }

    vector<string> promedios = calcularPromedios(lineas);

    guardarArchivo("promedios.txt", promedios);

    cout << "Archivo promedios.txt generado correctamente." << endl;

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

vector<string> calcularPromedios(const vector<string>& lineas) 
{
    vector<string> resultados;

    for (const string& linea : lineas) 
    {
        stringstream ss(linea);
        string nombre;
        float nota, suma = 0;
        int contador = 0;

        ss >> nombre;  

        while (ss >> nota) 
        {
            suma += nota;
            contador++;
        }

        if (contador > 0) 
        {
            float promedio = suma / contador;
            resultados.push_back(nombre + " " + to_string(promedio));
        }
    }

    return resultados;
}

void guardarArchivo(const string& nombreArchivo, const vector<string>& lineas) 
{
    ofstream archivo(nombreArchivo);

    for (const string& linea : lineas) 
    {
        archivo << linea << endl;
    }

    archivo.close();
}