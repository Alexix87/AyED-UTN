#include <iostream> 
#include <string.h>
using namespace std;
int main(){
    char cadena[100];

    strcpy(cadena, "Hola ");
    strcat(cadena, "mundo! ");
    strcat(cadena, ":) ");
    cout << cadena << endl;
    system("pause");


    return 0;
}