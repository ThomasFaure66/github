#include <iostream>
#include <sstream>
#include <string>

#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>


#define M_HBARC 0.197
using namespace std;
double alphaEM=1.0/137.0; double mllSqr=0.0; double qFSqrSum=1.0/9.0+4.0/9.0+1.0/9.0;

int QUARK_SUPPRESSION=1;

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
#include "DileptonRates.cpp"


// COMMANDLINE OPTIONS //
#include "IO/cfile.c"

int main(int argc, char* argv[]) {
    
    // SET COMMANDLINE ARGUMENTS //
    Konfig CommandlineArguments(argc,argv);
   

//    // SAVE DNDY values
      char filexsec[6000];
      sprintf(filexsec,"/home/tf275865/Bureau/DileptonProduction/src/dNdy.csv");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all[600];
  
  
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

    // COLLISION PARAMETERS //
    double EtaOverS=0.32; double dNchdEta= all[3]; double Area=110;
    
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("Nch",dNchdEta);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
    std::cerr << "#CALCULATING DILEPTON PRODUCTION FOR dNchdEta=" << dNchdEta << " Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION << std::endl;
    
    
    // DILEPTON PARAMTERS //
    double QMin=1.5; double QMax=5.0;

    CommandlineArguments.Getval("QMin",QMin);
    CommandlineArguments.Getval("QMax",QMax);
    
    double qTMin=0.001; double qTMax=10.0; double TauMin=0.0; double TauMax=40.0;
    
    CommandlineArguments.Getval("qTMin",qTMin);
    CommandlineArguments.Getval("qTMax",qTMax);
    CommandlineArguments.Getval("TauMin",TauMin);
    CommandlineArguments.Getval("TauMax",TauMax);
    
    std::cerr << "#KINEMATIC CUTS ARE qT=" << qTMin << " - " << qTMax << " AND  tau=" << TauMin << "-" << TauMax << " fm" << std::endl;
    
    
    // MONTE CARLO SAMPLING //
    int NSamples=5120000;
    CommandlineArguments.Getval("NSamples",NSamples);
    
    // SEED RANDOM NUMBER GENERATOR //
    srand48(time(0));
    
    // SETUP INTERPOLATORS FOR HYDRO ATTRACTORS //
    HydroAttractor::Setup();
    
//    // CALCULATE DILEPTON PRODUCTION -- qT //
//    int NQ=15; double yQ=2.0;
//    
//    CommandlineArguments.Getval("NQ",NQ);
//    CommandlineArguments.Getval("yQ",yQ);
//    
//    std::cerr << "#CALCULATING FOR qT=" << qTMin << " - " << qTMax << " IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//
//    // WRITE HEADER //
//    std::cout << "#1-qT [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
//    
//    for(int iqT=0;iqT<NQ;iqT++){
//
//        double qT=qTMin+iqT*(qTMax-qTMin)/double(NQ-1);
////	cout << "Q : " << Q << endl;
//
//        double dNlldQdY=0.0;
//        double dNlldQdYPreEq=0.0;
//        double dNlldQdYHydro=0.0;
//        
//        for(int i=0;i<NSamples;i++){
//            
//            double dN,dNPreEq,dNHydro;
//            DileptonRates::SampledNdqTdy(QMin,QMax,qT,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,dN,dNPreEq,dNHydro);
//            dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro;
//
//        }
//        dNlldQdY/=double(NSamples);
//        dNlldQdYPreEq/=double(NSamples);
//        dNlldQdYHydro/=double(NSamples);
//
//
//        std::cout << qT << " " << dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro << std::endl;
//
//    }
//   
//      // CALCULATE DILEPTON PRODUCTION -- dN/dQdy with dNchdEta
//
//      int NQ=15; double yQ=2.0; double NchMin= 100; double NchMax= 3000; int NNch=15;
//      
//      CommandlineArguments.Getval("NQ",NQ);
//      CommandlineArguments.Getval("yQ",yQ);
//      
//      std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << " IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//  
//      // WRITE HEADER //
//      std::cout << "#1-Q [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
//      
//      for(int iNch=0;iNch<NNch;iNch++){
//          
//                  double Nch=NchMin+iNch*(NchMax-NchMin)/double(NNch-1);
//       		  for(int iQ=0;iQ<NQ;iQ++){
//			  double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
//  //	cout << "Q : " << Q << endl;
//			  double dNlldQdY=0.0;
//                          double dNlldQdYPreEq=0.0;
//                          double dNlldQdYHydro=0.0;
//          
//                          for(int i=0;i<NSamples;i++){
//              
//                               double dN,dNPreEq,dNHydro;
//                               DileptonRates::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,Nch,Area,EtaOverS,dN,dNPreEq,dNHydro);
//                               dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro;
//  
//          }
//            dNlldQdY/=double(NSamples);
//            dNlldQdYPreEq/=double(NSamples);
//            dNlldQdYHydro/=double(NSamples);
//    
//    
//            std::cout << Q << " " << Nch << " " <<  dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro << std::endl;
//    
//        }
//        }
//  
      // CALCULATE DILEPTON PRODUCTION -- dN/dQdy //
      int NQ=15; double yQ=2.0;
      
      CommandlineArguments.Getval("NQ",NQ);
      CommandlineArguments.Getval("yQ",yQ);
      
      std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << " IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
  
      // WRITE HEADER //
      std::cout << "#1-Q [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
      
      for(int iQ=0;iQ<NQ;iQ++){
  
          double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
  //	cout << "Q : " << Q << endl;
  
          double dNlldQdY=0.0;
          double dNlldQdYPreEq=0.0;
          double dNlldQdYHydro=0.0;
          
          for(int i=0;i<NSamples;i++){
              
              double dN,dNPreEq,dNHydro;
              DileptonRates::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,dN,dNPreEq,dNHydro);
              dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro;
  
          }
          dNlldQdY/=double(NSamples);
          dNlldQdYPreEq/=double(NSamples);
          dNlldQdYHydro/=double(NSamples);
  
  
          std::cout << " " << all[3]  << " " << dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro << std::endl;
  
      }
