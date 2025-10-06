// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 03/10/2025
// Número de ejercicio: 2
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> voltios = {11.95,16.32,12.15,8.22,15.98,26.22,13.54,6.45,17.59};
    for(int i=0;i<voltios.size();i++){
        cout<<voltios[i]<<" ";
        if((i+1)%3==0) cout<<endl;
    }
    return 0;
}