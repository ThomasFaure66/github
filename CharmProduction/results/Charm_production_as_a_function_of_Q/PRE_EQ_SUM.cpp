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
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_Q/dCharmdQdy_gg_mQ1.5_qSupp0_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[6000];
      double y[300];
      double gg[300];
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
      while(j<300){
 	      y[j] = all[j*4];
 	      gg[j] = all[j*4+2];
 	      j++;
	      }
		
	char filexsec2[6000];
      sprintf(filexsec2,"/home/tf275865/Bureau/Stage_code/CharmProduction/results/Charm_production_as_a_function_of_Q/dCharmdQdy_qq_mQ1.5_qSupp1_NSamples1million_etaovers0.16_alphas0.3_centrality0_5_midrapidity.txt");
      ifstream dataFile2(filexsec2);
      int counter2 = 0;
      string line2;
      double all2[6000];
      double qq[300];
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
      while(k<300){
 	      qq[k] = all[k*4+2];
 	      k++;
	      }
      for(int h = 0; h<300;h++){
      	double sum = gg[h]+qq[h];
      	cout << y[h] << " " << sum << endl;}
		}
