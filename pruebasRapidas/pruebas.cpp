#include <iostream>
#include <limits.h>
using namespace std;

int main(int argc, char const *argv[]){
    short soloShort;
    unsigned short unsignedShort;
    
    int soloInt;
    unsigned int unsignedInt;

    long soloLong;
    unsigned long unsignedLong;

    float real_float;
    double real_double;
    long double real_longDouble;

    bool falso = false;
    bool verdadero = true;

    char caracter = 'A';

    char cadena[10];
    char *pCadena = "hola que tal";

    const int valorConst = 5;

    cout << "TIPOS DE DATOS, TAMANIOS, LIMITES \n";
    cout << "---------------------------------------------------\n";
    
    cout << "Solo Short: " << sizeof(soloShort) << " bytes | el minimo es: " << SHRT_MIN << " y el maximo: " << SHRT_MAX << "\n";
    cout << "Unsigned Short: " << sizeof(unsignedShort) << " bytes | el minimo es: " << 0 << " y el maximo: " << USHRT_MAX << "\n";
    cout << "---------------------------------------------------\n";

    cout << "Solo int: " << sizeof(soloInt) << " bytes | el minimo es: " << INT_MIN << " y el maximo: " << INT_MAX << "\n";
    cout << "Unsigned int: " << sizeof(unsignedInt) << " bytes | el minimo es: " << 0 << " y el maximo: " << UINT_MAX << "\n";
    cout << "---------------------------------------------------\n";
   
    cout << "Solo long: " << sizeof(soloLong) << " bytes | el minimo es: " << LONG_MIN << " y el maximo: " << LONG_MAX << "\n";
    cout << "Unsigned long: " << sizeof(unsignedLong) << " bytes | el minimo es: " << 0 << " y el maximo: " << ULONG_MAX << "\n";

    cout << "---------------------------------------------------\n";

    cout << "real float: " << sizeof(real_float) << "\n";
    cout << "real double: " << sizeof(real_double) << "\n";
    cout << "real long double: " << sizeof(real_longDouble) << " *en las clases dijeron que es 10 :O \n";

    cout << "---------------------------------------------------\n";
    
    cout << "bool verdadero ocupa: " << sizeof(verdadero) << " y tiene valor: " << verdadero << "\n";
    cout << "bool falso ocupa: " << sizeof(falso) << " y tiene valor: " << falso << "\n";

    cout << "---------------------------------------------------\n";

    cout << "char: " << sizeof(caracter) << " byte | el caracter es: " << caracter << "\n";
    cout << "el caracter minimo es: " << CHAR_MIN << " y el maximo: " << CHAR_MAX << "\n";
    cout << "si hago caracter = caracter + 2, el caracter ahora es:  " << static_cast<char>(caracter+2)<< "\n";
    
    cout << "---------------------------------------------------\n";
    
    cout << "Las cadenas las puedo declarar de forma estatica o dinamica \n";
    cout << "De forma estatica char cadena[10] mide: " << sizeof(cadena) << " y continene: " << cadena << "\n";
    cout << "De forma dinamica char cadena* mide: " << sizeof(pCadena) << " y continene: " << pCadena << "\n";
    
    cout << "---------------------------------------------------\n";
    
    cout << "valor constante: " << valorConst << "\n";
    //valorConst = 20; Las constantes solo se usan en modo lectura, no pueden ser modificados!

    cout << "---------------------------------------------------\n";


    return 0;
}
