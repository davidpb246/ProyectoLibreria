/* 
 * File:   C_matriz.h
 * Author: davidpb
 *
 * Created on June 19, 2014, 12:20 PM
 */

#ifndef C_MATRIZ_H
#define	C_MATRIZ_H

class C_matriz {
public:
    C_matriz(int=1, int=1);
    C_matriz(const C_matriz &);
    virtual ~C_matriz();
    float get(int fila, int columna) const;
    void set(int fila, int columna, float dato);
    C_matriz &operator = (const C_matriz &);
    float operator()(int, int);
    void desplegar(void);
    C_matriz operator+(const C_matriz &);
    C_matriz operator*(const float &);
    
private:
    int filas;
    int columnas;
    float *ptr_data;
};

#endif	/* C_MATRIZ_H */

