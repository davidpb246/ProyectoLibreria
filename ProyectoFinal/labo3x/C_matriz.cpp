/* 
 * File:   C_matriz.cpp
 * Author: davidpb
 * 
 * Created on June 19, 2014, 3:01 PM
 */

#include <iostream>
#include "C_matriz.h"
#include <cstdlib>

using namespace std;

C_matriz::C_matriz(int, int) {
}

C_matriz::C_matriz(const C_matriz& orig) {
}

C_matriz::~C_matriz() {
}

C_matriz::desplegar_matriz(int x, int y, const C_matriz &Matriz) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cout << Matriz.get(i, j) << "\t";
        }
        cout << endl;
    }
};

C_matriz::llenar_matriz(int x, int y, C_matriz &Matriz) {
    float elemento = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            Matriz.set(i, j, elemento);
            elemento++;
        }
    }
};



