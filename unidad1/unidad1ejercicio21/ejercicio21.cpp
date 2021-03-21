#include <iostream>
using namespace std;

int main(){
    
    int a,b;

    do{
        system("cls");
        cout << "Ingrese a: ";
        cin >> a;
        cout << "Ingrese b: ";
        cin >> b;
    }while(b==0);

    if ((a%b) == 0) 
        cout << a << " es divisible por " << b << endl;
    else 
        cout << a << " NO es divisible por " << b << endl;

    system("pause");
    return 0;
}