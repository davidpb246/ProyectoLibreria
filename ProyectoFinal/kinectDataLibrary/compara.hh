/* 
 * File:   compara.hh
 * Author: davidpb
 *
 * Created on June 2, 2014, 12:04 AM
 */

#include <string>
#include <iostream>
#include "conversion.hh"

#ifndef COMPARA_HH
#define	COMPARA_HH

class compara {
public:
    compara();
    compara(const compara& orig);
    virtual ~compara();
    double * sacapromedios(double * arreglo);
    int * arreglo_promedio(double *arreglo_prom1, double *arreglo_prom2);
    int * getArregloComparativo();
    void comparar_angulos(int * promedio);
    void comparar_velocidad(int pSizeMov1, int pSizeMov2);
private:
     double * _ArregloMov1;
     double  * _ArregloMov2;
     int * _ArregloComparativo;
    

};

#endif	/* COMPARA_HH */

