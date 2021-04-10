#include <iostream>
#include <time.h>
using namespace std;

bool valorPresente(int v[],int cant,int clave){
    bool encontrado = false;
    int i = 0;

    while (i<cant && !encontrado){
        if (v[i] == clave)
            encontrado = true;
        i++;
    }
    return encontrado;
}

void generarVector(int v[],int cant, int max){
    int nuevoValor;

    v[0] = rand() % max + 1;
    for (int i=1;i<cant;i++){
        do{
            nuevoValor = rand() % max + 1;
        }while(valorPresente(v,i,nuevoValor));
        v[i] = nuevoValor;
    }
}

void ordenarVectorBurbuja(int v[],int cant){
    int aux;
    for (int i = 0; i < cant-1; i++)
        for(int j = 0; j< cant-1-i; j++)
            if (v[j+1]<v[j]){
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
}

void mostrarVector(int v[],int cant){
    for (int i= 0; i< cant; i++)   
        cout << v[i] << "\t";
    cout << "\n"; 
}

void limpiarVector(int v[],int &cant, int max){
    for (int i= 0; i<max; i++)
        v[i] = 0;
    cant = 0;
}

void unionDe(int p[], int q[], int r[], int cantP, int cantQ, int &cantR,int max){
    limpiarVector(r,cantR,max);
    for (int i=0; i<cantP; i++)
        r[i] = p[i];
    cantR = cantP;

    for (int j=0; j<cantQ; j++)
        if (!valorPresente(r,cantP,q[j])){
            r[cantR] = q[j];
            cantR++;
        }
}

void interseccionDe(int p[], int q[], int r[], int cantP, int cantQ, int &cantR, int max){
    limpiarVector(r,cantR,max);
    cantR = 0;
    for (int i=0; i<cantP; i++){
        if (valorPresente(q,cantQ,p[i])){
            r[cantR] = p[i];
            cantR++;
        }
    }
}

void diferenciaDe(int p[], int q[], int r[], int cantP, int cantQ, int &cantR, int max){
    limpiarVector(r,cantR,max);
    cantR = 0;
    for (int i=0; i<cantP; i++){
        if(!valorPresente(q,cantQ,p[i])){
            r[cantR] = p[i];
            cantR++;
        }
    }
}

void diferenciaGeometricaDe(int p[], int q[], int r[], int cantP, int cantQ, int &cantR, int max){
    limpiarVector(r,cantR,max);
    cantR = 0;
    for (int i=0; i<cantP; i++){
        if(!valorPresente(q,cantQ,p[i])){
            r[cantR] = p[i];
            cantR++;
        }
    }
    for (int j=0; j<cantQ; j++){
        if(!valorPresente(p,cantP,q[j])){
            r[cantR] = q[j];
            cantR++;
        }
    }



}
int main(){
    int opcion;
    const int MAX = 90;
    int p[MAX], q[MAX], r[MAX];
    int cantElementosDeP,cantElementosDeQ,cantElementosDeR;

    cout << "Ingrese cantidad de elementos de vector P: ";
    cin >> cantElementosDeP;
    cout << "Ingrese cantidad de elementos de vector Q: ";
    cin >> cantElementosDeQ;

    srand(time(NULL));
    generarVector(p,cantElementosDeP,MAX);
    generarVector(q,cantElementosDeQ,MAX);
    ordenarVectorBurbuja(p,cantElementosDeP);
    ordenarVectorBurbuja(q,cantElementosDeQ);

    do{
        system("cls");
        cout << "1) Union de p y q \n";
        cout << "2) Interseccion de p y q \n";
        cout << "3) Diferencia entre p y q \n";
        cout << "4) Diferencia geometrica entre p y q \n";
        cout << "5) Salir \n";
        cin >> opcion;

        switch(opcion){
            case 1:
                unionDe(p,q,r,cantElementosDeP,cantElementosDeQ,cantElementosDeR,MAX);
                break;
            case 2: 
                interseccionDe(p,q,r,cantElementosDeP,cantElementosDeQ,cantElementosDeR,MAX);
                break;
            case 3:
                diferenciaDe(p,q,r,cantElementosDeP,cantElementosDeQ,cantElementosDeR,MAX);
                break;
            case 4: 
                diferenciaGeometricaDe(p,q,r,cantElementosDeP,cantElementosDeQ,cantElementosDeR,MAX);
                break;
            default: 
                break;
        };
        if (opcion!=5){
            ordenarVectorBurbuja(r,cantElementosDeR);
            cout << "Vector P: \n";
            mostrarVector(p,cantElementosDeP);
            cout << "Vector Q: \n";
            mostrarVector(q,cantElementosDeQ);
            cout << "Vector R: \n";
            mostrarVector(r,cantElementosDeR);
            system("pause");
        }
    }while (opcion!=5);
    return 0;
}