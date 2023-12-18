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
      char filexsec[6000];
      sprintf(filexsec,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/results/centralityaveraged/mQ1.6/dCharmdy_PreEq_mQ1.6_qSupp1_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centralityaveraged.txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double y[40];
      double PreEq[40];
      int j = 0;
  
  
     for(int i = 0; i<600; i++){
 	    all[i] = 0;
      }
      
      while(getline(dataFile, line)){
  	  istringstream iss(line);
  	  string token;
	  while(getline(iss, token, ' ')){
		  double num_float = stod(token);
 		  all[counter] = num_float;
  		  counter++;
  	  }
     }
      while(j<40){
 	      y[j] = all[j*2];
 	      PreEq[j] = all[j*2+1];
 	      j++;
	      }
		
	char filexsec2[6000];
      sprintf(filexsec2,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/Charm_production_fromFONLL/Charmproduction_centralityaveraged.txt");
      ifstream dataFile2(filexsec2);
      int counter2 = 0;
      string line2;
      double all2[600];
      double sigma[40];
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
 	      sigma[k] = 0.36*all2[k*2+1]*(exp/2.44853);
 	      k++;
	      }
      for(int h = 0; h<40;h++){
      	double rapport = 100.0*PreEq[h]/sigma[h];
      	cout << y[h] << " " << rapport << " " << sigma[h] << endl;}
		}
