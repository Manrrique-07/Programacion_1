// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct movie
{
    char titulo[30];
    char director[30];
    int duracion;
    int anio_estreno;
    char genero[30];
};

movie Llenar_datos_pelicula();
void Mismo_genero(vector<movie>&pelicula);
void Mismo_director(vector<movie>&pelicula);
void Mostrar_datos(vector<movie>&pelicula, int ind);

int main()
{
    system("chcp 65001");
    vector<movie>pelicula;
    int N;
    cout << "Ingrese la cantidad de películas: ";
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        cout << "Pélicula " << i+1 << endl;
        pelicula.push_back(Llenar_datos_pelicula());
    }
    cout << endl;
    Mismo_genero(pelicula);
    cout << endl;
    Mismo_director(pelicula);
    return 0;
}

movie Llenar_datos_pelicula()
{
    movie pelicula;
    cout << "Ingrese el título: ";
    cin.getline(pelicula.titulo,30);
    cout << "Ingrese el director: ";
    cin.getline(pelicula.director,30);
    cout << "Ingrese la duración: ";
    cin >> pelicula.duracion;
    cout << "Ingrese el año de estreno: ";
    cin >> pelicula.anio_estreno;
    cin.ignore();
    cout << "Ingrese el género: ";
    cin.getline(pelicula.genero,30);
    return pelicula;
}

void Mismo_genero(vector<movie>&pelicula)
{
    char genero[30];
    cout << "Ingrese el género que desea buscar: ";
    cin.getline(genero,30);
    for (int i = 0; i < pelicula.size(); i++)
    {
        if (strcmp(pelicula[i].genero, genero) == 0)
        {
             Mostrar_datos(pelicula, i);
        }
    }
}

void Mismo_director(vector<movie>&pelicula)
{
    char director[30];
    cout << "Ingrese el director que desea buscar: ";
    cin.getline(director,30);
    for (int i = 0; i < pelicula.size(); i++)
    {
        if (strcmp(pelicula[i].director, director) == 0)
        {
             Mostrar_datos(pelicula, i);
        }
    }   
}

void Mostrar_datos(vector<movie>&pelicula, int ind)
{
    cout << "\tTítulo: " << pelicula[ind].titulo << endl;
    cout << "\tDirector: " << pelicula[ind].director << endl;
    cout << "\tDuración: " << pelicula[ind].duracion << endl;
    cout << "\tAño de estreno: " << pelicula[ind].anio_estreno << endl;
    cout << "\tGénero: " << pelicula[ind].genero << endl;
    cout << endl;
}