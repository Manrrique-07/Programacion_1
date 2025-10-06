// Materia: Programación I, Paralelo 4
// Autor: Fabiola Belen Manrrique Mamani
// Fecha creación: 03/10/2025
// Número de ejercicio: 1
// Problema planteado:
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

double Aleatorios(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

int Entero(int min, int max) {
    return min + rand() % (max - min + 1);
}

vector<double> generarVoltajes() {
    vector<double> voltajes(100);
    for (int i = 0; i < 100; i++) {
        voltajes[i] = Aleatorios(20.00, 220.00);
    }
    return voltajes;
}

vector<double> generarTemperaturas() {
    vector<double> temperaturas(50);
    for (int i = 0; i < 50; i++) {
        temperaturas[i] = Aleatorios(0.00, 100.00);
    }
    return temperaturas;
}

vector<char> generarCaracteres() {
    vector<char> caracteres(30);
    string alfanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 30; i++) {
        caracteres[i] = alfanum[Entero(0, alfanum.size()-1)];
    }
    return caracteres;
}

vector<int> generarAnios() {
    vector<int> anios(100);
    for (int i = 0; i < 100; i++) {
        anios[i] = Entero(1990, 2025);
    }
    return anios;
}

vector<double> generarVelocidades() {
    vector<double> velocidades(32);
    for (int i = 0; i < 32; i++) {
        velocidades[i] = Aleatorios(10.00, 300.00);
    }
    return velocidades;
}

vector<double> generarDistancias() {
    vector<double> distancias(1000);
    for (int i = 0; i < 1000; i++) {
        distancias[i] = Aleatorios(1.00, 1000.00);
    }
    return distancias;
}

int main() {
    srand(time(0)); 

    vector<double> voltajes = generarVoltajes();
    vector<double> temperaturas = generarTemperaturas();
    vector<char> caracteres = generarCaracteres();
    vector<int> anios = generarAnios();
    vector<double> velocidades = generarVelocidades();
    vector<double> distancias = generarDistancias();

    cout << "Ejemplos de voltajes: ";
    for (int i = 0; i < 5; i++) cout << voltajes[i] << " ";
    cout << "\n";

    cout << "Ejemplos de temperaturas: ";
    for (int i = 0; i < 5; i++) cout << temperaturas[i] << " ";
    cout << "\n";

    cout << "Ejemplos de caracteres: ";
    for (int i = 0; i < 10; i++) cout << caracteres[i] << " ";
    cout << "\n";

    cout << "Ejemplos de años: ";
    for (int i = 0; i < 5; i++) cout << anios[i] << " ";
    cout << "\n";

    cout << "Ejemplos de velocidades: ";
    for (int i = 0; i < 5; i++) cout << velocidades[i] << " ";
    cout << "\n";

    cout << "Ejemplos de distancias: ";
    for (int i = 0; i < 5; i++) cout << distancias[i] << " ";
    cout << "\n";

    return 0;
}