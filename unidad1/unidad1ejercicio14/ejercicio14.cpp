#include <iostream>
#include <string.h>
using namespace std;

void ingresar(int &dato, char* texto){
    cout << texto;
    cin >> dato;
    cout << endl;
}

void ingresarT(char dato[],char* texto){
    cout << texto;
    cin >> dato;
    cout << endl;
}

bool esValido(int n){
    return (n==0 || n==1 || n==2 || n==3 );
}

int main(){

    int codigo;
    char textoCodigo[] = "Codigo: ";
    char textoVehiculo[] = "Numero de vehiculo: ";
    char textoNombrePiloto[] = "Nombre del piloto: ";
    char textoNombreCopiloto[] = "Nombre del copiloto: ";
    char textoEscuderia[] = "Escuderia: ";
    char textoTiempo[] = "Tiempo de llegada en minutos: ";

    char auto_vehiculo[20],
        auto_nombrePiloto[20],
        auto_nombreCopiloto[20],
        auto_escuderia[20];
    int auto_tiempo = 0; 

    char camion_vehiculo[20],
        camion_nombrePiloto[20],
        camion_nombreCopiloto[20],
        camion_escuderia[20];
    int camion_tiempo = 0;
        
    char moto_vehiculo[20],
        moto_nombrePiloto[20],
        moto_nombreCopiloto[20],
        moto_escuderia[20];
    int moto_tiempo = 0;
    
    char aux_vehiculo[20],
        aux_nombrePiloto[20],
        aux_nombreCopiloto[20],
        aux_escuderia[20];
    int aux_tiempo = 0;

    do{
        do{
            ingresar(codigo, textoCodigo);
        } while(!esValido(codigo));
        
        if (codigo != 0){
            ingresarT(aux_vehiculo, textoVehiculo);
            ingresarT(aux_nombrePiloto, textoNombrePiloto);
            ingresarT(aux_nombreCopiloto, textoNombreCopiloto);
            ingresarT(aux_escuderia, textoEscuderia);
            ingresar(aux_tiempo, textoTiempo);

            switch(codigo){
                case 1: 
                    if (auto_tiempo >= aux_tiempo || auto_tiempo == 0){
                        strcpy(auto_vehiculo,aux_vehiculo);
                        strcpy(auto_nombrePiloto, aux_nombrePiloto);
                        strcpy(auto_nombreCopiloto, aux_nombreCopiloto);
                        strcpy(auto_escuderia, aux_escuderia);
                        auto_tiempo = aux_tiempo;
                    }
                    break;
                case 2: 
                    if (camion_tiempo >= aux_tiempo || camion_tiempo == 0){
                        strcpy(camion_vehiculo,aux_vehiculo);
                        strcpy(camion_nombrePiloto, aux_nombrePiloto);
                        strcpy(camion_nombreCopiloto, aux_nombreCopiloto);
                        strcpy(camion_escuderia, aux_escuderia);
                        camion_tiempo = aux_tiempo;
                    }
                    break;
                case 3: 
                    if (moto_tiempo >= aux_tiempo || moto_tiempo == 0){
                        strcpy(moto_vehiculo,aux_vehiculo);
                        strcpy(moto_nombrePiloto, aux_nombrePiloto);
                        strcpy(moto_nombreCopiloto, aux_nombreCopiloto);
                        strcpy(moto_escuderia, aux_escuderia);
                        moto_tiempo = aux_tiempo;
                    }
                    break;
            }
        }
        else{
            if (aux_tiempo == 0) cout << "No hay ingresos" << endl;
            else{
                cout << "Mejores tiempos: \n" << endl;
                
                if (auto_tiempo != 0){
                    cout << "Auto: " << endl;
                    cout << "NumVehiculo: " << auto_vehiculo << " nombrePiloto: " << auto_nombrePiloto << " nombeCopiloto: " << auto_nombreCopiloto << " escuderia: " << auto_escuderia << " tiempo: " << auto_tiempo << endl;
                }
                if(camion_tiempo != 0){
                    cout << "Camion: " << endl;
                    cout << "NumVehiculo: " << camion_vehiculo << " nombrePiloto: " << camion_nombrePiloto << " nombeCopiloto: " << camion_nombreCopiloto << " escuderia: " << camion_escuderia << " tiempo: " << camion_tiempo << endl;
                }
                if (moto_tiempo != 0){
                    cout << "Moto: " << endl;
                    cout << "NumVehiculo: " << moto_vehiculo << " nombrePiloto: " << moto_nombrePiloto << " nombeCopiloto: " << moto_nombreCopiloto << " escuderia: " << moto_escuderia << " tiempo: " << moto_tiempo << endl;
                }
            }
        }
    } while(codigo!=0);
    system("pause");
    return 0;
}