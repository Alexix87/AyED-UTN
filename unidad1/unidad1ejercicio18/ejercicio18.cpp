#include <iostream>
using namespace std;

//maximo comun divisor
int mcd(int a, int b){
    int resto;
    while (b!=0){
        resto = a%b;
        a = b;
        b = resto;
    }
    return a;
}

int main(){

    int a,b;

    do{
        system("cls");
        cout << "Ingrese a: ";
        cin >> a;
        cout << "Ingrese b: ";
        cin >> b;
    }while(a<=0 || b<=0);

    cout << "El MCD entre " << a << " y " << b << " es: " << mcd(a,b) << endl;
    system("pause");
    return 0;
}