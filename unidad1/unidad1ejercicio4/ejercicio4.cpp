#include <iostream>
#include <math.h>
using namespace std;

bool esValido(float a, float b){
    return (a>0 && b>0);
}

void ingresarTriangulo(float &cateto1,float &cateto2){
    system("cls");
    cout << "Ingresar cateto 1: ";
    cin >> cateto1;
    cout << "Ingresar cateto 2: ";
    cin >> cateto2;
}

int main(){
    float cateto1, cateto2, hipotenusa;
    float acumuladorHipotenusas = 0;
    unsigned int cantidadDeTriangulos=0;
    unsigned int cantidadDeTriangulosConHipotenusaMayorACien = 0;
    unsigned int cantidadDeTrianglusConHipotenusaMenorIgualACien = 0;

    ingresarTriangulo(cateto1,cateto2);

    while (esValido(cateto1,cateto2)){
        cantidadDeTriangulos++;
        hipotenusa = hypot(cateto1,cateto2);
        acumuladorHipotenusas =+ hipotenusa;

        if(hipotenusa > 100)
            cantidadDeTriangulosConHipotenusaMayorACien++;
        else
            cantidadDeTrianglusConHipotenusaMenorIgualACien++;
        
        ingresarTriangulo(cateto1,cateto2);
    }

    system("cls");
    cout << "Resultados: \n";
    cout << "Cantidad de triangulos : " << cantidadDeTriangulos << endl;
    if (cantidadDeTriangulos!=0){
        cout << "Promedio de hipotenusa: " << acumuladorHipotenusas/cantidadDeTriangulos << "\n" << endl;

        cout << "Con hipotenusas MAYORES a cien: \n";
        cout << "Cantidad de triangulos: " << cantidadDeTriangulosConHipotenusaMayorACien << endl;
        cout << "Porcentaje de triangulos: " << (cantidadDeTriangulosConHipotenusaMayorACien*100)/cantidadDeTriangulos << "%\n" << endl; 

        cout << "Con hipotenusa MENORES O IGUALES a cien: \n";
        cout << "Cantidad de triangulos: " << cantidadDeTrianglusConHipotenusaMenorIgualACien << endl;
        cout << "Porcentaje de triangulos: " << (cantidadDeTrianglusConHipotenusaMenorIgualACien*100)/cantidadDeTriangulos << "%\n" << endl;
    }
    system("pause");
    return 0;
}