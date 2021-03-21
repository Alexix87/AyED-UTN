#include <iostream>
using namespace std;

bool esValido(int n){
    return n>=0;
}

int factorial(int n){
    if (n==0) return 1;
    return (n*factorial(n-1));
}

float calcular_e(int n){
    float acumulador = 0;
    for (int i = 0; i <= n ; i++){
        acumulador = acumulador + 1.0/factorial(i);
        cout << "i vale: " << i << ", el 1.0/fact es: " << 1.0/factorial(i) << " y el acumulador es: " << acumulador << "\n";
    }
    return acumulador;
}

int main(){
    int n;
    float e;
    do{
        system("cls");
        cout << "Ingrese el valor n: ";
        cin >> n;
    } while (!esValido(n));

    e = calcular_e(n);

    cout << "El valor de e con " << n << " terminos es: " << e << endl;
    system("pause");

    return 0;
}