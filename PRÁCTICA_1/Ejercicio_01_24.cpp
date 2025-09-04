// Materia: Programación I, Paralelo 4
// Autor: Belen Manrrique Mamani
// Carnet: 9978843 L.P.
// Carrera del estudiante: Ingeniería Industrial
// Fecha creación: 04/09/2025
// Número de ejercicio: 24
#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    int opcion = 0;
    do
    {
        cout << "1. Opcion 1 \n2. Opcion 2 \n3. Opcion 3 \n0. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Seleccionó la opción 1" << endl;
            break;
        case 2:
            cout << "Seleccionó la opción 2" << endl;
            break;;
        case 3:
            cout << "Seleccionó la opción 3" << endl;
            break;
        case 0:
            cout << "Saliendo...";
            break;;
        default:
            cout << "Opción inválida";
            break;
        }
    } while (opcion != 0);
    return 0;
}