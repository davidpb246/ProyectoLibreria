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

int archivos::getCantLineas() {
    return _CantLineas;
}

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

string archivos::getDirArchivo() {
    return _DirArchivo;
}

void archivos::setDirArchivo(string pDato) {
    this->_DirArchivo = pDato;
    setCantLineas();
    guardarEnArreglo();
}

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

string * archivos::getDatosArreglo() {
    return _DatosArreglo;
}








