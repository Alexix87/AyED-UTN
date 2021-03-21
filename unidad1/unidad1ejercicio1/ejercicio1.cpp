#include <iostream>
#include <math.h>
using namespace std;

bool esValido(float valor){
    bool resultado;
    (valor > 0) ? (resultado = true) : (resultado = false);
    return resultado;
}

void ingresar (float &valor){
    do{
        cout << "ingresar un valor real: ";
        cin >> valor;
        cout << "\n";
    }while(!esValido(valor));
}

float calcularHipotenusa (float valor1, float valor2){
    return sqrt(pow(valor1,2)+pow(valor2,2));
}

void mostrarHipotenusa(float cateto1, float cateto2, float hipotenusa){
    cout.precision(3);
    cout << "La hipotenusa con catetos " << cateto1 << " y " << cateto2 << " es: " << hipotenusa << "\n"; 
    cout << "La misma cuenta pero hecha por libreria: " << hypot(cateto1,cateto2) << "\n";
}

int main(int argc, char const *argv[]){
    float cateto1, cateto2, hipotenusa;
   
    ingresar(cateto1);
    ingresar(cateto2);
    hipotenusa = calcularHipotenusa (cateto1,cateto2);
    mostrarHipotenusa(cateto1,cateto2,hipotenusa);
    system("pause");
    return 0;
}    