/* 
 * File:   compara.cpp
 * Author: davidpb
 * 
 * Created on June 2, 2014, 12:04 AM
 */

#include "compara.hh"

compara::compara() {
    conversion persona1("jointp1", "jointp2");
    conversion persona2("joint1", "joint2");
    this->_ArregloMov1 = persona1.getArregloAngulos();
    this->_ArregloMov2 = persona2.getArregloAngulos();
    double * arregloP1 = sacapromedios(_ArregloMov1);
    double * arregloP2 = sacapromedios(_ArregloMov2);
    _ArregloComparativo = arreglo_promedio(arregloP1, arregloP2);
    comparar_angulos(_ArregloComparativo);
    comparar_velocidad(persona1._TamanoMov1, persona2._TamanoMov2); //
}

compara::compara(const compara& orig) {
}

compara::~compara() {
}

double * compara::sacapromedios(double* arreglo) {
    double * arreglo_prom = new double [10]; //revisar
    for (int k = 0; k < 10; k++) {
        int sumatoria = 0;
        for (int i = int(k * 10 * 0.1); i < int(10 * 0.1 * (1 + k)); i++) { //cambiar 10 por n
            sumatoria = sumatoria + arreglo[i];
        }
        arreglo_prom[k] = double(sumatoria) / double(int(10 * 0.1)); // cambiar 10 por n
    }
    return arreglo_prom;
}

int * compara::arreglo_promedio(double *arreglo_prom1, double *arreglo_prom2) {
    int * selecciona = new int [10]; //revisar
    for (int i = 0; i < 10; i++) {
        if (arreglo_prom1[i] > arreglo_prom2[i] + 5.0) {
            selecciona[i] = 0;
        } else if (arreglo_prom1[i] < arreglo_prom2[i] - 5.0) {
            selecciona[i] = 0;
        } else {
            selecciona[i] = 1;
        }
    }
    for (int j = 0; j < 10; j++) {
    }
    return selecciona;
}

int * compara::getArregloComparativo() {
    return _ArregloComparativo;
}

void compara::comparar_angulos(int* promedio) {
    int contador = 0;
    for (int l = 0; l < 10; l++) {
        contador += promedio[l];
    }
    if (contador >= 9) {
        cout << "Movimiento muy bueno" << "\n";
    } else if (contador >= 7) {
        cout << "Movimiento bueno" << "\n";
    } else if (contador >= 5) {
        cout << "Movimiento regular" << "\n";
    } else if (contador >= 3) {
        cout << "Movimiento deficiente" << "\n";
    } else {
        cout << "Movimiento muy deficiente" << "\n";
    }
}

void compara::comparar_velocidad(int pSizeMov1, int pSizeMov2) {
    float rizado;
    rizado = pSizeMov1 * 0.1;
    if (pSizeMov2 < pSizeMov1 - rizado) {
        cout << "Movimiento demasiado rapido\n";
    } else if (pSizeMov2 > pSizeMov1 + rizado) {
        cout << "Movimiento demasiado lento\n";
    } else {
        cout << "Movimiento de velocidad aceptable\n";
    }
}

