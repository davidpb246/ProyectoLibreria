/* DOCUMENTAR COMO DOXYGEN
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


#include <cstdlib>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <math.h>
#define PI (3.141592653589793)


using namespace std;
using namespace Eigen; /*para q es esto*/



int main(){
	Vector3d a(9,6,2.3);
	Vector3d b(4.5,0,78);
    //a.normalize();
    //b.normalize();
    double dotProduct = a.dot(b);
    cout << "Dot product: " << dotProduct << endl;
    /* double q = 5;
    double w = 4;
    double e = q/w;
    cout << "division: " << e << endl;*/
    double aNormal = a.norm();
    double bNormal = b.norm();
    cout << "normaA: " << aNormal << endl;
    cout << "normaB: " << bNormal << endl;
    
    double cosangle = (dotProduct)/((a.norm())*(b.norm()));
	cout << "CosenoAngle " << cosangle << endl;
	double angleRad = acos(cosangle);
	double angleGrad = (acos(cosangle))*((180.0)/(PI));
	cout << "AngleRad " << angleRad << endl;
	cout << "AngleGrad " << angleGrad << endl;
	
	int arreglo [20] = {1,2, 3,4, 5,6, 7,8, 9,10, 11,12, 13,14, 15,16, 17,18, 19,20};
	
	for(int j=0; j<20; j++){
		cout << "la posicion " << j << " de arreglo tiene: " << arreglo[j] <<endl;
	}
	
	return 0;
    

}

