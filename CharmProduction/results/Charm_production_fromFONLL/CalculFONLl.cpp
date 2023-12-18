#include <iostream>
#include <sstream>
#include <string>
#include<math.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>


#define M_HBARC 0.197
using namespace std;


int main() {
    
    
  //  // SAVE DNDY values

	char filexsec2[6000];
      sprintf(filexsec2,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/Charm_production_fromFONLL/Charmproduction_centralityaveraged.txt");
      ifstream dataFile2(filexsec2);
      int counter2 = 0;
      string line2;
      double all2[600];
      double sigma[40];
      double y[40];
      int k = 0;
  
  
     for(int i = 0; i<600; i++){
 	    all2[i] = 0;
      }
      
      while(getline(dataFile2, line2)){
  	  istringstream iss2(line2);
  	  string token2;
	  while(getline(iss2, token2, ' ')){
		  double num_float2 = stod(token2);
 		  all2[counter2] = num_float2;
  		  counter2++;
  	  }
     }
      while(k<40){
              double exp = 1165.0*pow(10, -6)*6.28*pow(10,3);
 	      sigma[k] = 0.36*all2[k*2+1]*(exp/3.11035);
 	      y[k] = all2[k*2];
 	      k++;
	      }
      for(int h = 0; h<40;h++){
      	cout << y[h] << " " << sigma[h] << endl;}
		}
