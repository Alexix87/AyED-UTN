#include <iostream>
using namespace std;

bool esValido(int n){
    return n>=0;
}

int factorialIterativo(int n){
    int acumulador = 1;
    for (int i = n; i>0 ; i--)
        acumulador = acumulador * i;
    return acumulador;
}

int factorialRecursivo(int n){
    if (n == 0) return 1;
    return n * factorialRecursivo(n-1);
}

int main(){
    int n, opcion, fact;

    do{
        system("cls");
        cout << "Ingrese n: ";
        cin >> n;
    }while(!esValido(n));

    do{
        system("cls");
        cout << "Seleccione el modo de calcular el factorial: " << endl;
        cout << "1 ----- Iterativa" << endl;
        cout << "2 ----- Recursiva" << endl;
        cin >> opcion;
    }while (opcion != 1 && opcion != 2);

    switch(opcion){
        case 1: 
            fact = factorialIterativo(n);
            break;
        case 2: 
            fact = factorialRecursivo(n);
            break;
    }

    cout << "El factorial de " << n << " es: " << fact << endl;
    system("pause");
    return 0;
}