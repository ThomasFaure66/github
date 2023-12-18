#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
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
	sprintf(filexsec, "/home/tf275865/Bureau/Stage_code/CharmProduction/results/Charm_production_fromFONLL/Charmproduction_centralityaveraged.txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double y[40];
      double dNdy[40];
      double ytot[79];
      double dNdytot[79];
      int j = 0;
      int l=0;
      int k=0;
  
  
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
 	      dNdy[j] = all[j*2+1];
 	      ytot[2*j]=y[j];
 	      dNdytot[2*j]=dNdy[j];
 	      j++;
	      }
	while(l+1 < 40){
		double yi = (y[l]+y[l+1])/2.0;
		double dNdyi =(dNdy[l]+dNdy[l+1])/2.0;
		ytot[2*l+1]= yi;
		dNdytot[2*l+1]=dNdyi;
		l++;}
		
	while(k<79){
	cout << ytot[k] << " " << dNdytot[k] << endl;
	k+=1;
				}
				}
				
		
		
		  



