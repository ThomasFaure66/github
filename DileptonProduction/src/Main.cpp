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
#include "DileptonRates2.cpp"

// COMMANDLINE OPTIONS //
#include "IO/cfile.c"

int main(int argc, char* argv[]) {
    
    // SET COMMANDLINE ARGUMENTS //
    Konfig CommandlineArguments(argc,argv);
   

  //  // SAVE DNDY values
//      char filexsec[6000];
//      sprintf(filexsec,"/home/tf275865/Bureau/Stage_code/DileptonProduction/src/dNdy.csv");
//      ifstream dataFile(filexsec);
//      int counter = 0;
//      string line;
//      double all[600];
//      double y[34];
//      double dNdy[34];
//      double ytot[67];
//      double dNdytot[67];
//      int j = 0;
//      int l=0;
//
//  
//  
//     for(int i = 0; i<600; i++){
// 	    all[i] = 0;
//      }
//      
//      while(getline(dataFile, line)){
//  	  istringstream iss(line);
//  	  string token;
//	  while(getline(iss, token, ',')){
//		  double num_float = stod(token);
// 		  all[counter] = num_float;
//  		  counter++;
//  	  }
//     }
//      while(j<34){
// 	      y[j] = all[j*8];
// 	      dNdy[j] = all[j*8+3];
// 	      ytot[2*j]=y[j];
// 	      dNdytot[2*j]=dNdy[j];
// 	      j++;
//	      }
//	while(l+1 < 34){
//		double yi = (y[l]+y[l+1])/2.0;
//		double dNdyi =(dNdy[l]+dNdy[l+1])/2.0;
//		ytot[2*l+1]= yi;
//		dNdytot[2*l+1]=dNdyi;
//		l++;}
  

//        Plot dNdy
//      for (int k = 0; k<34; k++){
//  	    cout << y[k] << " " << dNdy[k] << endl;
//      }
//    

    // COLLISION PARAMETERS //
    double EtaOverS=0.32; double Area=110;
    
  	 
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
    std::cerr << "#CALCULATING DILEPTON PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION << std::endl;
    
    
    // DILEPTON PARAMTERS //
    double QMin=0; double QMax=8;

    CommandlineArguments.Getval("QMin",QMin);
    CommandlineArguments.Getval("QMax",QMax);
    
    double qTMin=0; double qTMax=10.0; double TauMin=0.0; double TauMax=40.0;
    
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
          // CALCULATE DILEPTON PRODUCTION -- dN/dQdy for differents values of y //
//          int NQ=1500;
//         
//          CommandlineArguments.Getval("NQ",NQ);
//          
//          std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << " IN " << NQ << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//  
//          // WRITE HEADER //
//          std::cout << "#1-Q [GeV] 2--y  3--dN/dy 4--dN/dQdY 5--dN/dQdYpreEq 6--dN/dQdYHydro " << std::endl;
//          
//  	
//          for(int iQ=0;iQ<NQ;iQ++){
//      
//              double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
//      //	cout << "Q : " << Q << endl;
//      
//              double dNlldQdY[34];
//              double dNlldQdYPreEq[34];
//              double dNlldQdYHydro[34];
//  
//  	    for (int ii =0; ii<34; ii++){
//  		    dNlldQdY[ii]=0;
//  		    dNlldQdYPreEq[ii]=0;
//  		    dNlldQdYHydro[ii]=0;}
//  	    cout << Q << " ";
//  
//  
//              for(int h=0; h*4<34;h++){ 
//  		    double yQ = y[h*4];
//  		    double dNchdEta = dNdy[h*4];
//              for(int i=0;i<NSamples;i++){
//                  
//                  double dN,dNPreEq,dNHydro;
//                  DileptonRates::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,dN,dNPreEq,dNHydro);
//                  dNlldQdY[h*4]+=dN; dNlldQdYPreEq[h*4]+=dNPreEq; dNlldQdYHydro[h*4]+=dNHydro;
//      
//              }
//              dNlldQdY[h*4]/=double(NSamples);
//              dNlldQdYPreEq[h*4]/=double(NSamples);
//              dNlldQdYHydro[h*4]/=double(NSamples);
//  
//  	    cout << yQ << " " << dNchdEta << " " << dNlldQdY[h*4] << " " << dNlldQdYPreEq[h*4] << " " << dNlldQdYHydro[h*4] << " ";
//  	    }
//  	    cout << endl;
//      
//      
//      
//             
//  	}

        // CALCULATE DILEPTON PRODUCTION -- dN/dQdy //
        int NQ=300; double yQ=2.0; double dNchdEta = 1900;
        
        CommandlineArguments.Getval("NQ",NQ);
        CommandlineArguments.Getval("yQ",yQ);
        
        std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << " IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
    
        // WRITE HEADER //
        std::cout << "#1-Q [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
        
        for(int iQ=0;iQ<NQ;iQ++){
    
            double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
    //	cout << "Q : " << Q << endl;
    
            double dNlldQdY=0.0;
            double dNlldQdY2=0.0;
	
            for(int i=0;i<NSamples;i++){
                
                double dN,dNPreEq,dNHydro;
                DileptonRates::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,dN,dNPreEq,dNHydro);
                dNlldQdY+=dN;
                double dN2,dNPreEq2,dNHydro2;
                DileptonRates2::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,dN2,dNPreEq2,dNHydro2);
                dNlldQdY2+=dN2;
    
            }
            dNlldQdY/=double(NSamples);
            dNlldQdY2/=double(NSamples);

    
    
            std::cout << Q << " " << dNlldQdY << " "  << dNlldQdY2 << std::endl;
    
        }
//
//
//              //  CALCULATE DILEPTON PRODUCTION -- dN/dy //
//             
//          
//              //   std::cerr << "#CALCULATING FOR y=" << yMin << " - " << yMax << " IN " << NY << " BINS WITH Q=" <<  QMin  << " - " << QMax << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
//            
//             //    WRITE HEADER //
//                  std::cout << "#1-y 2--dN/dY 3--QMin 4--QMax 5-dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
//        //    
//    
//                     double dNlldY[67];
//                     double dNlldYPreEq[67];
//                     double dNlldYHydro[67];
//    
//    	         for (int ii =0; ii<67; ii++){
//    		        dNlldY[ii]=0;
//    		        dNlldYPreEq[ii]=0;
//    		        dNlldYHydro[ii]=0;}
//    		        
//    		   for(int h=0; h<67;h++){ 
//    		        double yQ = ytot[h];
//    		        double dNchdEta = dNdytot[h];
//    		    cout << yQ << " " << dNchdEta << " ";
//                   
//                     for(int i=0;i<NSamples;i++){
//                          
//        		  double dN, dNPreEq, dNHydro;    
//                      DileptonRates::SampledNdy(QMin,QMax,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS, dN, dNPreEq, dNHydro);
//        		  dNlldY[h]+=dN; dNlldYPreEq[h]+=dNPreEq; dNlldYHydro[h]+=dNHydro;
//                      }
//                     dNlldY[h]/=double(NSamples);
//        	         dNlldYPreEq[h]/=double(NSamples);
//        	         dNlldYHydro[h]/=double(NSamples);
//        	         
//              
//                      std::cout << dNlldY[h] << " " << dNlldYPreEq[h] << " " << dNlldYHydro[h] << " ";
//                  
//                  cout << endl;
//                  }
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
