#include <iostream>
using namespace std;

#define MAXIMO 100
#define CANTIDAD_DE_VOTOS 3
#define CANTIDAD_DE_TEMAS 30

struct votoPersona {
        char sexo;
        short edad;
        short temasPreferidos[CANTIDAD_DE_VOTOS];
};

bool validarSexo(votoPersona persona){
    return (persona.sexo == 'M' || persona.sexo == 'F');
}

bool validarEdad(votoPersona persona){
    return (persona.edad >= 15) && (persona.edad<=50);
}

bool validarDiscos (votoPersona persona){
    bool esValido = true;
     
    for (int i=1; i<=CANTIDAD_DE_VOTOS; i++)
        esValido = esValido && (persona.temasPreferidos[i-1] >= 1) && (persona.temasPreferidos[i-1] < CANTIDAD_DE_TEMAS);
    return esValido;
}

bool personaValida (votoPersona persona){
    return validarSexo(persona)  && validarEdad(persona) && validarDiscos(persona);
}

void ingresarPersona(votoPersona &persona){
    cout << "Sexo: ";
    cin >> persona.sexo;
    cout << "edad: ";
    cin >> persona.edad;
    cout << "3 discos favoritos (1..30): " << endl;
    cin >> persona.temasPreferidos[0] >> persona.temasPreferidos[1] >> persona.temasPreferidos[2]; 
}

void ingresarVotos(votoPersona votos[],int &cantidadIngresados){
    votoPersona persona;
    ingresarPersona (persona);
    while (personaValida(persona) && cantidadIngresados<MAXIMO){
        votos[cantidadIngresados] = persona;
        cantidadIngresados++;
        ingresarPersona (persona);
    }
}

void mostrarVotos(votoPersona votos[],int cantidadIngresados){
    system("cls");
    for (int i=0; i<cantidadIngresados; i++){
        cout << "Sexo: " << votos[i].sexo << endl;
        cout << "Edad: " << votos[i].edad << endl;
        cout << "Votos: " << votos[i].temasPreferidos[0] << " " << votos[i].temasPreferidos[1] << " " << votos[i].temasPreferidos[2] << endl << endl;
    }
}

void intercambiar(int v[][2], int i, int j){
    int aux;
    aux = v[j][0];
    v[j][0] = v[i][0];
    v[i][0] = aux;

    aux = v[j][1];
    v[j][1] = v[i][1];
    v[i][1] = aux;
}

void ordenBurbuja(int v[][2], int n){
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
            if(v[j+1][1]>v[j][1])
                intercambiar(v,j,j+1);
}

void inicializarTabla (int temas[][2]){
     for(int i=0; i<CANTIDAD_DE_TEMAS; i++){
        temas[i][0] = i+1;
        temas[i][1] = 0;
    }
}

void mostrarTabla(int temas[][2]){
    int i = 0;
    while (i<CANTIDAD_DE_TEMAS && temas[i][1]!=0 ){
        cout << "Tema N: " << temas[i][0] << " Votos: " << temas[i][1] << endl; 
        i++;
    }
}

bool hombresMasDe30(votoPersona persona){
    return (persona.edad > 30 && persona.sexo == 'M');
}
bool todos (votoPersona persona){
    return true;
}
bool hombres(votoPersona persona){
    return persona.sexo=='M';
}

filtramosConFuncion(votoPersona votos[], int temas[][2], int cantidadIngresados, bool (*funcion)(votoPersona)){
        for(int i=0; i<cantidadIngresados; i++)
            for (int j=0; j<CANTIDAD_DE_VOTOS; j++)
                if(funcion(votos[i]))
                    temas[ (votos[i].temasPreferidos[j])-1][1]++;
}

void generarTabla(votoPersona votos[], int temas[][2],int cantidadIngresados,bool (*funcion)(votoPersona)){
    inicializarTabla(temas);
    filtramosConFuncion(votos,temas,cantidadIngresados,funcion);
    ordenBurbuja(temas,CANTIDAD_DE_TEMAS);
    mostrarTabla(temas);
}

void tablaPosiciones(votoPersona votos[], int temas[][2], int cantidadIngresados){
    generarTabla(votos,temas,cantidadIngresados,todos);
}

void tablaPosicionesHombresMasDe30(votoPersona votos[], int temas[][2], int cantidadIngresados){
    generarTabla(votos,temas,cantidadIngresados,hombresMasDe30);
}

tablaPosicionesElegidasPorHombres(votoPersona votos[], int temas[][2], int cantidadIngresados){
    generarTabla(votos,temas,cantidadIngresados,hombres);
}

int main(){
    int cantidadIngresados = 0;
    int temas[CANTIDAD_DE_TEMAS][2];
    int temasHombresMasDe30[CANTIDAD_DE_TEMAS][2];

    votoPersona votos[MAXIMO];

    ingresarVotos(votos,cantidadIngresados);
    //funcionan cualquiera de las siguientes pero no queria hacer un menu :O

    //tablaPosiciones(votos,temas,cantidadIngresados);
    tablaPosicionesHombresMasDe30(votos,temas,cantidadIngresados);
    //tablaPosicionesElegidasPorHombres(votos,temas,cantidadIngresados);


    //mostrarVotos(votos,cantidadIngresados);




    system ("pause");
    return 0;
}