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

#include "../HydroAttractor.cpp"
#include "../PhaseSpaceDistribution.cpp"
#include "getphasedistribution.cpp"


// COMMANDLINE OPTIONS //
#include "../IO/cfile.c"

int main(int argc, char* argv[]) {
    Konfig CommandlineArguments(argc,argv);
 
 // COLLISION PARAMETERS //
    double EtaOverS=0.16; double Area=110; double alphas=0.3;
    
    CommandlineArguments.Getval("alphas",alphas);
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    

    // CHARM PARAMETERS //
    double Q=4;
    CommandlineArguments.Getval("M_pair",Q);
    
    double qT=5; double TauMin=0.0001; double TauMax=0.203+0.0001;
    
    CommandlineArguments.Getval("qT",qT);
    CommandlineArguments.Getval("TauMin",TauMin);
    CommandlineArguments.Getval("TauMax",TauMax);
    
    std::cerr << "#CALCULATING CHARM/ANTICHARM PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION << " Alpha-s " << alphas << std::endl;
    std::cerr << "#KINEMATIC CUTS ARE qT=" << qT << "GeV tau=" << TauMin << "-" << TauMax << " fm" << " Q=" << Q << "GeV"  << std::endl;
    
    // MONTE CARLO SAMPLING //
    int NSamples=5120000;
    CommandlineArguments.Getval("NSamples",NSamples);
    
    // SEED RANDOM NUMBER GENERATOR //
    srand48(time(0));
    
    // SETUP INTERPOLATORS FOR HYDRO ATTRACTORS //
    HydroAttractor::Setup();
    
    
   // CALCULATE PHASE-SPACE DISTRIBUTION, TEMPERATURE, ENERGY DENSITY AS A FUNCTION OF TAU //
    int Ntau=117; double yQ=0; double dNchdEta = 2240;
        
    CommandlineArguments.Getval("Ntau",Ntau);
    CommandlineArguments.Getval("yQ",yQ);
    
    // WRITE HEADER //
    std::cout << "#1--Tau [fm/c] #2--GLUON DISTRIBUTION #3--QUARK DISTRIBUTION #4--TEMPERATURE [GeV] #5--ENERGY DENSITY [GeV^{4}]" << std::endl;
        
    for(int itau=0;itau<Ntau;itau++){
    	double Tau=TauMin+itau*(TauMax-TauMin)/double(Ntau-1);
        double d1=0.0;
        double d2=0.0;
        double d3=0.0;
        double d4=0.0;

        for(int i=0;i<NSamples;i++){
        	double fg,fq,temperature, energy;
                getphasedistribution::phasedistribution(Q,qT,Tau,yQ,dNchdEta,Area,EtaOverS,alphas,fg,fq,temperature, energy);
                d1+=fg; d2+=fq; d3+=temperature; d4+=energy;
                }
                
        d1/=double(NSamples);
        d2/=double(NSamples);
        d3/=double(NSamples);
        d4/=double(NSamples);
        
	std::cout << Tau  << " " << d1 << " " << d2 << " " << d3  << " " << d4;
	cout << endl;
        }
     
 // EXIT //
    return 0;
}
    
    
