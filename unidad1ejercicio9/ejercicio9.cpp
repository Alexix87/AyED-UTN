#include <iostream>
using namespace std;

void ingresar(int &n){
    system("cls");
    cout << "Ingrese el valor de n: ";
    cin >> n;
}

bool esValido(int n){
    return n>=0;
}

int main(){
    int n;
    do{
        ingresar(n);
    } while (!esValido(n));

    cout << "La sumatoria es: " << (n*(n+1))/2 << endl;
    
    system("pause");
    return 0;
}