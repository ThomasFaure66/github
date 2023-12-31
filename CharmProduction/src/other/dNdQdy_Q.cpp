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
#include "CharmRates_qq.cpp"
#include "CharmRates_gg.cpp"


// COMMANDLINE OPTIONS //
#include "IO/cfile.c"

int main(int argc, char* argv[]) {
    
    // SET COMMANDLINE ARGUMENTS //
    Konfig CommandlineArguments(argc,argv);
    
    // COLLISION PARAMETERS //
    double EtaOverS=0.16 ; double Area=110;double MQ=1.5; double alphas=0.3;
    
    CommandlineArguments.Getval("alphas",alphas);
    CommandlineArguments.Getval("M",MQ);
    CommandlineArguments.Getval("etas",EtaOverS);
    CommandlineArguments.Getval("area",Area);
    CommandlineArguments.Getval("Q",QUARK_SUPPRESSION);
    
    std::cerr << "#CALCULATING CHARM/ANTICHAM PRODUCTION FOR  Area=" << Area << " fm^2 AND Eta/s=" << EtaOverS << " QUARK SUPPRESION " << QUARK_SUPPRESSION <<  " Quark mass " << MQ << std::endl;
    
    
    // DILEPTON PARAMTERS //
    double QMin=3.001; double QMax=8;

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
    
    // CALCULATE DILEPTON PRODUCTION -- dN/dQdyQ //
        int NQ=300; double yQ=0; double dNchdEta = 2240;
        
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
            double testo = 0.0;

            for(int i=0;i<NSamples;i++){
                
                double dN,dNPreEq,dNHydro, test;
                CharmRates_gg::SampledNdQdy(Q*Q,qTMin,qTMax,TauMin,TauMax,yQ,dNchdEta,Area,EtaOverS,MQ,alphas,dN,dNPreEq,dNHydro, test);
                dNlldQdY+=dN; dNlldQdYPreEq+=dNPreEq; dNlldQdYHydro+=dNHydro; testo+=test;
                

            }
            dNlldQdY/=double(NSamples);
            dNlldQdYPreEq/=double(NSamples);
            dNlldQdYHydro/=double(NSamples);
            testo/=double(NSamples);
            

    
    
            std::cout << Q  << " " << dNlldQdY << " " << dNlldQdYPreEq << " " << dNlldQdYHydro ;

    		cout << endl;
        }
         return 0;
}
   
