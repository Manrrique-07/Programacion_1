// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 14
// Problema planteado:
#include <iostream>
#include <string>

using namespace std;

char aMinuscula(char c);
void contarVocales(const string& texto);

int main() 
{
    string texto;
    cout << "Ingrese una frase: ";
    getline(cin, texto);

    contarVocales(texto);

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

void contarVocales(const string& texto) 
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    for (char c : texto) 
    {
        c = aMinuscula(c); 

        switch (c) 
        {
            case 'a': 
                a++; 
                break;
            case 'e': 
                e++; 
                break;
            case 'i': 
                i++; 
                break;
            case 'o': 
                o++; 
                break;
            case 'u': 
                u++; 
                break;
            default: 
                break;
        }
    }
    cout << "Vocales encontradas:" << endl;
    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "o: " << o << endl;
    cout << "u: " << u << endl;
}