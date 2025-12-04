// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Carnet: 9978843
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 28/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct product
{
    char nombre[50];
    char codigo[50];
    double precio;
    int cantidad_inventario;
    char observaciones[50];
};

product Llenar();
void producto_mas_caro(vector<product>productos);
void Mostrar(vector<product>productos, int ind);
void inventario_total(vector<product>productos);

int main()
{
    vector<product>productos;
    int N;
    cout << "Ingrese la cantidad de productos: ";
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin.ignore();  
        cout << endl;
        productos.push_back(Llenar());
        cout << endl; 
    }
    producto_mas_caro(productos);
    inventario_total(productos);
}

product Llenar()
{
    product producto;
    cout << "Ingrese el nombre del producto: ";
    cin.getline(producto.nombre, 50);
    cout << "Ingrese el código: ";
    cin.getline(producto.codigo, 50);
    cout << "Ingrese el precio: ";
    cin >> producto.precio;
    cout << "Ingrese la cantidad en el inventario: ";
    cin >> producto.cantidad_inventario;
    if (producto.cantidad_inventario < 5)
    {
        strcpy(producto.observaciones, "PRUDUCTO CON BAJA CANTIDAD DE INVENTARIO");
    }
    else
    {
        strcpy(producto.observaciones, " ");
    }
    return producto;
}

void producto_mas_caro(vector<product>productos)
{
    double precio_mayor;
    int ind = 0;
    for (int i = 0; i < productos.size(); i++)
    {
        if (productos[i].precio > precio_mayor)
        {
            precio_mayor = productos[i].precio;
            ind = i;
        }   
    }
    cout << "--------------PRODUCTO MAS CARO------------" << endl;
    Mostrar(productos, ind);
}

void Mostrar(vector<product>productos, int ind)
{
    cout << "\tNombre del producto: " << productos[ind].nombre << endl;
    cout << "\tCódigo: " << productos[ind].codigo << endl;
    cout << "\tPrecio del producto: " << productos[ind].precio << endl;
    cout << "\tCantidad en el inventario: " << productos[ind].cantidad_inventario << endl;
    cout << "\tObservaciones: " << productos[ind].observaciones << endl;
}

void inventario_total(vector<product>productos)
{
    int inv_total = 0;
    for (int i = 0; i < productos.size(); i++)
    {
        inv_total = inv_total + productos[i].cantidad_inventario;
    }
    
    cout << "Cantidad total de productos en el inventario: " << inv_total << endl;
}