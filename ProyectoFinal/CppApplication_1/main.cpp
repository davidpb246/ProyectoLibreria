
/* 
 * File:   main.cpp
 * Author: davidpb
 *
 * Created on June 7, 2014, 6:46 PM
 */
#include <cstdlib>
#include <eigen3/Eigen/Dense>
#include <math.h>
#include <stdlib.h>     /* atof */
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string * _ArregloMov1[2] = {"2.345","2.356"};
    string * _ArregloMov2[2] = {"2.345","2.356"};
    
    double pos1y = atof(_ArregloMov1[0].c_str())-(_ArregloMov2[0].c_str());

    return 0;
}

