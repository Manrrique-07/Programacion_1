// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 03/10/2025
// Número de ejercicio: 5
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar(int n);
vector<int> combinar(vector<int> v1, vector<int> v2);

int main()
{
    int n;
    cout << "ingrese el tamanio de los vectores: " << endl;
    cin >> n;
    vector<int> v1 = ingresar(n);
    vector<int> v2 = ingresar(n);
    
    vector<int> v3 = combinar(v1, v2);
    
    for(int i : v3){
        cout << i << "\t";
    }
    return 0;
}

vector<int> ingresar(int n)
{
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cout << "Ingrese el valor " << i + 1 << ":\n";
        cin >> v[i];
    }
    return v;
}

vector<int> combinar(vector<int> v1, vector<int> v2)
{
    vector<int> v3;
    for(int i : v1){
        v3.push_back(i);
    }
    
    for(int i : v2){
        v3.push_back(i);
    }
    
    return v3;
}