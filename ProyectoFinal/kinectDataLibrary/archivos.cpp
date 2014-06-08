/* 
 * File:   archivos.cpp
 * Author: davidpb
 * 
 * Created on May 31, 2014, 3:00 PM
 */

#include "archivos.hh"

archivos::archivos() {
}

archivos::archivos(const archivos& orig) {
}

archivos::~archivos() {
}

/**
  @brief Método que retorna la cantidad de lineas de cada archivo.
  @param No recibe parámetros.
  @returns _CantLineas - int de cantidad de lineas analizadas. 
     */
int archivos::getCantLineas() {
    return _CantLineas;
}

/**
  @brief Método que establece el valor de _CanLineas.
  @param No recibe parámetros.
  @returns Método sin retorno. 
     */
void archivos::setCantLineas() {
    string line;
    ifstream myfile(_DirArchivo.c_str());
    _CantLineas = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            _CantLineas = _CantLineas + 1;
        }
        myfile.close();
    }
}

/**
  @brief Método que retorna la dirección del archivo de texto.
  @param No recibe parámetros.
  @returns _DirArchivo - String que almacena la dirección donde se encuentra el archivo.
     */
string archivos::getDirArchivo() {
    return _DirArchivo;
}

/**
  @brief Método que establece el nombre del archivo de texto que se quiere cargar.
     * en este caso seran cada uno de los joints.
  @param pDato, String que recibe el nombre del archivo a leer.
  @returns Método sin retorno.
     */
void archivos::setDirArchivo(string pDato) {
    this->_DirArchivo = pDato;
    setCantLineas();
    guardarEnArreglo();
}

/**
  @brief Método que lee y guarda la información del archivo de texto en un arreglo.
  @param pDato, String que recibe el nombre del archivo a leer.
  @returns Método sin retorno.
     */
void archivos::guardarEnArreglo() {
    _DatosArreglo = new string[_CantLineas];
    string line;
    ifstream myfile(_DirArchivo.c_str());
    int _Contador = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {

            _DatosArreglo [_Contador] = line;
            _Contador = _Contador + 1;
        }
        myfile.close();
    }
}

 /**
  @brief Método que retorna un arreglo con la información de los archivos de texto.
  @param No recibe parámetros.
  @returns *_DatosArreglo - Arreglo con posiciones X, Y, Z de los joints. 
     */
string * archivos::getDatosArreglo() {
    return _DatosArreglo;
}








