#include <iostream>
using namespace std;

void ingresar(int &n,char* texto){
    cout << texto;
    cin >> n;
    cout << endl;
}

bool esValido(int n){
    return (n>0);
}

int main(){
    int n,valor,maximo,indice;

    do{
        ingresar(n,"Cantidad de valores a ingresar: ");
        system("cls");
    }while(!esValido(n));

    ingresar(valor,"Ingresar valor: ");    
    maximo = valor;
    indice = 1;

    for(int i = n; i>1; i--){
        ingresar(valor,"Ingresar valor: ");
        if (valor>maximo){
            maximo = valor;
            indice = n-(i-2);
        }
    }

    cout << "El maximo es: " << maximo << endl;
    cout << "En la posicion: " << indice << endl;
    system("pause");

    return 0;
}