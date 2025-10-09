// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 13
// Problema planteado:
#include <iostream>
#include <string>

using namespace std;

char aMayuscula(char c);
string capitalizarPalabras(const string& texto);

int main() 
{
    string texto;

    cout << "Ingrese un texto: ";
    getline(cin, texto);

    string capitalizado = capitalizarPalabras(texto);

    cout << "Texto con mayusculas: " << capitalizado << endl;

    return 0;
}

char aMayuscula(char c) 
{
    if (c >= 'a' && c <= 'z') 
    {
        return c - ('a' - 'A'); 
    }
    return c;
}

string capitalizarPalabras(const string& texto) 
{
    string resultado = texto;
    bool nuevaPalabra = true; 

    for (int i = 0; i < resultado.length(); i++) 
    {
        char c = resultado[i];

        if (c >= 'a' && c <= 'z') 
        {
            if (nuevaPalabra) 
            {
                resultado[i] = aMayuscula(c); 
                nuevaPalabra = false;
            }
        }
        else if (c >= 'A' && c <= 'Z') 
        {
            if (nuevaPalabra) 
            {
                nuevaPalabra = false; 
            }
        }
        else 
        {
            nuevaPalabra = true;
        }
    }

    return resultado;
}
