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

void comparar_angulos(int promedio[]){
    //Aqui el mae cuenta el número de unos y le dice que tal estuvo según la suma
    int contador =0;
    for(int l=0;l<10;l++){	
        contador+=promedio[l];
    }
    
    //cout<<"Contador es : "<<contador<<" \n";
    if (contador>=9){
        cout<<"El movimiento fue excelente"<<"\n";
        }
    else if(contador>=7){
        cout<<"El movimiento fue bueno pero podrias mejorar"<<"\n";
    }
    else if(contador>=5){
        cout<<"El movimiento fue regular"<<"\n";
    }
    else if(contador>=3){
        cout<<"El movimiento fue deficiente"<<"\n";
    }  
    else {
        cout<<"El movimiento fue muy deficiente"<<"\n";
    }
}
    
int comparar_velocidad(int lista_falsa[], int n, int lista_falsa1[], int k){
    //Este nada más dice que tal estuvo la velocidad
	float rizado;
    rizado = n*0.1;
    if (k<n-rizado){
		cout<<"Hiciste el movimiento demasiado rapido\n";
		return 1;
		}
	else if (k>n+rizado){
		cout<<"Hiciste el movimiento demasiado lento\n";
		return 1;
		}
    else {
		cout<<"Hiciste el movimiento a la velocidad adecuada, !Muy bien!\n";
		return 0;
		}
	
	}

int main(int argc, char** argv) {
    
    /* Vea aqui se supone que se recibe 2 arrays: el movimimiento perfecto(lista_falsa) y algún otro
     * vea que ya tenemos q tener la longitud del vector que son esos int(n,k,m,a), el suyo no lo recibo aqí xq hay 
     * que pegarlo aquí mismo, osea que aquí mismo se hace.. creo XD.. entoncs di suponiendo que ya tenemos
     * eso y que su parte funciona bien solo seria de pegar esta vara así como está, xq vea que ya hasta
     * lo tengo implementado en métodos, no hay mucho q hacer, lo q me preocupa es pegarlo a lo de David
     * xq ni idea cm hacerlo XD
     */
    
    int n,k,m,a;
    n=20;
    a=21;
    k=23;
    m=17;
    int * lista_falsa = new int[n];
    int * lista_falsa1 = new int[k];
    int * lista_falsa2 = new int[m];
    int * lista_falsa3 = new int[a];
    
    int promedio5[]={1,1,1,1,1,1,1,1,1,0};
    
    
    cout<<"El análisis del movimiento es: "<<"\n";
    comparar_angulos(promedio5);
    
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
    
    cout<<"El análisis de velocidad es: \n";
    comparar_velocidad(lista_falsa, n, lista_falsa1, k);
    //comparar_velocidad(lista_falsa, n, lista_falsa1, k);/

    
    
    return 0;
}
