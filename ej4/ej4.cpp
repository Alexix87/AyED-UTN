#include <iostream> 
#include <time.h>

using namespace std;

void generarVector(int vector[],int max){
    srand(time(NULL));
    for (int i = 0; i<max; i++){
        vector[i]= rand()%100 +1;
    }
}

void mostrarVector(int vector[],int max){
    cout << "El vector es: " << endl;
    for (int i = 0; i<max; i++){
        cout << vector[i] << "\t";
    }
    cout << "\n";
}

void ordenarBurbuja(int vector[], int max){
    int aux;
    for (int i = 0; i<max-1; i++)
        for(int j= 0; j<max-1-i; j++)
            if(vector[j+1]<vector[j]){
                aux = vector[j+1];
                vector[j+1]=vector[j];
                vector[j]= aux;
            }
}

void pedirValor(int &clave){
    cout << "valor a buscar: ";
    cin >> clave;
}

int busquedaBinaria(int vector[],int clave, int inferior, int superior){
    int medio;
    if (inferior > superior) return -1;
    medio = (superior + inferior) / 2;
    if (clave == vector[medio]) return medio;
    else
        if(clave>vector[medio]) return busquedaBinaria(vector,clave,medio+1,superior);
        else return busquedaBinaria(vector,clave,inferior,medio-1);
}

void mostrarResultado(int posicion){
    if (posicion == -1)
        cout << "el valor no esta en el vector";
    else
        cout << "el valor se en cuentra en la posicion: " << posicion;
}

int main(){
    const int max = 15;
    int vector[max];
    int clave;
    int posicion;
    generarVector (vector,max);
    mostrarVector(vector,max);
    ordenarBurbuja(vector,max);
    mostrarVector(vector,max);
    pedirValor(clave);
    posicion = busquedaBinaria(vector,clave,0,max-1);
    mostrarResultado(posicion);
    
    cout << "\n";
    system("pause");
    return 0;
}