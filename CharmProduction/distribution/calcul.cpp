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
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/distribution/energy_density_0.2031.txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[6000];
      double tau[117];
      double tauenergy[117];
      int j = 0;
  
  
     for(int i = 0; i<6000; i++){
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
     for(int j=0; j<77; j++){
 	      tau[j] = all[j*4];
 	      tauenergy[j] =(1.0/3.0)*(pow(all[(j)*4+3], 1.0/4.0)-pow(all[(j+40)*4+3], 1.0/4.0));
 	      cout << tau[j] << " " << tauenergy[j] << endl;}
 	      }
 	      
