#include <iostream>
using namespace std;

void ingresar(int &n){
    system("cls");
    cout << "Ingresar valor n: ";
    cin >> n;
}

bool esValido(int n){
    return (n>=0);
}

int main(){
    int n;
    int acumulador = 0;

    do{
        ingresar(n);
    } while(!esValido(n));

    for (int i = 0; i<=n; i++)
        acumulador += i;

    cout << "La sumatoria es: " << acumulador << endl;
    system("pause");

    return 0;
}