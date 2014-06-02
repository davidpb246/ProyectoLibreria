/* 
 * File:   compara.cpp
 * Author: sama
 * 
 * Created on June 1, 2014, 8:52 PM
 */

#include "compara.h"

compara::compara() {
}

compara::compara(const compara& orig) {
}

compara::~compara() {
}

void compara::sacapromedios(){
    for(int k = 0; k<10; k++){
        int sumatoria = 0;
	for(int i = int(k*20*0.1); i < int(20*0.1*(1+k)); i++){
            sumatoria = sumatoria + arreglo[i];
        }
	cout << "sumatoria " << sumatoria << endl;
	arreglo_prom[k] = float(sumatoria)/float(int(20*0.1));
	cout << "Arreglo promedios " << arreglo_prom[k] << endl;
    }}

void compara::arreglo_prom(){
    for(int i = 0; i < 10; i++){
        if (arreglo_prom1[i] > arreglo_prom2[i] + 5.0){
            selecciona[i] = 0;
        }
        else if (arreglo_prom1[i] < arreglo_prom2[i] - 5.0){
            selecciona[i] = 0;
        }
    }
    for(int j=0; j<10; j++){
	cout << "la posicion " << j << " de selecciona tiene: " << selecciona[j] <<endl;
    }
}



