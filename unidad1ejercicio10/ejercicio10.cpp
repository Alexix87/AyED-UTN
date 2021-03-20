#include <iostream>
using namespace std;

void ingresar(int &n){
    system("cls");
    cout << "Ingresar un valor n: ";
    cin >> n;
}

bool esValido(int n){
    return (n>=0);
}

void mostrarTerminosFibo(int n){
    int anterior1, anterior2, nuevoTerminoFibo;
    system("cls");

    switch (n){
        case 0: 
            cout << "El valor de n es cero! \n";
            break;
        case 1: 
            cout << "1\n";
            break;
        case 2: 
            cout << "1 1\n";
            break;
        default:
            anterior1 = 1;
            anterior2 = 1;
            cout << "1 1 ";
            for (int i= 2; i<n; i++){
                nuevoTerminoFibo = anterior2 + anterior1;
                cout << nuevoTerminoFibo << " ";
                anterior2 = anterior1;
                anterior1 = nuevoTerminoFibo;
            }
            cout << endl;

    }
    system("pause");
}


int main(){
    int n;

    do{
        ingresar(n);
    }while(!esValido(n));

    mostrarTerminosFibo(n);
    return 0;
}