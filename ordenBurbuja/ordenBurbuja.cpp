#include <iostream>
#include <time.h>

using namespace std;

void generarVector(int vector[], int cantElementos){
    /* initialize random seed: */
    srand (time(NULL));
    for (int i=0; i<cantElementos; i++)
        vector[i] = rand() % 10 + 1;
}

void mostrarVector(int vector[], int cantElementos){
    for (int i=0; i<cantElementos; i++)
        cout << vector[i] << "\t";
    cout << endl;
}

void intercambiar(int &a,int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenarBurbuja(int vector[], int cantElementos){
    for (int i=0; i < cantElementos -1; i++)
        for (int j=0; j< cantElementos -1 -i; j++)
            if (vector[j]>vector[j+1])
                intercambiar(vector[j],vector[j+1]);
}

void ordenarBurbujaMostrando(int vector[], int cantElementos){
    for (int i=0; i<cantElementos-1; i++){
        for(int j=0; j<cantElementos -1 -i; j++){
            if (vector[j]>vector[j+1])
                intercambiar(vector[j],vector[j+1]);
            mostrarVector(vector,cantElementos);
        }
        cout << endl;
        mostrarVector(vector,cantElementos);
    }

}

int main(){

    const int cantElementos = 15;
    int vector[cantElementos];
    bool burbujaMostrando = true;

    generarVector(vector,cantElementos);
    mostrarVector(vector,cantElementos);
    (burbujaMostrando) ? ordenarBurbujaMostrando(vector,cantElementos) : ordenarBurbuja(vector,cantElementos);
    mostrarVector(vector,cantElementos);

    getchar();
    return 0;
}