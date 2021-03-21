#include <iostream>
using namespace std;

int main(){

    int cantidad = 0;
    int numero = 1;
    int suma;
    
    do{
        suma = 0;
        
        for (int i = 1; i<numero; i++)
            if(numero % i == 0)
                suma = suma + i;

        if (suma == numero){
            cout << numero << " es un numero perfecto" << endl;
            cantidad++;
        }

        numero++;

    }while(cantidad < 3);

    system("pause");
    return 0;
}