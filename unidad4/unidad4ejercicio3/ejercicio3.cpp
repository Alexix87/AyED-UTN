#include <iostream>
#include <time.h>
using namespace std;

void ordenBurbuja(int v[], int cant){
    int aux;
    for (int i = 0; i<cant-1; i++)
        for (int j= 0; j<cant-1-i; j++)
            if (v[j+1]<v[j]){
                aux = v[j+1];
                v[j+1]= v[j];
                v[j]=aux;
            }
}

bool esValido(int vector[], int indice, int valor){
    bool valido = false;
    bool encontrado = false;
    int i = 0;
    if (indice == 0) return true;
    while (i<indice && !encontrado){
        if(vector[i]==valor)
            encontrado = true;
        i ++;
    }
    if (encontrado) return false;
    else return true;
}

/*
Generar un vector con N elementos en forma al azar sin repetir en el intervalo de 1 a 90.
Caso 1: simulando sacar una bolilla cantarla y meterla en la misma bolsa.
*/
void caso1(int vGenerado[], int limiteGenerado){
    int valorNuevo;
    bool valido;
    
    srand(time(NULL));
    for(int i=0; i<limiteGenerado; i++){
        do{
            valorNuevo = rand() % 90 + 1;
            valido = esValido(vGenerado, i, valorNuevo);
            if (valido)
                vGenerado[i] = valorNuevo;
        }while(!valido);
    } 
}


void mostrarVector(int vector[], int indiceMax){
    cout << "\nEl vector es: \n";
    for(int i=0; i<indiceMax; i++)
        cout << vector[i] << "\t";
    cout << "\n";
}
void cortar(int vector[],int indice, int indiceMaximo){
    int i;
    for(i=indice;i<indiceMaximo;i++){
        vector[i] = vector[i+1];
    }
    vector[indiceMaximo-1] = -1;
}
void cortarValorDeIndiceAlVector(int indiceACortar,int vectorValores[],int indiceAPegar,int vectorGenerado[],int &indiceAux,int indiceMaximo){
    indiceAux--;
    vectorGenerado[indiceAPegar] = vectorValores[indiceACortar];
    cortar(vectorValores,indiceACortar,indiceMaximo);
}
/*
Generar un vector con N elementos en forma al azar sin repetir en el intervalo de 1 a 90.
Caso 2: simulando sacar una bolilla cantarla y apartarla.
*/
void caso2(int vectorGenerado[],int limiteMaxDeGenerado){
    const int limiteMaximoDeCantidadValores = 90;
    int indiceAux = limiteMaximoDeCantidadValores;
    int vectorValores[limiteMaximoDeCantidadValores];
    int indiceNuevo;
    for (int i = 0; i<limiteMaximoDeCantidadValores; i++)
        vectorValores[i] = i+1;
    

    srand(time(NULL));
    for(int i=0; i<limiteMaxDeGenerado; i++){
        do{
        indiceNuevo = rand() % 90;
        }while(indiceNuevo>indiceAux);

        cortarValorDeIndiceAlVector(indiceNuevo,vectorValores,i,vectorGenerado,indiceAux,limiteMaximoDeCantidadValores);
    }
    mostrarVector(vectorValores,limiteMaximoDeCantidadValores);
    cout << "\n\n\n";
}

int main(){
    int caso = 2;
    const int limiteMaxDeGenerado =10 ;
    int vectorGenerado[limiteMaxDeGenerado];

    switch(caso){
        case 1: 
            caso1(vectorGenerado,limiteMaxDeGenerado);
            break;
        case 2:
            caso2(vectorGenerado,limiteMaxDeGenerado);
            break;
    }
    
    ordenBurbuja(vectorGenerado,limiteMaxDeGenerado);
    mostrarVector(vectorGenerado,limiteMaxDeGenerado);
    system("pause");
    
    return 0;
}