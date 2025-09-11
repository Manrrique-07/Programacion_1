// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
float IMC(float peso, float altura) 
{
    return peso / (altura * altura);
}
int main() 
{
    float peso, altura, imc;
    cout << "Ingrese su peso en kilogramos: ";
    cin >> peso;
    cout << "Ingrese su altura en metros: ";
    cin >> altura;
    imc = IMC(peso, altura);
    cout << "Su IMC es: " << imc << endl;
    if (imc < 18.5) 
    {
        cout << "Clasificación: Bajo peso" << endl;
    } 
    else if (imc < 25) 
    {
        cout << "Clasificación: Normal" << endl;
    } 
    else if (imc < 30) 
    {
        cout << "Clasificación: Sobrepeso" << endl;
    } 
    else 
    {
        cout << "Clasificación: Obesidad" << endl;
    }
    return 0;
}