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

    return 0;
}
