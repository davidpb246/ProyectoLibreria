#include <cstdlib>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <math.h>
#define PI (3.141592653589793)


using namespace std;
using namespace Eigen; /*para q es esto*/


int main(){
	
	/*double suma;
	suma = 239*0.2;
	cout << "porciento " << int(suma) << endl;
	
	Vector3d a(9,6,2.3);
	Vector3d b(4.5,0,78);
    //a.normalize();
    //b.normalize();
    double dotProduct = a.dot(b);
    cout << "Dot product: " << dotProduct << endl;
    //double q = 5;
    //double w = 4;
    //double e = q/w;
    //cout << "division: " << e << endl;
    double aNormal = a.norm();
    double bNormal = b.norm();
    cout << "normaA: " << aNormal << endl;
    cout << "normaB: " << bNormal << endl;
    
    double cosangle = (dotProduct)/((a.norm())*(b.norm()));
	cout << "CosenoAngle " << cosangle << endl;
	double angleRad = acos(cosangle);
	double angleGrad = (acos(cosangle))*((180.0)/(PI));
	cout << "AngleRad " << angleRad << endl;
	cout << "AngleGrad " << angleGrad << endl;*/
        
        
    int arreglo [20] = {1,2, 3,4, 5,6, 7,8, 9,10, 11,12, 13,14, 15,16, 17,18, 19,20};
    float arreglo_prom [10] = {0,0,0,0,0,0,0,0,0,0};
    int selecciona [10] = {1,1,1,1,1,1,1,1,1,1};
    
    //FUNCION SUMA DE LOS DATOS DE CADA 10% DE CADA ARREGLO fsuma
    
    for(int k = 0; k<10; k++){
        int sumatoria = 0;
	for(int i = int(k*20*0.1); i < int(20*0.1*(1+k)); i++){
            sumatoria = sumatoria + arreglo[i];
        }
	cout << "sumatoria " << sumatoria << endl;
	arreglo_prom[k] = float(sumatoria)/float(int(20*0.1));
	cout << "Arreglo promedios " << arreglo_prom[k] << endl;
    }

    float arreglo_prom1 [10] = {20,26,32.0,40,46,53,56,68,75,80};
    float arreglo_prom2 [10] = {23,26,37.1,40,42,53,60,62,70,74};
    //                                 x               x     x
    
    
    //int compara_datos(/*arreglo1.fsuma*/, /*arreglo2.fsuma*/){ //entran los arreglos que tienen los promedios de los 10%'s, donde la posicion [0] tiene el primer 10%
	//seria bueno primero imprimir los dos arreglos
        //cout <<"promedio de los datos primeros del arreglo 1: " << arreglo_prom1 <<endl;
	//cout <<"promedio de los datos primeros del arreglo 2: " << arreglo_prom2 <<endl;
    for(int i = 0; i < 10; i++){
        if (arreglo_prom1[i] > arreglo_prom2[i] + 5.0){
            selecciona[i] = 0;
        }
        else if (arreglo_prom1[i] < arreglo_prom2[i] - 5.0){
            selecciona[i] = 0;
        }
    }
    for(int j=0; j<10; j++){
        cout << "la posicion " << j << " de selecciona tiene: " << selecciona[j] <<endl;
    }
    
    //}
    
    return 0;
    


}

