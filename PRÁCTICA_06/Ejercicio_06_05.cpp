// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 5
// Problema planteado:
#include <iostream>
#include <vector>

using namespace std;

void MostrarVector(const vector<string>& v);
vector<string> Interseccion(const vector<string>& v1, const vector<string>& v2);

int main()
{
    int n1, n2;

    cout << "Ingrese la cantidad de clientes de la Empresa 1: ";
    cin >> n1;
    cin.ignore();

    vector<string> empresaA(n1);
    cout << "Ingrese los nombres de los clientes de la Empresa 1:" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << "Cliente " << i + 1 << ": ";
        getline(cin, empresaA[i]);
    }

    cout << "Ingrese la cantidad de clientes de la Empresa 2: ";
    cin >> n2;
    cin.ignore();

    vector<string> empresaB(n2);
    cout << "Ingrese los nombres de los clientes de la Empresa 2:" << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << "Cliente " << i + 1 << ": ";
        getline(cin, empresaB[i]);
    }

    vector<string> comunes = Interseccion(empresaA, empresaB);

    cout << "Clientes en comun:" << endl;
    MostrarVector(comunes);

    return 0;
}

void MostrarVector(const vector<string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Nombre " << i + 1 << ": " << v[i] << endl;
    }
}

vector<string> Interseccion(const vector<string>& v1, const vector<string>& v2)
{
    vector<string> comunes;

    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                comunes.push_back(v1[i]);
                break; 
            }
        }
    }

    return comunes;
}