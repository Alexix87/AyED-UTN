#include <iostream>
#include <math.h>
using namespace std;

void ingresarValores(int &a, int &b){
    system("cls");
    cout << "Ingrese a: ";
    cin >> a;
    cout << "Ingrese b: ";
    cin >> b;
}

bool esValido(int a, int b){
    if ( a<0 || b<0 || (a==0 && b==0)) return false;
    return true;
}

int main(){
    int a,b;
    do{
        ingresarValores(a,b);
    }while(!esValido(a,b));

    cout << a << " elevado a la " << b << " = " << pow (a,b) << endl;
    system("pause");

    return 0;
}