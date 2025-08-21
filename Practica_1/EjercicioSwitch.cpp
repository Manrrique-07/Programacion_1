#include <iostream>
using namespace std;

int main()
{
    int dia;
    system("chcp 65001");
    system("cls");
    cout << "Ingrese el dia";
    cin >> dia;
    switch (dia)
    {
        case 1:
            cout << "LUNES";
            break;
        case 2:
            cout << "MARTES";
            break;
        case 3:
            cout << "MIERCOLES";
            break;
        case 4:
            cout << "JUEVES";
            break;
        case 5:
            cout << "VIERNES";
            break;
        case 6:
            cout << "SABADO";
            break;
        case 7:
            cout << "DOMINGO";
            break;
        default:
            cout << "Valor de dia incorrecto";
            break;
    }
    return 0;
}