//   
//          // CALCULATE DILEPTON PRODUCTION -- dN/dy //
//            double yMin=-2.0; double yMax=+2.0; int NY=30;
//        
//            CommandlineArguments.Getval("yMin",QMin);
//            CommandlineArguments.Getval("yMax",QMax);
//            CommandlineArguments.Getval("NY",NY);
//        
//            std::cerr << "#CALCULATING FOR y=" << yMin << " - " << yMax << " IN " << NY << " BINS WITH Q=" <<  QMin  << " - " << QMax << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//        
//          // WRITE HEADER //
//            std::cout << "#1-Q [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
//  //    
//            for(int iY=0;iY<NY;iY++){
//        
//                double yQ=yMin+iY*(yMax-yMin)/double(NY-1);
//        
//                double dNlldY=0.0;
//  	        double dNlldYPreEq=0.0;
//  	        double dNlldYHydro=0.0;
//        
//                for(int i=0;i<NSamples;i++){
//                    
//  		  double dN, dNPreEq, dNHydro;    
//                  DileptonRates::SampledNdy(QMin,QMax,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS, dN, dNPreEq, dNHydro);
//  		  dNlldY+=dN; dNlldYPreEq+=dNPreEq; dNlldYHydro+=dNHydro;
//                }
//                dNlldY/=double(NSamples);
//  	        dNlldYPreEq/=double(NSamples);
//  	        dNlldYHydro/=double(NSamples);
//        
//                std::cout << yQ << " " << dNlldY << " " << dNlldYPreEq << " " << dNlldYHydro <<  std::endl;
//        
//            }
//    
//    
//  // CALCULATE DILEPTON PRODUCTION -- dN/dQdqTdy 
//
//      int NQ=15; double yQ=2.0; int NqT=15;
//      
//      CommandlineArguments.Getval("NQ",NQ);
//      CommandlineArguments.Getval("NqT", NqT);
//      CommandlineArguments.Getval("yQ",yQ);
//      
//      std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << " IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//  
//      // WRITE HEADER //
//      std::cout << "#1-Q [GeV] 2--qT [GeV] 3 -dN/dqTdQdY [GeV-1] " << std::endl;
//      
//      for(int iQ=0;iQ<NQ;iQ++){
//  
//          double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
//  //	cout << "Q : " << Q << endl;
//  
//          for(int iqT=0;iqT<NqT;iqT++){
//		  double qT=qTMin+iqT*(qTMax-qTMin)/double(NqT-1);
//
//		  double dNlldqTdQdY=0.0;
//		  double dNlldqTdQdYPreEq=0.0;
//		  double dNlldqTdQdYHydro=0.0;
//
//		  for(int i=0;i<NSamples;i++){
//              		 double dN,dNPreEq,dNHydro;
//			 DileptonRates::SampledNdqTdQdy(Q*Q,qT,TauMin,TauMax,yQ,dNchdEta,Area,dN,dNPreEq,dNHydro, EtaOverS);
//			 dNlldqTdQdY+=dN; dNlldqTdQdYPreEq+=dNPreEq; dNlldqTdQdYHydro+=dNHydro;
//		  }
//         	  dNlldqTdQdY/=double(NSamples);
//         	  dNlldqTdQdYPreEq/=double(NSamples);
//         	  dNlldqTdQdYHydro/=double(NSamples);
//	
//							
//		  std::cout << Q << " " << qT << " " << dNlldqTdQdY << std::endl;
//	  }	  
//
//  	}

    // EXIT //
    return 0;
}
