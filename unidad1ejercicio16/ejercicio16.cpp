#include <iostream>
using namespace std;

int main(){
    bool a = true;
    bool b = true;

    while (a){
        cout << a << "  " << b << "  " << a << endl;
        
        if (!b)
            a = !a;
        else 
            b = !b;
    }

    system("pause");
    return 0;
}