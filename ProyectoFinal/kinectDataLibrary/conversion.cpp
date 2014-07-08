/* 
 * File:   conversion.cpp
 * Author: davidpb
 * 
 * Created on June 1, 2014, 7:42 PM
 */

#include "conversion.hh"

/**
  @brief Método constructor de la clase conversion, en el cual se inicializan los valores
 * de los atributos de clase, Dir_Joints, Arreglo_angulos, Tamano Mov.
  @param ptx1 ptxt2 ptxt3 ptxt4 - Strings que recibe el nombre del archivo a leer.
  @returns Método sin retorno.
 */
conversion::conversion(string ptxt1, string ptxt2, string ptxt3, string ptxt4) {
    _Joint1_Txt.setDirArchivo(ptxt1);
    string * hola = _Joint1_Txt.getDatosArreglo();
    _Joint2_Txt.setDirArchivo(ptxt2);
    _Joint3_Txt.setDirArchivo(ptxt3);
    _Joint4_Txt.setDirArchivo(ptxt4);
    this->_Arreglo_angulos = new double[_Joint1_Txt.getCantLineas()];
    this->_TamanoMov1 = _Joint1_Txt.getCantLineas();
    this->_TamanoMov2 = _Joint2_Txt.getCantLineas();
    this->_TamanoMov3 = _Joint3_Txt.getCantLineas();
    this->_TamanoMov4 = _Joint4_Txt.getCantLineas();
    llenarArregloAngulos();
}

conversion::conversion(const conversion& orig) {
}

conversion::~conversion() {
}

/**
  @brief Método convertir, que realiza la conversión de todas las posiciones XYZ 
 * a ángulos.
  @param strings linea1 linea2 linea3 linea4 int n - Cada una de las lineas del archivo de texto
 * y un int que es la cantidad de posiciones tomadas. 
  @returns double - Método que retorna un double con cada uno de los ángulos formados. 
 */
double conversion::convertir(string* linea1, string* linea2, string* linea3, string* linea4, int n) { //Recibe arreglos ["1235,123,213"]
    string * arrXYZ = split(linea1[n]);
    string * arrXYZ_2 = split(linea2[n]);
    string * arrXYZ_3 = split(linea3[n]);
    string * arrXYZ_4 = split(linea4[n]);
    double pos1x = ((atof(arrXYZ[0].c_str()))-(atof(arrXYZ_2[0].c_str())));
    double pos1y = ((atof(arrXYZ[1].c_str()))-(atof(arrXYZ_2[1].c_str())));
    double pos1z = ((atof(arrXYZ[2].c_str()))-(atof(arrXYZ_2[2].c_str())));
    double pos2x = ((atof(arrXYZ_3[0].c_str()))-(atof(arrXYZ_4[0].c_str())));
    double pos2y = ((atof(arrXYZ_3[1].c_str()))-(atof(arrXYZ_4[1].c_str())));
    double pos2z = ((atof(arrXYZ_3[2].c_str()))-(atof(arrXYZ_4[2].c_str())));
    Vector3d a(pos1x, pos1y, pos1z);
    Vector3d b(pos2x, pos2y, pos2z);
    double dotProduct = a.dot(b);
    double aNormal = a.norm();
    double bNormal = b.norm();
    double cosangle = (dotProduct) / ((a.norm())*(b.norm()));
    double angleRad = acos(cosangle);
    double angleGrad = (acos(cosangle))*((180.0) / (PI));
    return angleGrad;
}

/**
  @brief Método encargado de separar cada una de las posiciones xyz del archivo de texto, 
 * separa cada vez que encuenta una coma.
  @param string pDato - String que contiene cada una de las posiciones XYZ ej: "23.9,43.9,65.3"
  @returns string * Arreglo de String.
 */
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

/**
  @brief Método que llena un arreglo con los ángulos formados por las posiciones.
  @param Método sin parámetros.
  @returns Método sin retorno.
 */
void conversion::llenarArregloAngulos() {
    for (int cont = 0; cont < _Joint1_Txt.getCantLineas(); cont++) {
        double angulo = convertir(_Joint1_Txt.getDatosArreglo(), _Joint2_Txt.getDatosArreglo(), _Joint3_Txt.getDatosArreglo(), _Joint4_Txt.getDatosArreglo(), cont);
        _Arreglo_angulos[cont] = angulo;
    }
}

/**
  @brief Método que retorna el arreglo de ángulos.
  @param Método sin parámetros.
  @returns double * _Arreglo_angulos - Arreglo con ángulos.
 */
double *conversion::getArregloAngulos() {
    return _Arreglo_angulos;
}

