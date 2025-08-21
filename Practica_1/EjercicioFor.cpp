#include <iostream>

using namespace std;

int main()
{
    int numero = 0;
    cout << "Ingrese un numero:";
    cin >>numero;
    for (int i = 1; i <= numero; i++)
    {
        if (i%2==0)
        {
            cout << i << "-";
        }
        
    }
    cout << endl;
    return 0;
}
    