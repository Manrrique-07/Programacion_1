// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 5

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> leerArchivo(const string& nombreArchivo);
bool actualizarPrecio(vector<string>& lineas, const string& productoBuscado, float nuevoPrecio);
void guardarArchivo(const string& nombreArchivo, const vector<string>& lineas);

int main() 
{
    string producto;
    float nuevoPrecio;

    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> producto;

    cout << "Ingrese el nuevo precio: ";
    cin >> nuevoPrecio;

    vector<string> lineas = leerArchivo("productos.txt");

    if (lineas.empty()) 
    {
        cout << "No se pudo abrir el archivo productos.txt" << endl;
        return 1;
    }

    bool encontrado = actualizarPrecio(lineas, producto, nuevoPrecio);

    if (!encontrado) 
    {
        cout << "El producto no existe en el archivo." << endl;
        return 0;
    }

    guardarArchivo("productos.txt", lineas);
    cout << "Precio actualizado correctamente." << endl;

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

bool actualizarPrecio(vector<string>& lineas, const string& productoBuscado, float nuevoPrecio) 
{
    bool encontrado = false;

    for (string& linea : lineas) 
    {
        stringstream ss(linea);
        string producto;
        float precio;

        ss >> producto >> precio;

        if (producto == productoBuscado) 
        {
            linea = producto + " " + to_string(nuevoPrecio);
            encontrado = true;
            break;
        }
    }

    return encontrado;
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