// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 8

#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct athlete
{
    char nombre[50];
    int deparamento;
    int deporte;
    int medallas;
};

athlete LLenar_datos_atleta(vector<string>departamentos, vector<string>deportes);
void Mostrar_vector(vector<string>vec);
void Simulacion_olimpiadas(vector<athlete>atletas, vector<string>departamentos, vector<string>deportes);
int aleatorio(int superior, int inferior);
void Mostrar_medallero(vector<athlete>atletas, vector<string>departamentos);

int main()
{
    srand(time(0));
    vector<athlete>atletas;
    vector<string>departamentos = {"La Paz", "Potosi", "Oruro", "Cochabamba", "Tarija", "Chuquisaca", "Pando", "Beni", "Santa Cruz"};
    vector<string>deportes = {"Tiro con arco", "Atletismo", "Boxeo", "Ciclismo", "Natacion", "Esgrima"};
    Simulacion_olimpiadas(atletas, departamentos, deportes);
    return 0;
}

athlete LLenar_datos_atleta(vector<string>departamentos, vector<string>deportes)
{
    athlete atleta;
    cin.ignore();

    cout << "Ingrese el nombre del atleta: ";
    cin.getline(atleta.nombre, 50);
    
    Mostrar_vector(departamentos);
    cout << "Ingrese el numero de departamento que representa: ";
    cin >> atleta.deparamento;

    Mostrar_vector(deportes);
    cout << "Ingrese el numero del deporte que participa: ";
    cin >> atleta.deporte;

    atleta.medallas = aleatorio(5, 0);
    return atleta;
}

void Mostrar_vector(vector<string>vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i+1 << ". " << vec[i] << endl;
    }
    cout << endl;
}

void Simulacion_olimpiadas(vector<athlete>atletas, vector<string>departamentos, vector<string>deportes)
{
    int N = 0;
    cout << "Ingrese la cantidad de atletas: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        atletas.push_back(LLenar_datos_atleta(departamentos, deportes));
    }

    cout << "--------MEDALLERO FINAL---------" << endl;
    Mostrar_medallero(atletas, departamentos);
}

int aleatorio(int superior, int inferior)
{
    return (rand() % (superior-inferior+1))+inferior;
}

void Mostrar_medallero(vector<athlete>atletas, vector<string>departamentos)
{
    vector<int>Medallas_totales(departamentos.size(),0);
    int dep = 0;
    for (int i = 0; i < atletas.size(); i++)
    {
        dep = atletas[i].deparamento - 1;
        Medallas_totales[dep] += atletas[i].medallas;
    }
        
    for (int i = 0; i < departamentos.size(); i++)
    {
        cout << departamentos[i] << ": " << Medallas_totales[i] << " medallas" << endl;
    }
}   