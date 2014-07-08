/* 
 * File:   conversion.cpp
 * Author: davidpb
 * 
 * Created on June 1, 2014, 7:42 PM
 */

#include "conversion.hh"

conversion::conversion(string ptxt1, string ptxt2) {
    _Joint1_Txt.setDirArchivo(ptxt1);
    _Joint2_Txt.setDirArchivo(ptxt2);
    this->_Arreglo_angulos = new double[_Joint1_Txt.getCantLineas()];
    this->_TamanoMov1 = _Joint1_Txt.getCantLineas();
    this->_TamanoMov2 = _Joint2_Txt.getCantLineas();
    llenarArregloAngulos();
}

conversion::conversion(const conversion& orig) {
}

conversion::~conversion() {
}

double conversion::convertir(string* linea1, string* linea2, int n) { //Recibe arreglos ["1235,123,213"]
    string * arrXYZ = split(linea1[n]);
    string * arrXYZ_2 = split(linea2[n]);
    Vector3d a(atof(arrXYZ[0].c_str()), atof(arrXYZ[1].c_str()), atof(arrXYZ[2].c_str()));
    Vector3d b(atof(arrXYZ_2[0].c_str()), atof(arrXYZ_2[1].c_str()), atof(arrXYZ_2[2].c_str()));
    double dotProduct = a.dot(b);
    double aNormal = a.norm();
    double bNormal = b.norm();
    double cosangle = (dotProduct) / ((a.norm())*(b.norm()));
    double angleRad = acos(cosangle);
    double angleGrad = (acos(cosangle))*((180.0) / (PI));
    return angleGrad;
}

string * conversion::split(string pDato) {
    string delimiters = " ,";
    size_t current;
    size_t next = -1;
    string * arregloXYZ = new string [3];
    int contador = 0;
    do {
        current = next + 1;
        next = pDato.find_first_of(delimiters, current);
        arregloXYZ[contador] = pDato.substr(current, next - current);
        contador++;
    } while (next != string::npos);
    return arregloXYZ;
}

void conversion::llenarArregloAngulos() {
    for (int cont = 0; cont < _Joint1_Txt.getCantLineas(); cont++) {
        double angulo = convertir(_Joint1_Txt.getDatosArreglo(), _Joint2_Txt.getDatosArreglo(), cont);
        _Arreglo_angulos[cont] = angulo;
    }
}

double *conversion::getArregloAngulos() {
    return _Arreglo_angulos;
}
