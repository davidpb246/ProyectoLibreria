/* 
 * File:   archivos.hh
 * Author: davidpb
 *
 * Created on May 31, 2014, 3:00 PM
 */

#include <string>
#include <iostream>
#include <fstream>


using namespace std;

#ifndef ARCHIVOS_HH
#define	ARCHIVOS_HH

class archivos {
public:
    archivos();
    archivos(const archivos& orig);
    virtual ~archivos();
    string getDirArchivo();
    int getCantLineas();
    void guardarEnArreglo();
    void setCantLineas();
    string * getDatosArreglo();

    /**
  @brief Método que establece el nombre del archivo de texto que se quiere cargar.
     * en este caso seran cada uno de los joints.
  @param pDato, String que recibe el nombre del archivo a leer.
  @returns Método sin retorno.
     */
    void setDirArchivo(string pDato);

private:
    int _CantLineas;
    string _DirArchivo;
    string *_DatosArreglo;
};

#endif	/* ARCHIVOS_HH */


