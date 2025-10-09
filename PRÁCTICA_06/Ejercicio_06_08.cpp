// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 8
// Problema planteado:
#include <iostream>
#include <string>

using namespace std;

bool validarCorreo(const string& correo);

int main() 
{
    string correo;

    cout << "Ingrese un correo electronico: ";
    getline(cin, correo);

    if (validarCorreo(correo))
        cout << "Correo electronico valido" << endl;
    else
        cout << "Correo electronico invalido" << endl;

    return 0;
}

bool validarCorreo(const string& correo) 
{
    int posArroba = -1;
    int cantidadArrobas = 0;

    for (int i = 0; i < correo.length(); i++) 
    {
        if (correo[i] == '@') 
        {
            cantidadArrobas++;
            if (cantidadArrobas == 1)
            {
                posArroba = i;
            }
        }
    }

    if (cantidadArrobas != 1)
        return false;

    bool puntoDespues = false;
    for (int i = posArroba + 1; i < correo.length(); i++) 
    {
        if (correo[i] == '.') 
        {
            puntoDespues = true;
            break;
        }
    }

    return puntoDespues;
}