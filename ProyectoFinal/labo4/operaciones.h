/* 
 * File:   operaciones.h
 * Author: davidpb
 *
 * Created on June 19, 2014, 12:46 PM
 */

#ifndef OPERACIONES_H
#define	OPERACIONES_H

class operaciones {
public:
    operaciones();
    operaciones(const operaciones& orig);
    virtual ~operaciones();
    void suma();
    void resta();
    void norma();
    void producto_escalar();
    void producto_vectorial();
    
private:

};

#endif	/* OPERACIONES_H */

