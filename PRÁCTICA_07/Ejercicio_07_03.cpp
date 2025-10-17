// Materia: Programación I, Paralelo 4
// Autor: Manrrique Mamani Fabiola Belen
// Fecha creación: 15/10/2024
// Número de ejercicio: 3

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Mostrar(int ar[100][100]);
void filas(int ar[100][100]);
void columnas(int ar[100][100]);
void coordenadas(int ar[100][100]);
int cantidad_muertos(int ar[100][100]);
void complejo(int ar[100][100]);

int main()
{
    srand(time(0));
    int area[100][100];
    int muertos_vivientes = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            area[i][j] = (rand()%(2-1+1))+1;
        }   
    }
    Mostrar(area);
    filas(area);
    cout << endl;
    columnas(area);
    cout << endl;
    coordenadas(area);
    muertos_vivientes = cantidad_muertos(area);
    cout << "Cantidad de muertos vivientes den la matriz: " << muertos_vivientes << endl;
    complejo(area);
    
    return 0;
}

void Mostrar(int ar[100][100])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ar[i][j] == 1)
            {
                cout << "X" << " ";
            }
            else
            {
                cout << "O" << " ";
            }
            
        }
        cout << endl;
    }
}

void filas(int ar[100][100])
{
    cout << "filas libres: ";
    int cont_fil1 = 0;
    int cont_fil2 = 0;
    int cont_fil3 = 0;

    for (int j = 0; j < 4; j++)
    {
        if (ar[0][j] == 2)
        {
            cont_fil1+=1;
            if (cont_fil1 == 4)
            {
                cout << "1 ";
            }   
        }     
    }

    for (int j = 0; j < 4; j++)
    {
        if (ar[1][j] == 2)
        {
            cont_fil2+=1;
            if (cont_fil2 == 4)
            {
                cout << "2 ";
            }   
        }   
    }

    for (int j = 0; j < 4; j++)
    {
        if (ar[2][j] == 2)
        {
            cont_fil3+=1;
            if (cont_fil3 == 4)
            {
                cout << "3 ";
            }   
        }         
    }
}

void columnas(int ar[100][100])
{
    cout << "Columnas libres: ";
    int cont_col1 = 0;
    int cont_col2 = 0;
    int cont_col3 = 0;
    int cont_col4 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (ar[i][0] == 2)
        {
            cont_col1+=1;
            if (cont_col1 == 3)
            {
                cout << "1 ";
            }   
        }     
    }

    for (int i = 0; i < 3; i++)
    {
        if (ar[i][1] == 2)
        {
            cont_col2+=1;
            if (cont_col2 == 3)
            {
                cout << "2 ";
            }   
        }     
    }

    for (int i = 0; i < 3; i++)
    {
        if (ar[i][2] == 2)
        {
            cont_col3+=1;
            if (cont_col3 == 3)
            {
                cout << "3 ";
            }   
        }     
    }

    for (int i = 0; i < 3; i++)
    {
        if (ar[i][3] == 2)
        {
            cont_col4+=1;
            if (cont_col4 == 3)
            {
                cout << "4 ";
            }   
        }     
    }
}

void coordenadas(int ar[100][100])
{
    cout << "Posiciones de los muertos vivientes: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ar[i][j] == 1)
            {
                cout << i << " --- " << j << endl;
            }
        }
    }
}

int cantidad_muertos(int ar[100][100])
{
    int cantidad = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ar[i][j] == 1)
            {
                cantidad+=1;
            }
        }
    }
    return cantidad;
}

void complejo(int ar[100][100])
{
    int cont_muertos = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ar[i][0] == 1)
        {
            cont_muertos+=1;
            if (cont_muertos >= 2)
            {
                cout << "No es posible entrar al complejo" << endl;
            }
            else
            {
                cout << "Es posible entrar al complejo" << endl;
            }   
        }
    }
}