#include <iostream>
#include <time.h>
using namespace std;

void generarVector(int v[], int cant, int max){
    for(int i=0; i<cant; i++)
        v[i]=rand()%90+1;
}

void ordenarVector(int v[], int cant){
    int aux;
    for (int i=0; i<cant-1; i++)
        for (int j=0; j<cant-1-i; j++)
            if (v[j+1]<v[j]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
}

void mostrarVector(int v[], int cant, char* mensaje){
    cout << mensaje;
    for (int i=0; i<cant; i++)
        cout << v[i] << "\t";
    cout << "\n";
}

void merge(int p[], int q[], int r[], int cantP, int cantQ){
    int i;
    for (i=0; i<cantP; i++)
        r[i] = p[i];
    for (int j=0; j<cantQ; j++){
        r[i] = q[j];
        i++;
    }
}

int main(){
    const int cantP = 15;
    const int cantQ = 20;
    const int cantR = cantP + cantQ;
    int p[cantP], q[cantQ], r[cantR];
    int max = 90;
    char vecP[] = "Vector P: ";
    char vecQ[] = "Vector Q: ";
    char vecR[] = "Vector R: ";
    srand(time(NULL));
    generarVector(p,cantP,max);
    generarVector(q,cantQ,max);
    ordenarVector(p,cantP);
    ordenarVector(q,cantQ);
    merge(p,q,r,cantP,cantQ);
    ordenarVector(r,cantR);
    

    mostrarVector(p,cantP,vecP);
    mostrarVector(q,cantQ,vecQ);
    mostrarVector(r,cantR,vecR);
    system("pause");
    return 0;
}