// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 11/09/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
void Par_Impar(int numero) 
{
    if (numero % 2 == 0) 
    {
        cout << numero << " es PAR" << endl;
    } 
    else 
    {
        cout << numero << " es IMPAR " << endl;
    }
}
int main() 
{
    system("chcp 65001");
    int num;
    cout << "Ingrese un número: ";
    cin >> num;
    Par_Impar(num);  
    return 0;
}