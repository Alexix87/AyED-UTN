#include <iostream>
using namespace std;

void ingresar(int &n){
    system("cls");
    cout << "Ingresar valor de n: ";
    cin >> n;
}

bool esValido(int n){
    return (n>0);
}

int fibonacci(int i){
    int anterior1 = 1;
    int anterior2 = 1;
    int aux;
    int resultado;

    switch(i){
        case 1: 
            resultado = 1;
            break;
        case 2: 
            resultado = 1;
            break;
        default: 
            for (int k = 2; k<i; k++ ){
                resultado = anterior1 + anterior2;
                anterior2 = anterior1;
                anterior1 = resultado;
            }
    }
    return resultado;
}

int sumarFiboHasta(int n){
    int resultado = 0;
    int aux = 1;
    switch (n){
    case 1:
        resultado = 1;
        break;
    case 2: 
        resultado = 2;
        break;
    default:
        while(resultado < n){
            resultado += fibonacci(aux);
            aux++;
        }
    }
    return resultado;
}

int main(){
    int n,rta;

    do{
        ingresar(n);
    } while(!esValido(n));

    rta = sumarFiboHasta(n);

 //   system("cls");
    cout << "La sumatoria de terminos Fibonacci hasta superar a " << n << " es: " << rta << endl;
    system("pause");

    return 0;
}