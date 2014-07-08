/* 
 * File:   main.cpp
 * Author: davidpb
 *
 * Created on June 19, 2014, 3:00 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(void) {
    const int n = 2;
    const int m = 3;
    cout<<"Probando el constructor y get():"<<endl;
    C_matriz A(n,m);
    A.desplegar_matriz(n,m,A);
    cout<<"Probando set():"<<endl;
    A.llenar_matriz(n,m,A);
    cout<<"Probando el constructor con parametros predeterminados:"<<endl;
    C_matriz B;
    A.desplegar_matriz(1,1,B);
    cout<<"Probando el constructor de copia:"<<endl;
    C_matriz C(A);
    A.desplegar_matriz(n,m,C);
    return 0;
}

