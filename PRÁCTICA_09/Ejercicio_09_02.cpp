// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Atleta
{
    char nombre[30];
    char pais[30];
    int edad;
    int mejor_tiempo;
};

Atleta Ingresar_datos();
void mostrar_menor(vector<Atleta>& athlete);

int main()
{
    system("chcp 65001"); 
    vector<Atleta> athlete;
    int N = 0;

    cout << "Ingrese el número de atletas: ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        athlete.push_back(Ingresar_datos());
    }

    mostrar_menor(athlete);

    return 0;   
}

Atleta Ingresar_datos()
{
    Atleta athlete;
    
    cout << "Ingrese el nombre del atleta: ";
    cin.getline(athlete.nombre, 30);
    
    cout << "Ingrese el país del atleta: ";
    cin.getline(athlete.pais, 30);
    
    cout << "Ingrese la edad del atleta: ";
    cin >> athlete.edad;
    
    cout << "Ingrese el tiempo en segundos del atleta: ";
    cin >> athlete.mejor_tiempo;
    
    cin.ignore(); 
    
    return athlete;
}

void mostrar_menor(vector<Atleta>& athlete)
{
    int menor = 0;

    for (size_t i = 1; i < athlete.size(); i++)
    {
        if (athlete[i].mejor_tiempo < athlete[menor].mejor_tiempo)
        {
            menor = i;
        }
    }

    cout << "\n El atleta con el mejor tiempo es:\n";
    cout << "Nombre: " << athlete[menor].nombre << endl;
    cout << "País: " << athlete[menor].pais << endl;
    cout << "Tiempo: " << athlete[menor].mejor_tiempo << " segundos" << endl;
}