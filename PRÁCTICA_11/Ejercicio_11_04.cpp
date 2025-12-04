// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 11-11-2025 
// Número de ejercicio: 4

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

struct Estudiante 
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
    char materia[40];
    int paralelo;
};

void menu();
void adicionarEstudiante();
void listarEstudiantesHabilitados();
void eliminarEstudiante();
void adicionarNotasHabilitacion();

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
        cout << "\n===== MENU NOTAS UCB =====\n";
        cout << "1. Adicionar Estudiante\n";
        cout << "2. Listado de Estudiantes Habilitados\n";
        cout << "3. Eliminar un Estudiante\n";
        cout << "4. Adicionar notas habilitacion\n";
        cout << "5. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> op;

        switch(op) 
        {
            case 1: adicionarEstudiante(); break;
            case 2: listarEstudiantesHabilitados(); break;
            case 3: eliminarEstudiante(); break;
            case 4: adicionarNotasHabilitacion(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(op != 5);
}

bool existeCI(const char* ci) 
{
    ifstream file("ESTUDIANTES.BIN", ios::binary);
    Estudiante e;

    while (file.read((char*)&e, sizeof(Estudiante))) 
    {
        if (strcmp(e.ci, ci) == 0) return true;
    }
    return false;
}

void adicionarEstudiante() 
{
    Estudiante e;
    ofstream file("ESTUDIANTES.BIN", ios::binary | ios::app);

    cin.ignore();
    cout << "Carnet: ";
    cin.getline(e.ci, 10);

    if (existeCI(e.ci)) 
    {
        cout << "ERROR: Ya existe un estudiante con ese CI.\n";
        return;
    }

    cout << "Nombres: ";
    cin.getline(e.nombres, 30);
    cout << "Apellidos: ";
    cin.getline(e.apellidos, 30);
    cout << "Materia: ";
    cin.getline(e.materia, 40);
    cout << "Paralelo: ";
    cin >> e.paralelo;

    file.write((char*)&e, sizeof(Estudiante));
    file.close();

    cout << "Estudiante registrado exitosamente.\n";
}

struct Nota 
{
    string ci;
    string materia;
    int paralelo;
    float nota;
    float porcentaje;
};

float calcularNotaFinal(const vector<Nota>& notas) 
{
    float total = 0;
    for (auto& n : notas)
        total += (n.nota * n.porcentaje) / 100.0;
    return total;
}

bool todasNotasMayores60(const vector<Nota>& notas) 
{
    for (auto& n : notas)
        if (n.nota < 60)
            return false;
    return true;
}

vector<Nota> obtenerNotas(string ci, string materia, int paralelo) 
{
    ifstream f("HABILITACION.txt");
    vector<Nota> lista;
    string linea;

    while (getline(f, linea)) 
    {
        size_t p1 = linea.find(";");
        size_t p2 = linea.find(";", p1 + 1);
        size_t p3 = linea.find(";", p2 + 1);
        size_t p4 = linea.find(";", p3 + 1);

        string c = linea.substr(0, p1);
        string mat = linea.substr(p1 + 1, p2 - p1 - 1);
        int par = stoi(linea.substr(p2 + 1, p3 - p2 - 1));
        float nota = stof(linea.substr(p3 + 1, p4 - p3 - 1));
        float porc = stof(linea.substr(p4 + 1));

        if (c == ci && mat == materia && par == paralelo) 
        {
            Nota n { c, mat, par, nota, porc };
            lista.push_back(n);
        }
    }
    return lista;
}

void listarEstudiantesHabilitados() 
{
    ifstream file("ESTUDIANTES.BIN", ios::binary);

    if (!file) 
    {
        cout << "No existe el archivo ESTUDIANTES.BIN\n";
        return;
    }

    Estudiante e;
    float sumaNotas = 0;
    int cuenta = 0;

    cout << "\n===== LISTADO DE ESTUDIANTES HABILITADOS =====\n";

    while (file.read((char*)&e, sizeof(Estudiante))) 
    {
        vector<Nota> notas = obtenerNotas(e.ci, e.materia, e.paralelo);

        if (notas.size() == 0) continue;

        float notaFinal = calcularNotaFinal(notas);
        bool habilitado = todasNotasMayores60(notas);

        cout << "\nCARNET: " << e.ci;
        cout << "\nNOMBRES: " << e.nombres;
        cout << "\nAPELLIDOS: " << e.apellidos;
        cout << "\nMATERIA: " << e.materia;
        cout << "\nPARALELO: " << e.paralelo;
        cout << "\nNOTA HABILITACION: " << notaFinal;

        if (habilitado) 
        {
            cout << "\nESTADO: HABILITADO\n";
            sumaNotas += notaFinal;
            cuenta++;
        } else 
        {
            cout << "\nESTADO: NO HABILITADO (TIENE UNA NOTA < 60)\n";
        }
    }

    if (cuenta > 0) 
    {
        cout << "\nPROMEDIO GENERAL HABILITACION = "
             << (sumaNotas / cuenta) << endl;
    } else 
    {
        cout << "\nNo existen estudiantes habilitados.\n";
    }

    file.close();
}

void eliminarEstudiante() 
{
    ifstream file("ESTUDIANTES.BIN", ios::binary);
    ofstream temp("TEMP.BIN", ios::binary);

    if (!file) 
    {
        cout << "No existe ESTUDIANTES.BIN\n";
        return;
    }

    char ci[10];
    cin.ignore();
    cout << "Ingrese CI a eliminar: ";
    cin.getline(ci, 10);

    Estudiante e;
    bool encontrado = false;

    while (file.read((char*)&e, sizeof(Estudiante))) 
    {
        if (strcmp(e.ci, ci) == 0) 
        {
            encontrado = true;
        } else 
        {
            temp.write((char*)&e, sizeof(Estudiante));
        }
    }

    file.close();
    temp.close();

    remove("ESTUDIANTES.BIN");
    rename("TEMP.BIN", "ESTUDIANTES.BIN");

    if (encontrado)
        cout << "Estudiante eliminado.\n";
    else
        cout << "No existe ese CI.\n";
}

void adicionarNotasHabilitacion() 
{
    ofstream file("HABILITACION.txt", ios::app);
    string ci, materia;
    int par;
    float nota, porc;

    cin.ignore();
    cout << "CI: ";
    getline(cin, ci);
    cout << "Materia: ";
    getline(cin, materia);
    cout << "Paralelo: "; 
    cin >> par;
    cout << "Nota: ";
    cin >> nota;
    cout << "Porcentaje: ";
    cin >> porc;

    file << ci << ";" << materia << ";" << par << ";" << nota << ";" << porc << endl;
    file.close();

    cout << "Nota registrada.\n";
}