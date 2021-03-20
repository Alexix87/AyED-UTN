#include <iostream>
using namespace std;

void ingresar(int &valor){
    cout << "Ingresar valor: ";
    cin >> valor;
}

bool esValido(int a, int b){
    return (a!=b);
}

void mostrar(int valor1, int valor2){
    cout << "El mayor es: " << valor1 << " y el menor es: " << valor2 << endl;
}

void compararYmostrar(int a, int b){
    (a>b) ? mostrar(a,b) : mostrar(b,a);
}

int main(){
    int a, b;
    
    do{
        ingresar(a);
        ingresar(b);
    }while(!esValido(a,b));

    compararYmostrar(a,b);
    system("pause");
    return 0;
}
