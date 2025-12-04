// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <string.h>

using namespace std;

struct Libro
{
    char titulo[30];
    char autor[30];
    int anio_publicacion;
    bool disponible;
};

Libro Ingresar_datos();
bool Disponible ();
void Mostrar(Libro book);

int main()
{
    Libro book;
    system("chcp 65001");
    book = Ingresar_datos();
    Mostrar(book);
    return 0;
}

Libro Ingresar_datos()
{
    Libro book; 
    cout<<"Ingrese el título del libro: ";
    cin.getline(book.titulo,30);
    cout<<"Ingrese el autor del libro: ";
    cin.getline(book.autor,30);
    cout<<"Ingrese el año de su publicación: ";
    cin>>book.anio_publicacion;
    cin.ignore();
    cout << "¿Está disponible (si/no)?: ";
    book.disponible = Disponible();
    return book;
}

bool Disponible ()
{
    char dis[3]; 
    cin.getline(dis, 3);

    if (strcmp(dis, "si") == 0 || strcmp(dis, "SI") == 0 || strcmp(dis, "Si") == 0)
        return true;
    else
        return false;   
}

void Mostrar(Libro book)
{
    cout << "\tTítulo: " << book.titulo << endl;
    cout << "\tAutor: " << book.autor << endl;
    cout << "\tAño de publicación: " << book.anio_publicacion << endl;
    cout << "\tDisponible: ";
    if (book.disponible)
    {
        cout << "si";
    }
    else
    {
        cout << "no";
    }
}