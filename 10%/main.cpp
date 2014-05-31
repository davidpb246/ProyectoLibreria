/* 
 * File:   main.cpp
 * Author: andres
 *
 * Created on May 27, 2014, 1:47 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

void printArray(int lista_falsa[], int n){
    for (int b = 0; b < n; b++) {
    	cout << lista_falsa[b] << ' ';
    }
    cout << endl;}
    
int comparar_velocidad(int lista_falsa[], int n, int lista_falsa1[], int k){
	float rizado;
    rizado = n*0.1;
    if (k<n-rizado){
		//cout<<"Hiciste el movimiento demasiado rapido, intentalo de nuevo\n";
		return 1;
		}
	else if (k>n+rizado){
		//cout<<"Hiciste el movimiento demasiado lento, intentalo de nuevo\n";
		return 1;
		}
    else {
		//cout<<"Hiciste el movimiento a la velocidad adecuada, !Muy bien!\n";
		return 0;
		}
	
	}

int main(int argc, char** argv) {

    int n,k,m,a;
    n=20;
    a=21;
    k=23;
    m=17;
    int * lista_falsa = new int[n];
    int * lista_falsa1 = new int[k];
    int * lista_falsa2 = new int[m];
    int * lista_falsa3 = new int[a];
    
    for(int i=0;i<20;i++){
		int dat=i;
        lista_falsa[i]=dat;
    }
  
    for(int x=0;x<23;x++){
        lista_falsa1[x]=x;
    }
    
    for(int p=0;p<17;p++){
        lista_falsa2[p]=p;
    }
    
    printArray(lista_falsa, n);
    printArray(lista_falsa1, k);
    printArray(lista_falsa2, m);
    
    cout<<"El analisis de velocidad es: "<< comparar_velocidad(lista_falsa, n, lista_falsa1, k)<<"\n";
    //comparar_velocidad(lista_falsa, n, lista_falsa1, k);//lento
    cout<<"El analisis de velocidad es: "<< comparar_velocidad(lista_falsa, n, lista_falsa2, m)<<"\n";
    //comparar_velocidad(lista_falsa, n, lista_falsa2, m);//rapido
    cout<<"El analisis de velocidad es: "<<comparar_velocidad(lista_falsa, n, lista_falsa3, a)<<"\n";
    //comparar_velocidad(lista_falsa, n, lista_falsa3, a);//perfecto
    
    return 0;
}
