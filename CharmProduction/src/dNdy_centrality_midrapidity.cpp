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
      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/CharmProduction/src/dNchdeta_A_Npart_midrapidity_5points.csv");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
      double Npart[5];
      double A[5];
      double dNchdeta[5];
      int j = 0;


  
  
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
      while(j<5){
 	      Npart[j] = all[j*3];
 	      A[j]=all[j*3+1];
 	      dNchdeta[j] = 1.161*all[j*3+2];
 	      j++;
	      }
 
 // COLLISION PARAMETERS //
    double EtaOverS=0.32; double Area=110; double MQ=1.5;
    
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
    
                     double dNlldY[11];
                     double dNlldYPreEq[11];
                     double dNlldYHydro[11];
                     double nombre = 0;
                     double yQ = 0;
    
    	         for (int ii =0; ii<5; ii++){
   		        dNlldY[ii]=0;
    		        dNlldYPreEq[ii]=0;
   		        dNlldYHydro[ii]=0;}
  		        
   		   for(int h=0; h<5;h++){ 
    		        double Np = Npart[h];
    		        double Ar=A[h];
    		        double dNchdEta = dNchdeta[h];
   		    cout << Np << " " << Ar << " " << dNchdEta << " ";
             
                    for(int i=0;i<NSamples;i++){
                          
        		  double dN, dNPreEq, dNHydro, test, test2, test3;    
                      CharmRates_gg::SampledNdy(QMin,QMax,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Ar,EtaOverS,MQ, dN, dNPreEq, dNHydro, test, test2, test3);
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
    
    
