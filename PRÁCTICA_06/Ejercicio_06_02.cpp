// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 08/10/2025
// Número de ejercicio: 2
// Problema planteado: 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buscar_mineral(string min[], vector<double>prod);
void Ordenar(string min[], vector<double>prod);
void Mostrar(string min[], vector<double>prod);

int main()
{
    string minerales[6] = {"SN", "SB", "AU", "PT", "AG", "CU"};
    vector<double>produccion = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};
    buscar_mineral(minerales, produccion);
    Ordenar(minerales, produccion);
    Mostrar(minerales, produccion);
    return 0;
}

void buscar_mineral(string min[], vector<double>prod)
{
    string buscar;
    bool encontrar = false;
    cout << "Ingrese el mineral buscado (SN, SB, AU, PT, AG, CU): ";
    cin >> buscar;

    for (int i = 0; i < prod.size(); i++)
    {
        if (min[i] == buscar)
        {
            cout << "Produccion de " << min[i] << ": " << prod[i] << endl;
            encontrar = true;
            break;
        }
        
    }

    if (!encontrar)
    {
        cout << "Mineral no encontrado" << endl;
    }
}

void Ordenar(string min[], vector<double>prod)
{
    double prod_temporal = 0;
    string min_temporal;

    for (int i = 0; i < prod.size() - 1; i++)
    {
        for (int j = 0; j < prod.size(); i++)
        {
            if (prod[i] < prod[j])
            {
                prod_temporal = prod[i];
                prod[i] = prod[j];
                prod[j] = prod_temporal;

                min_temporal = min[i];
                min[i] = min[j];
                min[j] = min_temporal;
            }
        }
    }
}

void Mostrar(string min[], vector<double>prod)
{
    for (int i = 0; i < prod.size(); i++)
    {
        cout << min[i] << " -> Produccion: " << prod[i] << endl;
    }
    
}
