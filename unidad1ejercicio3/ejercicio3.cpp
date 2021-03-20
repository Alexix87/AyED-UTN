#include <iostream>
#include <math.h>
using namespace std;

void ingresarCatetos(float &cateto1, float &cateto2){
    do{
        system("cls");
        cout << "Ingresar cateto 1: ";
        cin >> cateto1;
        cout << "Ingresar cateto 2: ";
        cin >> cateto2;
    } while (!(cateto1 > 0 && cateto2 > 0));
}

float calcularSuperficie(float unValor){
    return pow(unValor,2); 
}

float calcularSuperficieCondicionada(float hipotenusa){
    float superficie;
    if(hipotenusa > 100)
        superficie = calcularSuperficie(hipotenusa);
    else   
        superficie = calcularSuperficie(2*hipotenusa);
    return superficie;
}

void mostrarResultado(float hipotenusa, float superficie){
    cout << "Respuesta del ejercicio: \n"; 
    cout << "La hipotenusa es: " << hipotenusa << " y la superficie: " << superficie << endl;    
    system("pause");
}

int main(){
    float cateto1, cateto2;
    float hipotenusa, superficie;

    ingresarCatetos(cateto1, cateto2);
    hipotenusa = hypot(cateto1,cateto2);
    superficie = calcularSuperficieCondicionada(hipotenusa);
    mostrarResultado(hipotenusa,superficie);
    return 0;
}