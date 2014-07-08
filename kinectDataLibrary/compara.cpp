/* 
 * File:   compara.cpp
 * Author: davidpb
 * 
 * Created on June 2, 2014, 12:04 AM
 */

#include "compara.hh"

/**
  @brief Método constructor de la clase compara, y que lleva el hilo principal del programa.
  @param Método sin parámetros.
  @returns Método sin retorno.
 */
compara::compara() {
    conversion persona1("panza", "cuello", "muneca", "hombro");
    conversion persona2("panza1", "cuello1", "muneca1", "hombro1");
    this->_ArregloMov1 = persona1.getArregloAngulos();
    for (int i = 0; i < 10; i++) {
        cout << _ArregloMov1[i] << endl;
    }
    this->_ArregloMov2 = persona2.getArregloAngulos();
    cout << "hola" << endl;
    for (int i = 0; i < 16; i++) {
        cout << _ArregloMov2[i] << endl;
    }
    this->_CantDatos1 = persona1._TamanoMov1;
    this->_CantDatos2 = persona2._TamanoMov1;
    double * arregloP1 = sacapromedios(_ArregloMov1, _CantDatos1);
    double * arregloP2 = sacapromedios(_ArregloMov2, _CantDatos2);
    _ArregloComparativo = arreglo_promedio(arregloP1, arregloP2);
    comparar_angulos(_ArregloComparativo);
    comparar_velocidad(persona1._TamanoMov1, persona2._TamanoMov2); //
}

compara::compara(const compara& orig) {
}

compara::~compara() {
}

/**
  @brief Método sacapromedios transformar cada 10% de ángulos en una sóla  información. Se forma
 * un bloque cada 10% y va depender de la cantidad de datos analizados. 
  @param double * arreglo - Recibe el arreglo de los ángulos. int pDato - Cantidad de datos del movimiento. 
  @returns double * - Arreglo con cada uno de los bloques de la información.
 */
double * compara::sacapromedios(double* arreglo, int pDato) {
    double * arreglo_prom = new double [10]; //revisar
    for (int k = 0; k < 10; k++) {
        int sumatoria = 0;
        for (int i = int(k * pDato * 0.1); i < int(pDato * 0.1 * (1 + k)); i++) { //cambiar 10 por n
            sumatoria = sumatoria + arreglo[i];
        }
        arreglo_prom[k] = double(sumatoria) / double(int(pDato * 0.1)); // cambiar 10 por n
    }
    return arreglo_prom;
}

/**
  @brief Método que compara los datos de los dos movimientos, y retorna un arreglo de 1 y 0;
 * 1 para una parte del movimiento que fue bien realizada y 0 para una parte que no fue bien realizada.
  @param  2 double * arreglo_prom - Los dos arreglo_prom de los movimientos.
  @returns int* - Arreglo de 1 y 0 que representan la calidad del movimiento.
 */
int * compara::arreglo_promedio(double *arreglo_prom1, double *arreglo_prom2) {
    int * selecciona = new int [10];
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

/**
  @brief Método que retorna el _ArregloComparativo de los movimientos..
  @param  Método sin parámetros.
  @returns int* - Arreglo de 1 y 0.
 */
int * compara::getArregloComparativo() {
    return _ArregloComparativo;
}

/**
  @brief Método que analiza el arreglo de 1 y 0. Nos dice la calidad del movimientos dependiendo de la cantidad
 * de unos que va a obtener el arreglo comparativo.
  @param  int* promedio - Arreglo con los ángulos promedio.
  @returns Método sin retorno.
 */
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

/**
  @brief Método que compara la cantidad de datos del movimiento 1 con los del moviento 2.
  @param  2 int pSizeMov - Tamaño del arreglo de cada uno de los movimientos. 
  @returns Método sin retorno.
 */
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

