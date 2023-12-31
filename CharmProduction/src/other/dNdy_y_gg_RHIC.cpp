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
double alphaEM=1.0/137.0; double mllSqr=0.0; double qFSqrSum=1.0/9.0+4.0/9.0+1.0/9.0;

int QUARK_SUPPRESSION=0;

double Nc=3.0;
double Nf=3.0;
double nuG=2.0*(Nc*Nc-1.0);
double nuQ=4.0*Nc*Nf;

// ENERGY DENSITIES OF QUARKS AND GLUONS //
double eGlEq(double T){
    return (M_PI*M_PI/30.0)*nuG*T*T*T*T;
}

double eQuEq(double T){
    return (7.0*M_PI*M_PI/240.0)*nuQ*T*T*T*T;
}

double eEq(double T){
    return eGlEq(T)+eQuEq(T);
}

double eNEq(double T,double qSupp){
    return eGlEq(T)+qSupp*eQuEq(T);
}


// STANDARD RANDOM NUMBER GENERATOR //
double rng(){
    return drand48();
}

#include "HydroAttractor.cpp"
#include "PhaseSpaceDistribution.cpp"
#include "CharmRates_gg.cpp"
#include "CharmRates_qq.cpp"

// COMMANDLINE OPTIONS //
#include "IO/cfile.c"

int main(int argc, char* argv[]) {
    
    // SET COMMANDLINE ARGUMENTS //
    Konfig CommandlineArguments(argc,argv);
    
  //  // SAVE DNDY values
      char filexsec[6000];
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/src/dNdeta_y_RHIC.csv");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double y[20];
      double dNdy[20];
      double ytot[39];
      double dNdytot[39];
      int j = 0;
      int l=0;

  
  
     for(int i = 0; i<600; i++){
 	    all[i] = 0;
      }
      
      while(getline(dataFile, line)){
  	  istringstream iss(line);
  	  string token;
	  while(getline(iss, token, ',')){
		  double num_float = stod(token);
 		  all[counter] = num_float;
  		  counter++;
  	  }
     }
      while(j<20){
 	      y[j] = all[j*6];
 	      dNdy[j] = all[j*6+3];
 	      ytot[2*j]=y[j];
 	      dNdytot[2*j]=dNdy[j];
 	      j++;
	      }
	while(l+1 < 20){
		double yi = (y[l]+y[l+1])/2.0;
		double dNdyi =(dNdy[l]+dNdy[l+1])/2.0;
		ytot[2*l+1]= yi;
		dNdytot[2*l+1]=dNdyi;
		l++;}
 
 // COLLISION PARAMETERS //
    double EtaOverS=0.16; double Area=100; double MQ=1.5;double alphas=0.3;
    
    CommandlineArguments.Getval("alphas",alphas);
    CommandlineArguments.Getval("M",MQ);
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
    std::cerr << "#CALCULATING CHARM/ANTICHAM PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION << " Quark mass " << MQ << std::endl;
    
    
    // DILEPTON PARAMTERS //
    double QMin=3; double QMax=12;

    CommandlineArguments.Getval("QMin",QMin);
    CommandlineArguments.Getval("QMax",QMax);
    
    double qTMin=0; double qTMax=10.0; double TauMin=0.0; double TauMax=40.0;
    
    CommandlineArguments.Getval("qTMin",qTMin);
    CommandlineArguments.Getval("qTMax",qTMax);
    CommandlineArguments.Getval("TauMin",TauMin);
    CommandlineArguments.Getval("TauMax",TauMax);
    
    std::cerr << "#KINEMATIC CUTS ARE qT=" << qTMin << " - " << qTMax << " tau=" << TauMin << "-" << TauMax << " fm" << " Q=" << QMin << "-" << QMax << std::endl;
    
    
    // MONTE CARLO SAMPLING //
    int NSamples=5120000;
    CommandlineArguments.Getval("NSamples",NSamples);
    
    // SEED RANDOM NUMBER GENERATOR //
    srand48(time(0));
    
    // SETUP INTERPOLATORS FOR HYDRO ATTRACTORS //
    HydroAttractor::Setup();
    
    
    
             //  CALCULATE CHARM/ANTICHARM PRODUCTION -- dN/dy //
             
         
             //   std::cerr << "#CALCULATING FOR y=" << yMin << " - " << yMax << " IN " << NY << " BINS WITH Q=" <<  QMin  << " - " << QMax << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
           
            //    WRITE HEADER //
                 std::cout << "#1-y 2--dNch/deta 5-dN/dY [GeV-1] 3--dN_{PreEq}/dY [GeV-1] 3--dN_{Hydro}/dY [GeV-1]" << std::endl;
        //    
    
                     double dNlldY[39];
                     double dNlldYPreEq[39];
                     double dNlldYHydro[39];
                     double nombre = 0;
    
    	         for (int ii =0; ii<39; ii++){
   		        dNlldY[ii]=0;
    		        dNlldYPreEq[ii]=0;
   		        dNlldYHydro[ii]=0;}
  		        
   		   for(int h=0; h<39;h++){ 
    		        double yQ = ytot[h];
    		        double dNchdEta = dNdytot[h];
   		    cout << yQ << " " << dNchdEta << " ";
             
                    for(int i=0;i<NSamples;i++){
                          
        		  double dN, dNPreEq, dNHydro, test, test2, test3;    
                      CharmRates_gg::SampledNdy(QMin,QMax,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,MQ,alphas, dN, dNPreEq, dNHydro, test, test2, test3);
        		  dNlldY[h]+=dN; dNlldYPreEq[h]+=dNPreEq; dNlldYHydro[h]+=dNHydro;nombre+=test2;
 //       		  if(test==1){
 //       		  	cout << "cosTheta" << " " << test << " " << endl;}

                     }
                     dNlldY[h]/=double(NSamples);
        	         dNlldYPreEq[h]/=double(NSamples);
       	         dNlldYHydro[h]/=double(NSamples);
       	         nombre/=double(NSamples);
			
             
                      std::cout << dNlldY[h] << " " << dNlldYPreEq[h] << " " << dNlldYHydro[h] ;
  
                  cout << endl;
                  }
 //                 cout << nombre << endl;
     

 // EXIT //
    return 0;
}
    
    
