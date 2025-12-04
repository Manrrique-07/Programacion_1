// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 04/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <fstream>

using namespace std;

void GuardarNombres(int cantidad);
void LeerNombres();

int main()
{
    int n;

    cout << "¿Cuantos nombres desea ingresar?: ";
    cin >> n;

    GuardarNombres(n);  
    LeerNombres();      

    return 0;
}

void GuardarNombres(int cantidad) 
{
    ofstream archivo("nombres.txt");

    if (!archivo) 
    {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    cin.ignore();
    string nombre;

    cout << "\n--- INGRESO DE NOMBRES ---\n";
    for (int i = 0; i < cantidad; i++) 
    {
        cout << "Nombre " << i + 1 << ": ";
        getline(cin, nombre);
        archivo << i+1 << ". " << nombre << endl;
    }

    archivo.close();
}

void LeerNombres() 
{
    ifstream archivo("nombres.txt");
    string nombre;

    if (!archivo) 
    {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "\n--- NOMBRES GUARDADOS ---\n";
    while (getline(archivo, nombre)) 
    {
        cout << nombre << endl;
    }

    archivo.close();
}
