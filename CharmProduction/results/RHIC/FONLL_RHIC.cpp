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

      char filexsec[6000];
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/plotsigma/sigma_RHIC.csv");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double y[20];
      double dNdy[20];

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
      while(j<20){
 	      y[j] = all[j*2];
 	      dNdy[j] = (1068.4/41.3)*pow(10,3)*all[j*2+1]*pow(10, -12);
 	      j++;
	      }

for (int k = 0; k<20; k++){
  	    cout << y[k] << " " << dNdy[k] << endl;
  	         } 
}

