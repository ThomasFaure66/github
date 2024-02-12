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
    Konfig CommandlineArguments(argc,argv);
 
 // COLLISION PARAMETERS //
    double EtaOverS=0.32; double Area=110; 
    
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
    std::cerr << "#CALCULATING DILEPTON PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION << std::endl;
    
    
    // DILEPTON PARAMTERS //
    double Q = 2.0;

    double qTMin=0; double qTMax=10.0; double TauMin=0.0; double TauMax=2;
    
    
    CommandlineArguments.Getval("qTMin",qTMin);
    CommandlineArguments.Getval("qTMax",qTMax);
    CommandlineArguments.Getval("TauMin",TauMin);
    CommandlineArguments.Getval("TauMax",TauMax);
    

    
    
    // MONTE CARLO SAMPLING //
    int NSamples=5120000;
    CommandlineArguments.Getval("NSamples",NSamples);
    
    // SEED RANDOM NUMBER GENERATOR //
    srand48(time(0));
    
    // SETUP INTERPOLATORS FOR HYDRO ATTRACTORS //
    HydroAttractor::Setup();
    
    
  // CALCULATE DILEPTON PRODUCTION -- dN/dQdyQ //
        int Ntau=100; double yQ=0.0; double dNchdEta = 2240.0;
        
        CommandlineArguments.Getval("Ntau",Ntau);
        CommandlineArguments.Getval("yQ",yQ);
        

    
        // WRITE HEADER //
        std::cout << "#1-Q [GeV] 2--dN/dQdY [GeV-1] 3--dN_{PreEq}/dQdY [GeV-1] 3--dN_{Hydro}/dQdY [GeV-1]" << std::endl;
        
        for(int itau=0;itau<Ntau;itau++){
    
            double Tau=TauMin+itau*(TauMax-TauMin)/double(Ntau-1);
    //	cout << "Q : " << Q << endl;
    
            double dNlldQdY=0.0;
            double dNlldQdYPreEq=0.0;
            double dNlldQdYHydro=0.0;


            for(int i=0;i<NSamples;i++){
                
                double dN,dNPreEq,dNHydro;
                DileptonRates::SampledNdQdtaudy(Q,qTMin,qTMax,Tau,yQ,dNchdEta,Area,EtaOverS,dN,dNPreEq,dNHydro);
                dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro;
                

            }
            dNlldQdY/=double(NSamples);
            dNlldQdYPreEq/=double(NSamples);
            dNlldQdYHydro/=double(NSamples);


    
    
            std::cout << Tau  << " " << dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro ;

    		cout << endl;
        }
     

 // EXIT //
    return 0;
}
    
    
