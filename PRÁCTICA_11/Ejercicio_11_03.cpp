// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 11-11-2025 
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct Pizza 
{
    int codigo;
    char nombre[30];
    char tipo[15];    
    char tam[15];     
    float precio;
};

void menu();
void adicionarPizza();
void listarPizzas();
void modificarPrecio();
void eliminarPizza();
void adicionarVenta();
float obtenerPrecioFinal(const Pizza& p);
int obtenerVentas(int codigo, string tam);
float obtenerTotal(int codigo, string tam);

int main() 
{
    menu();
    return 0;
}

void menu() 
{
    int op;
    do 
    {
        cout << "\n===== MENU PIZZERIA ELIS =====\n";
        cout << "1. Adicionar Pizza\n";
        cout << "2. Listado de Pizzas\n";
        cout << "3. Modificar el precio de la Pizza\n";
        cout << "4. Eliminar una Pizza\n";
        cout << "5. Adicionar Venta de Pizzas\n";
        cout << "6. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> op;

        switch (op) 
        {
            case 1: adicionarPizza(); break;
            case 2: listarPizzas(); break;
            case 3: modificarPrecio(); break;
            case 4: eliminarPizza(); break;
            case 5: adicionarVenta(); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida\n"; break;
        }

    } while (op != 6);
}

void adicionarPizza() 
{
    Pizza p;
    ofstream file("PRODUCTO.BIN", ios::binary | ios::app);

    cout << "Codigo: "; cin >> p.codigo;
    cin.ignore();
    cout << "Nombre: "; cin.getline(p.nombre, 30);
    cout << "Tipo (TRADICIONAL / ESPECIAL): "; cin.getline(p.tipo, 15);
    cout << "Tamaño (XS / MEDIANA / GRANDE / FAMILIAR / INTERMINABLE): ";
    cin.getline(p.tam, 15);
    cout << "Precio base (TRADICIONAL): "; cin >> p.precio;

    if (strcmp(p.tipo, "ESPECIAL") == 0) {
        p.precio *= 1.10; 
    }

    file.write((char*)&p, sizeof(Pizza));
    file.close();

    cout << "Pizza añadida correctamente.\n";
}

void listarPizzas() 
{
    ifstream file("PRODUCTO.BIN", ios::binary);

    if (!file) 
    {
        cout << "No existe el archivo PRODUCTO.BIN\n";
        return;
    }

    Pizza p;

    cout << "\n===== LISTADO DE PIZZAS =====\n";
    cout << "CODIGO | NOMBRE | TIPO | TAMANO | PRECIO | CANTIDAD | TOTAL\n";

    while (file.read((char*)&p, sizeof(Pizza))) 
    {
        int cant = obtenerVentas(p.codigo, p.tam);
        float total = cant * p.precio;

        cout << p.codigo << " | "
             << p.nombre << " | "
             << p.tipo << " | "
             << p.tam << " | "
             << p.precio << " | "
             << cant << " | "
             << total << endl;
    }

    file.close();
}

void modificarPrecio() {
    fstream file("PRODUCTO.BIN", ios::binary | ios::in | ios::out);

    if (!file) 
    {
        cout << "No existe PRODUCTO.BIN\n";
        return;
    }

    int cod;
    cout << "Ingrese codigo de pizza a modificar: ";
    cin >> cod;

    Pizza p;
    bool encontrado = false;

    while (!file.eof()) 
    {
        streampos pos = file.tellg();
        file.read((char*)&p, sizeof(Pizza));

        if (file.eof()) break;

        if (p.codigo == cod) 
        {
            cout << "Precio actual: " << p.precio << endl;
            cout << "Nuevo precio base TRADICIONAL: ";
            cin >> p.precio;

            if (strcmp(p.tipo, "ESPECIAL") == 0)
                p.precio *= 1.10;

            file.seekp(pos);
            file.write((char*)&p, sizeof(Pizza));

            cout << "Precio actualizado.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) cout << "Pizza no encontrada.\n";

    file.close();
}

void eliminarPizza() 
{
    ifstream file("PRODUCTO.BIN", ios::binary);
    ofstream temp("TEMP.BIN", ios::binary);

    if (!file) 
    {
        cout << "No existe PRODUCTO.BIN\n";
        return;
    }

    int cod;
    cout << "Codigo a eliminar: ";
    cin >> cod;

    Pizza p;
    bool borrado = false;

    while (file.read((char*)&p, sizeof(Pizza))) 
    {
        if (p.codigo == cod) 
        {
            borrado = true;
        } else 
        {
            temp.write((char*)&p, sizeof(Pizza));
        }
    }

    file.close();
    temp.close();

    remove("PRODUCTO.BIN");
    rename("TEMP.BIN", "PRODUCTO.BIN");

    if (borrado)
        cout << "Pizza eliminada.\n";
    else
        cout << "No se encontro el codigo.\n";
}

void adicionarVenta() 
{
    ofstream file("VENTAS.txt", ios::app);

    string ci, tam;
    int cod, cant;

    cin.ignore();
    cout << "CI Cliente: ";
    getline(cin, ci);
    cout << "Codigo Pizza: ";
    cin >> cod;
    cin.ignore();
    cout << "Tamaño: ";
    getline(cin, tam);
    cout << "Cantidad vendida: ";
    cin >> cant;

    file << ci << ";" << cod << ";" << tam << ";" << cant << endl;

    file.close();

    cout << "Venta registrada.\n";
}

int obtenerVentas(int codigo, string tam) 
{
    ifstream file("VENTAS.txt");
    if (!file) return 0;

    string linea;
    int total = 0;

    while (getline(file, linea)) 
    {
        int pos1 = linea.find(";");
        int pos2 = linea.find(";", pos1 + 1);
        int pos3 = linea.find(";", pos2 + 1);

        int cod = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        string t = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        int cantidad = stoi(linea.substr(pos3 + 1));

        if (cod == codigo && t == tam) 
        {
            total += cantidad;
        }
    }

    file.close();
    return total;
}