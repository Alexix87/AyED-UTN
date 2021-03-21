#include <iostream>
using namespace std;

void ingresar(int &unValor, char* texto){
    cout << texto;
    cin >> unValor;
    cout << endl;
}
bool esValido(int n){
    return n>0;
}

int main(){
    int n,valor,x,indice;
    
    do{
        ingresar(n,"Cantidad de valores a ingresar: ");
    }while(!esValido(n));

    ingresar(x,"Valor a buscar: ");

    indice = 0;

    for(int i = 1; i<=n; i++ ){
        ingresar(valor,"Ingrese valor: ");
        if (valor == x) indice = i;
    }

    if (indice)
        cout << "El valor buscado esta en la posicion: " << indice;
    else
        cout << "El valor buscado NO se encuentra!";

    cout << endl;
    system("pause");
    return 0;
}