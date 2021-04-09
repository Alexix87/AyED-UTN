#include <iostream>
#include <time.h>
using namespace std;

void generarVector(int vector[], const int MAX){
    srand(time(NULL));
    for (int i = 0; i< MAX; i++)
        vector[i] = rand() % 100 + 1;
}

void mostrarVector(int vector[],const int MAX){
    for (int i = 0; i< MAX; i++)
        cout << vector[i] << "\t";
    cout << "\n";

}

int sumatoria(int vector[], const int MAX){
    int sum = 0;
    for (int i = 0; i< MAX; i++)
        sum += vector[i];
    return sum;
}

void mostrarPromedio(int vector[],const int MAX){
    system("cls");
    mostrarVector(vector,MAX);
    cout << "El promedio es: " << sumatoria(vector,MAX)/MAX << endl;
    system("pause");
}

void mostrarSumatoria(int vector[], const int MAX){
    system("cls");
    mostrarVector(vector,MAX);
    cout << "La sumatoria es: " << sumatoria(vector,MAX) << endl;
    system("pause");
}

void maximo(int vector[], const int MAX){
    int max = 0; 
    for (int i =0; i<MAX; i++)
        if (max<vector[i]) 
            max =vector[i];
    system("cls");
    mostrarVector(vector,MAX);
    cout << "El maximo es: " << max << endl;
    system("pause");
}

void minimo(int vector[], const int MAX){
    int min = 101;
    for (int i =0; i<MAX; i++)
        if (min>vector[i]) 
            min =vector[i];
    system("cls");
    mostrarVector(vector,MAX);
    cout << "El minimo es: " << min << endl;
    system("pause");
}

void mostrarMenu(){
    system ("cls");
    cout << "1)\tPromedio" << endl;
    cout << "2)\tMaximo" << endl;
    cout << "3)\tMinimo" << endl;
    cout << "4)\tSumatoria" << endl;
    cout << "5)\tSalir" << endl;
}

void menu(int vector[], const int MAX){
    int opcion;
    do{
        do {
            mostrarMenu();
            cout << "Opcion: ";
            cin>> opcion;
        }while (opcion<0 || opcion>5);

        switch(opcion){
            case 1: mostrarPromedio(vector,MAX);
                break;
            case 2: maximo(vector,MAX);
                break;
            case 3: minimo(vector,MAX);
                break;
            case 4: mostrarSumatoria(vector,MAX);
                break;
        }
    }while(opcion != 5);
}

int main(){
    const int MAX=15;
    int vector[MAX];
    generarVector(vector,MAX);
    menu(vector,MAX);
    return 0;
}