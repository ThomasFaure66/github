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
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/dCharmdy_gg_mQ1.5_qSupp0_NSamples1000000_QMin3_QMax12_etaovers0.16.txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double y[67];
      double gg[67];
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
      while(j<67){
 	      y[j] = all[j*5];
 	      gg[j] = all[j*5+2];
 	      j++;
	      }
		
	char filexsec2[6000];
      sprintf(filexsec2,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/sigmagood.txt");
      ifstream dataFile2(filexsec2);
      int counter2 = 0;
      string line2;
      double all2[600];
      double sigma[33];
      int k = 0;
  
  
     for(int i = 0; i<600; i++){
 	    all2[i] = 0;
      }
      
      while(getline(dataFile2, line2)){
  	  istringstream iss2(line2);
  	  string token2;
	  while(getline(iss2, token2, ' ')){
		  double num_float2 = stod(token2);
 		  all[counter2] = num_float2;
  		  counter2++;
  	  }
     }
      while(k<33){
 	      sigma[k] = all[k*2+1];
 	      k++;
	      }
      for(int h = 0; h<33;h++){
      	double rapport = 100.0*gg[2*h]/sigma[h];
      	cout <<y[2*h] << " " << rapport << endl;}
		}
