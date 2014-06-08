/* 
 * File:   conversion.hh
 * Author: davidpb
 *
 * Created on June 1, 2014, 7:42 PM
 */

#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <math.h>
#include <stdlib.h>     /* atof */
#include <string>
#include <iostream>
#include "archivos.hh"

#define PI (3.141592653589793)

using namespace std;
using namespace Eigen;

#ifndef CONVERSION_HH
#define	CONVERSION_HH

class conversion {
public:
    conversion(string  ptxt1, string ptxt2, string ptxt3, string ptxt4);
    conversion(const conversion& orig);
    virtual ~conversion();
    double convertir(string* pjoint1, string* pjoint2, string* pjoint3, string* pjoint4, int  n);
    string * split(string pDato);
    void llenarArregloAngulos();
    double * getArregloAngulos();
    int _TamanoMov1;
    int _TamanoMov2;
    int _TamanoMov3;
    int _TamanoMov4;
    
private:
    archivos _Joint1_Txt;
    archivos _Joint2_Txt;
    archivos _Joint3_Txt;
    archivos _Joint4_Txt;
    double  * _Arreglo_angulos;
    
};

#endif	/* CONVERSION_HH */

