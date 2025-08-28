// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 24/08/2025
// Número de ejercicio: 7
#include <iostream>
using namespace std;
int main ()
{
    system("chcp 65001");
    char caracter;
    cout << "Ingrese un caracter ";
    cin >> caracter;
    if ((caracter >= 'a' && caracter <= 'z')) 
    {
        char letra = caracter;
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') 
        {
            cout << "El caracter ingresado es una vocal.";
        } 
        else 
        {
            cout << "El caracter ingresado es una consonante.";
        }
    } 
    else 
    {
        cout << "Es un caracter especial.";
    }
    return 0;
}