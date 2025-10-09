// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 12
// Problema planteado:
#include <iostream>
#include <string>

using namespace std;

char aMinuscula(char c);
bool esLetra(char c);
bool esPalindromo(const string& texto);

int main() 
{
    string texto;

    cout << "Ingrese un texto: ";
    getline(cin, texto);

    if (esPalindromo(texto))
    {
        cout << "Es un palindromo" << endl;
    }
    else
    {
        cout << "No es un palindromo" << endl;
    }

    return 0;
}

char aMinuscula(char c) 
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A'); 
    }
    return c;
}

bool esLetra(char c) 
{
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}

bool esPalindromo(const string& texto) 
{
    string limpio = "";

    for (char c : texto) 
    {
        if (esLetra(c)) 
        {
            limpio += aMinuscula(c);
        }
    }

    int izquierda = 0;
    int derecha = limpio.length() - 1;

    while (izquierda < derecha) 
    {
        if (limpio[izquierda] != limpio[derecha]) 
        {
            return false;
        }
        izquierda++;
        derecha--;
    }

    return true;
}