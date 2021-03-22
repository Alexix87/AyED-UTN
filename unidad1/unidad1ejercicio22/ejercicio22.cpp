#include <iostream>
#include <time.h>
using namespace std;

bool trianguloValido(int a, int b, int c){
    return ((a<b+c) && (b<a+c) && (c<a+b));
}

void generarTriangulo(int &a, int &b, int &c){
    /* initialize random seed: */
    srand (time(NULL));
    do{
        /* generate secret number between 1 and 10: */
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        c = rand() % 10 + 1;
    } while (!trianguloValido(a,b,c));
}

int calcularPerimetro(int a, int b, int c){
    return a+b+c;
}

int clasificar(int a, int b, int c){
    if (a==b && a==c) return 0;
    if ((a==b && a!=c) || (a==c) && (a!=b) || (b==c) && (b!=a)) return 1;
    return 2;
}

int main(){
    char nombre[10];
    int opcion, correctas,incorrectas,a,b,c,perimetro,rtaPerimetro,rtaTipo;
    enum tipoDeTriangulo{Equilatero,Isosceles,Escaleno};
    tipoDeTriangulo tipo;

    do{
        system("cls");
        cout << "Nombre: ";
        cin >> nombre;
        incorrectas = 0;
        correctas = 0;

        for(int i = 1; i<=10; i++){
            generarTriangulo(a,b,c);
            perimetro = calcularPerimetro(a,b,c);
            
            switch(clasificar(a,b,c)){
                case 0: tipo = Equilatero;
                    break;
                case 1: tipo = Isosceles;
                    break;
                case 2: tipo = Escaleno;
                    break;
            };

            cout << "\nEl triangulo tiene los siguientes lados: " << a << "   " << b << "   " << c << endl;
            cout << "Perimetro: ";
            cin >> rtaPerimetro;
            cout << "Tipo de triangulo (ingrese: 0-Equilatero 1-isosceles 2-escaleno): ";
            cin >> rtaTipo;

            if (perimetro == rtaPerimetro && tipo == rtaTipo){
                cout << "La respuesta es correcta!" << endl;
                correctas++;
            }else{
                cout << "La respuesta es incorrecta :(" << endl;
                incorrectas++;
            }
        }

        cout << nombre << " -> Correctas: " << correctas << " Incorrectas: " << incorrectas << endl;
        cout << "otro alumno? (1 = Si): ";
        cin >> opcion;
    }while (opcion == 1);

    return 0;
}