// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 11-11-2025 
// Número de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Producto 
{
    int codigo;
    char nombre[30];
    int cantidadInicial;
    float precio;
};

struct VentaTXT 
{
    string ci;
    string nombreCliente;
    int codigoProducto;
    int cantidadVendida;
};

void adicionarProducto();
bool existeProducto(int codigo);
void listarProductos();
void buscarProducto();
void modificarProducto();
void adicionarVenta();
int cantidadVendidaTotal(int codigo);

int main() 
{
    int opc;
    do 
    {
        cout << "\n=========== MENU FARMACIAS CHAVEZ ===========\n";
        cout << "1. Adicionar Producto\n";
        cout << "2. Listado de Productos\n";
        cout << "3. Buscar un producto por codigo\n";
        cout << "4. Modificar un producto\n";
        cout << "5. Adicionar ventas del producto\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;

        cin.ignore();

        switch(opc) 
        {
            case 1: adicionarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProducto(); break;
            case 4: modificarProducto(); break;
            case 5: adicionarVenta(); break;
            case 6: break;
            default: cout << "Opcion invalida.\n";
        }

    } while(opc != 6);

    return 0;
}

bool existeProducto(int codigo) 
{
    ifstream file("PRODUCTOS.BIN", ios::binary);
    if (!file) return false;

    Producto p;
    while (file.read((char*)&p, sizeof(p))) 
    {
        if (p.codigo == codigo) 
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void adicionarProducto() 
{
    Producto p;

    cout << "Ingrese codigo del producto: ";
    cin >> p.codigo;
    cin.ignore();

    if (existeProducto(p.codigo)) 
    {
        cout << "ERROR: El producto con ese código ya existe.\n";
        return;
    }

    cout << "Ingrese nombre del producto: ";
    cin.getline(p.nombre, 30);

    cout << "Ingrese cantidad inicial: ";
    cin >> p.cantidadInicial;

    cout << "Ingrese precio unitario: ";
    cin >> p.precio;

    ofstream file("PRODUCTOS.BIN", ios::binary | ios::app);
    file.write((char*)&p, sizeof(p));
    file.close();

    cout << "Producto registrado correctamente.\n";
}

void listarProductos() 
{
    ifstream file("PRODUCTOS.BIN", ios::binary);
    if (!file) 
    {
        cout << "No existen productos registrados.\n";
        return;
    }

    cout << "\nCODIGO  NOMBRE             C.INI  PRECIO  VENDIDO  TOTAL\n";

    Producto p;
    while (file.read((char*)&p, sizeof(p))) 
    {
        int vendido = cantidadVendidaTotal(p.codigo);
        float total = vendido * p.precio;

        cout << p.codigo << "   "
             << p.nombre << "   "
             << p.cantidadInicial << "   "
             << p.precio << "   "
             << vendido << "   "
             << total << endl;
    }

    file.close();
}

int cantidadVendidaTotal(int codigo) 
{
    ifstream file("VENTAS.txt");
    if (!file) return 0;

    string linea;
    int total = 0;

    while (getline(file, linea)) 
    {
        VentaTXT v;
        int pos1 = linea.find(';');
        int pos2 = linea.find(';', pos1 + 1);
        int pos3 = linea.find(';', pos2 + 1);

        v.ci = linea.substr(0, pos1);
        v.nombreCliente = linea.substr(pos1 + 2, pos2 - pos1 - 2);
        v.codigoProducto = stoi(linea.substr(pos2 + 2, pos3 - pos2 - 2));
        v.cantidadVendida = stoi(linea.substr(pos3 + 2));

        if (v.codigoProducto == codigo) 
        {
            total += v.cantidadVendida;
        }
    }

    file.close();
    return total;
}

void buscarProducto() 
{
    int codigo;
    cout << "Ingrese el codigo a buscar: ";
    cin >> codigo;

    ifstream file("PRODUCTOS.BIN", ios::binary);
    if (!file) 
    {
        cout << "No existen productos.\n";
        return;
    }

    Producto p;
    bool encontrado = false;

    while (file.read((char*)&p, sizeof(p))) 
    {
        if (p.codigo == codigo) 
        {
            cout << "\nProducto encontrado:\n";
            cout << "Codigo: " << p.codigo << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Cantidad inicial: " << p.cantidadInicial << endl;
            cout << "Precio unitario: " << p.precio << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Producto NO encontrado.\n";

    file.close();
}

void modificarProducto() 
{
    int codigo;
    cout << "Ingrese el codigo del producto a modificar: ";
    cin >> codigo;
    cin.ignore();

    fstream file("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
    if (!file) 
    {
        cout << "Error al abrir archivo.\n";
        return;
    }

    Producto p;
    bool encontrado = false;

    while (file.read((char*)&p, sizeof(p))) 
    {
        if (p.codigo == codigo) 
        {
            encontrado = true;

            cout << "Nuevo nombre: ";
            cin.getline(p.nombre, 30);

            cout << "Nueva cantidad inicial: ";
            cin >> p.cantidadInicial;

            cout << "Nuevo precio: ";
            cin >> p.precio;

            long pos = file.tellg();
            file.seekp(pos - sizeof(p));
            file.write((char*)&p, sizeof(p));

            cout << "Producto modificado correctamente.\n";
            break;
        }
    }

    if (!encontrado)
        cout << "Producto no encontrado.\n";

    file.close();
}

void adicionarVenta() 
{
    VentaTXT v;

    cout << "Ingrese CI cliente: ";
    getline(cin, v.ci);

    cout << "Ingrese nombre cliente: ";
    getline(cin, v.nombreCliente);

    cout << "Ingrese codigo de producto: ";
    cin >> v.codigoProducto;

    if (!existeProducto(v.codigoProducto)) 
    {
        cout << "ERROR: El producto no existe.\n";
        return;
    }

    cout << "Ingrese cantidad vendida: ";
    cin >> v.cantidadVendida;

    ofstream file("VENTAS.txt", ios::app);
    file << v.ci << "; " << v.nombreCliente << "; " 
         << v.codigoProducto << "; " << v.cantidadVendida << endl;
    file.close();

    cout << "Venta registrada correctamente.\n";
}