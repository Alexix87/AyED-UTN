#include <iostream>
using namespace std;

int sg(int x){
    if (x == 0) return 0;
    if (x<0) return -1;
    else return 1;

}

int main(){

    int x;

    cout << "Ingrese x: ";
    cin >> x;

    cout << "el signo de x es: " << sg(x) << endl;
    system("pause");


    return 0;
}