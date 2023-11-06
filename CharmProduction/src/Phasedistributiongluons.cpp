#include <stdlib.h>

namespace Phasedistributiongluons{

    // SAMPLE DILPETON PRODUCTION -- Q INVARIANT MASS, qT TRANSVERSE MOMENTUM , EtaQ RAPIDITY OF DILEPTON PAIR //
    void PDgg(double Q, double qT,double Tau,double EtaQ,double dNchdEta,double Area,double etas,double &fg){
        
        // GET EVOLUTION OF MACROSCOPIC FIELDS //
        
 	double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);
        
        double yQ=atanh(qZ/qAbs);
     
     
        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,etas,Tau,T,wTilde,e,pL,eQOvereG);
        
        // GET PARAMETERS OF PHASE-SPACE DISTRIBUTION //
        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // SAMPLE CHARM/ANTICHARM PRODUCTION //
        
        fg=PhaseSpaceDistribution::fG(qT,EtaQ,0,Xi,Teff,qSupp);  
      
   }
   }
