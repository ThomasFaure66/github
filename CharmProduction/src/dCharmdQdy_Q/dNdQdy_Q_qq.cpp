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

#include "../HydroAttractor.cpp"
#include "../PhaseSpaceDistribution.cpp"
#include "../CharmRates/CharmRates_qq.cpp"
#include "../CharmRates/CharmRates_gg.cpp"

// COMMANDLINE OPTIONS //
#include "../IO/cfile.c"

int main(int argc, char* argv[]) {
    
    // SET COMMANDLINE ARGUMENTS //
    Konfig CommandlineArguments(argc,argv);
    
   // COLLISION PARAMETERS //
    double EtaOverS=0.16 ; double Area=110;; double alphas=0.3;
    
    CommandlineArguments.Getval("alphas",alphas);
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
        
    // CHARM PARAMETERS //
    double MQ=1.5;
    CommandlineArguments.Getval("M",MQ);
    double QMin=3.001; double QMax=8;
    
    
    CommandlineArguments.Getval("QMin",QMin);
    CommandlineArguments.Getval("QMax",QMax);
    
    double qTMin=0; double qTMax=10.0; double TauMin=0.0; double TauMax=40.0;
    
    
    CommandlineArguments.Getval("qTMin",qTMin);
    CommandlineArguments.Getval("qTMax",qTMax);
    CommandlineArguments.Getval("TauMin",TauMin);
    CommandlineArguments.Getval("TauMax",TauMax);
    
    std::cerr << "#CALCULATING CHARM/ANTICHARM PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION <<  " Charm mass " << MQ << " Alpha-s " << alphas << std::endl;
    std::cerr << "#KINEMATIC CUTS ARE qT=" << qTMin << " - " << qTMax << "GeV AND tau=" << TauMin << "-" << TauMax << " fm" << std::endl;
    
    
    // MONTE CARLO SAMPLING //
    int NSamples=5120000;
    CommandlineArguments.Getval("NSamples",NSamples);
    
    // SEED RANDOM NUMBER GENERATOR //
    srand48(time(0));
    
    // SETUP INTERPOLATORS FOR HYDRO ATTRACTORS //
    HydroAttractor::Setup();
    
    // CALCULATE CHARM PRODUCTION -- dN/dQdy //
    int NQ=300; double yQ=0; double dNchdEta = 2240;
        
    CommandlineArguments.Getval("NQ",NQ);
    CommandlineArguments.Getval("yQ",yQ);
        
    std::cerr << "#CALCULATING FOR Q=" << QMin << " - " << QMax << "GeV IN " << NQ << " BINS AT yQ=" <<  yQ  << " WITH " << NSamples << " SAMPLES PER BIN" << std::endl;
    
    // WRITE HEADER //
    std::cout << "#1--Q [GeV] #2--dN_{tot}/dQdy [GeV-1] #3--dN_{PreEq}/dQdy [GeV-1] #4--dN_{Hydro}/dQdy [GeV-1]" << std::endl;
        
    for(int iQ=0;iQ<NQ;iQ++){
    	double Q=QMin+iQ*(QMax-QMin)/double(NQ-1);
    	double dNlldQdY=0.0;
        double dNlldQdYPreEq=0.0;
        double dNlldQdYHydro=0.0;

        for(int i=0;i<NSamples;i++){
        	double dN,dNPreEq,dNHydro;
                CharmRates_qq::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,MQ,alphas,dN,dNPreEq,dNHydro);
                dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro;
                }
                
        dNlldQdY/=double(NSamples);
        dNlldQdYPreEq/=double(NSamples);
        dNlldQdYHydro/=double(NSamples);      

        std::cout << Q  << " " << dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro ;
    	cout << endl;
        }
         return 0;
}
   
