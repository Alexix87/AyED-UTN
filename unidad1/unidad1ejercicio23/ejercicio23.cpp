#include <iostream>
using namespace std;

void verificarMinimo(int unValor, int &minimo){
    if(unValor<minimo) minimo = unValor;
}
void verificarMaximo(int unValor, int &maximo){
    if(unValor>maximo) maximo = unValor;
}

void mostrar(int a, int b, int c){   
    cout << "Los numeros son: " << a;
    cout << "   " << b;
    cout << "   " << c << endl;
}
 
void mostrarOrdenadosDescendentes(int a, int b, int c){
    if (a>b)
        if (a>c) 
            if (b>c)
                mostrar(a,b,c);
            else 
                mostrar(a,c,b);
        else 
            mostrar(c,a,b);
    else
        if(b>c)
            if(c>a)
                mostrar(b,c,a);
            else    
                mostrar(b,a,c);
        else
            mostrar(c,b,a);
}

int main(){

    int n,a,b,c,minimo,maximo;

    cout << "cantidad de ternas: ";
    cin >> n;
    minimo = 30000;
    maximo = 0;

    for(int i=1; i<=n; i++){
        cout << "ingresar 3 numeros: \n";
        cin >> a;
        cin >> b;
        cin >> c;

        mostrarOrdenadosDescendentes(a,b,c);
        verificarMinimo(a,minimo);
        verificarMaximo(a,maximo);
        verificarMinimo(b,minimo);
        verificarMaximo(b,maximo);
        verificarMinimo(c,minimo);
        verificarMaximo(c,maximo);
    }

    cout << "El maximo es: " << maximo << " y el minimo: " << minimo << endl;
    system("pause");

    return 0;
}