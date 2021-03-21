#include <iostream>
using namespace std;

int funcion(bool unBool, int a, int b){
    return unBool ? a : b;
}

int main(){

    int a,b,opcion;
    bool unBool;

    cout << "ingresar a: ";
    cin >> a;
    cout << "ingresar b: ";
    cin >> b;

    do{
        system("cls");
        cout << "opcion booleana: " << endl;
        cout << "1-----Verdadero" << endl;
        cout << "2-----Falso" << endl;
        cout << "opcion: ";
        cin >> opcion;
    }while (opcion != 1 && opcion !=2);

    if (opcion == 1)
        unBool= true;
    else
        unBool = false;

    system("cls");
    cout  << "El valor es: " << funcion(unBool,a,b) << endl;
    system("pause");




}