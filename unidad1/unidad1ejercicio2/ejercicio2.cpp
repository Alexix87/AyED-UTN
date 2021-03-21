#include <iostream>
using namespace std;

void ingresar(float &valor){
    cout << "Ingresar valor: ";
    cin >> valor;
}

bool esValido(float a, float b){
    return (a!=b);
}

void mostrar(float valor1, float valor2){
    cout << "El mayor es: " << valor1 << " y el menor es: " << valor2 << endl;
}

void compararYmostrar(float a, float b){
    (a>b) ? mostrar(a,b) : mostrar(b,a);
}

int main(){
    float a, b;
    
    do{
        ingresar(a);
        ingresar(b);
    }while(!esValido(a,b));

    compararYmostrar(a,b);
    system("pause");
    return 0;
}
