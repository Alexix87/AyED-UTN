#include <iostream>
using namespace std;

/*
Quince tiradores participan en un campeonato de tiro al blanco, efectuando cada uno de
ellos tres disparos. Como datos se ingresan 15 registros desordenados, cada uno de los
cuales contiene : Número del tirador (1..15), y tres puntajes (real 0..10)
correspondientes a los tres disparon realizados.
La suma de los 3 puntajes es el puntaje total del respectivo tirador. Se pide, emitir la
clasificación del campeonato ordenada por puntaje total y de la siguiente manera :
Posic. Tirador Puntaje
1 99 99.99
2 99 99.99
*/

void cargarPuntajes(int mPuntajes[15][4],const int CANT_TIRADORES, const int CANT_TIROS){
    for (int i=0; i<CANT_TIRADORES; i++){
        cout << "Tirador N° " << i+1 << "\n";
        mPuntajes[i][0] = i+1;
        for (int j=0; j<CANT_TIROS; j++){
            cout << "Tiro " << j+1 << ": ";
            cin >> mPuntajes[i][j+1];
        }
    }
}

int sumarPuntajeDeParticipante(int mPuntajes[15][4], int participante, int CANT_TIROS){
    int sumatoria = 0; 
    for (int i=1; i<=CANT_TIROS; i++){
        sumatoria += mPuntajes[participante][i];
    }
    return sumatoria;
}

void mostrarTablaPosiciones(int mPuntajes[15][4],int CANT_TIRADORES, int CANT_TIROS){
    cout << "Posicion";
    cout.width(10);
    cout << "Tirador";
    cout.width(10);
    cout << "Puntaje" << endl;
    
    for(int i=0; i<CANT_TIRADORES; i++){
        cout << i+1; 
        cout.width(10);
        cout << mPuntajes[i][0];
        cout.width(10);
        cout << sumarPuntajeDeParticipante(mPuntajes,i,CANT_TIROS) << endl;
    }
    cout << endl;

    system("pause");
}

void intercambiar (int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenarTablaPosiciones (int mPuntajes[15][4],int CANT_TIRADORES, int CANT_TIROS){
    for(int i=0; i<CANT_TIRADORES-1; i++)
        for(int j=0; j<CANT_TIRADORES-1-i; j++)
            if ( sumarPuntajeDeParticipante(mPuntajes,j,CANT_TIROS) < sumarPuntajeDeParticipante(mPuntajes,j+1,CANT_TIROS)){
                for(int k=0; k<CANT_TIROS+1;k++){
                    intercambiar(mPuntajes[j][k],mPuntajes[j+1][k]);
                }
            }
}

int main(){
    const int CANT_TIRADORES = 15;
    const int CANT_TIROS = 3;
    int mPuntajes[CANT_TIRADORES][CANT_TIROS+1];

    cargarPuntajes (mPuntajes,CANT_TIRADORES,CANT_TIROS);
    ordenarTablaPosiciones(mPuntajes,CANT_TIRADORES,CANT_TIROS);
    mostrarTablaPosiciones(mPuntajes,CANT_TIRADORES,CANT_TIROS);

    return 0;
}