#include <iostream>
#include <sstream>
#include <string>
#include<math.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cmath>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>


#define M_HBARC 0.197
using namespace std;

int main(){
	double m=1.5;
	double min=3;
	double max=12;
	
	for(int i=0 ; i<100; i++){
	
        double Q = min+i*(max-min)/99;
       	double alphas = 0.3;
        double v = sqrt(1.0-(4.0*m*m)/(Q*Q));
        double sigma=((M_PI*alphas*alphas)/(2.0*Q*Q))*(((11.0/4.0)-(3.0/2.0)*v*v+(1.0/12.0)*v*v*v*v)*atanh(v)-(v/24.0)*(59.0-31.0*v*v));
        cout << Q << " " << sigma << endl;
}	
}


