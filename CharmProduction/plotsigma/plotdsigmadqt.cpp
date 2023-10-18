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
      sprintf(filexsec,"/home/tf275865/Bureau/test/dsigmadqt.csv");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[6000];
      double y[900];
      double dNdy[900];

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
 		  cout << all[counter] << " ";
  		  counter++;
  	  }
     }
      while(j<900){
 	      y[j] = all[j*3];
 	      dNdy[j] = 26.98*pow(10,3)*all[j*3+2]*pow(10, -12);
 	      j++;
	      }

for (int k = 0; k<900; k++){
  	    cout << y[k] << " " << dNdy[k] << endl;
  	         } 
}

