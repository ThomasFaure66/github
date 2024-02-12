#include <stdlib.h>

namespace getphasedistribution{
    
    // NON-EQUILIBIRIUM CURRENT-CURRENT CORRELATION FUNCTION -- yQ IS PSEUDORPAIDITY OF CHARM/ANTICHARM PAIR //
    void SampleTracePi(double Q, double q0,double qT,double PhiQ, double yQ,double EtaX,double Xi,double Teff,double qSupp,double MQ, double alphas, double &sampletrace, double &sonde1, double &sonde2){
        
        // SET JACOBIAN TO UNITY //
        double Jacobian=1.0;
        
        // SET KINETMATIC VARIABLES DERIVED FROM q //
        double qZ=qT*sinh(yQ);
        double qAbs=qT*cosh(yQ);
        double CosThetaQ=qZ/qAbs;
        double SinThetaQ=sqrt(1.0-CosThetaQ*CosThetaQ);
        
        // GET COORDINATE SYSTEM FOR p INTEGRATION //
        double eq[3];
        
        eq[0]=cos(PhiQ)/sqrt(1.0+sinh(yQ)*sinh(yQ));
        eq[1]=sin(PhiQ)/sqrt(1.0+sinh(yQ)*sinh(yQ));
        eq[2]=sinh(yQ)/sqrt(1.0+sinh(yQ)*sinh(yQ));
        
        
        double el[3];
        
        el[0]=(0.0-CosThetaQ*eq[0])/SinThetaQ;
        el[1]=(0.0-CosThetaQ*eq[1])/SinThetaQ;
        el[2]=(1.0-CosThetaQ*eq[2])/SinThetaQ;
        
        
        double et[3];
        
        et[0]=(eq[1]*el[2]-eq[2]*el[1]);
        et[1]=(eq[2]*el[0]-eq[0]*el[2]);
        et[2]=(eq[0]*el[1]-eq[1]*el[0]);
        
        // SAMPLE p VECTOR //
        double pMin=(q0-qAbs)/2.0;
        double pMax=(q0+qAbs)/2.0;
        
        double pAbs=pMin+(pMax-pMin)*rng();
        double PhiP=2.0*M_PI*drand48();
        
        Jacobian*=2.0*M_PI*(pMax-pMin);
        
        double CosThetaPQ=(qAbs)/(2.0*pAbs)+(2.0*pAbs*q0)/(2.0*pAbs*qAbs)-(q0*q0)/(2.0*pAbs*qAbs);
//        if(CosThetaPQ > 1.0){
//        	if(CosThetaPQ >1.1){
//        		cout << "Fail" << endl;
//        		exit(EXIT_FAILURE);}
//        	CosThetaPQ = 1.0;}
        double SinThetaPQ=sqrt(1.0-CosThetaPQ*CosThetaPQ);
        
        // GET RELEVANT VECTORS //
       double pVec[3]; 
        
        pVec[0]=pAbs*(SinThetaPQ*cos(PhiP)*et[0]+SinThetaPQ*sin(PhiP)*el[0]+CosThetaPQ*eq[0]);
        pVec[1]=pAbs*(SinThetaPQ*cos(PhiP)*et[1]+SinThetaPQ*sin(PhiP)*el[1]+CosThetaPQ*eq[1]);
        pVec[2]=pAbs*(SinThetaPQ*cos(PhiP)*et[2]+SinThetaPQ*sin(PhiP)*el[2]+CosThetaPQ*eq[2]);
        
        
        double pT=sqrt(pVec[0]*pVec[0]+pVec[1]*pVec[1]);
        double yP=atanh(pVec[2]/pAbs);

        // GET PHASE SPACE DISTRIBUTION //
        double fg=PhaseSpaceDistribution::fG(pT,yP,EtaX,Xi,Teff,qSupp);
        double fq=PhaseSpaceDistribution::fQ(pT,yP,EtaX,Xi,Teff,qSupp);
        
        // GET POLARIZATION TENSOR //
        sampletrace=fg;
        sonde1 = fg;
        sonde2 = fq;
    }
    
    
    void phasedistribution(double Q, double qT, double Tau ,double EtaQ,double dNchdEta,double Area,double etas, double MQ, double alphas, double &fg,double &temperature, double &energy){
        
        // SAMPLE INTEGRATION POINT //

        double PhiQ=2.0*M_PI*0.5;
        double QSqr=Q*Q;
     
        // ENERGY AND MOMENTUM OF CHARM/ANTICHARM PAIR //
        double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);
        
        // PSEUDO-RAPIDITY OF CHARM/ANTICHARM PAIR //
        double yQ=atanh(qZ/qAbs);
        
        // GET EVOLUTION OF MACROSCOPIC FIELDS //

        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,etas,Tau,T,wTilde,e,pL,eQOvereG);
        
        // GET PARAMETERS OF PHASE-SPACE DISTRIBUTION //
        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // SAMPLE CHARM/ANTICHARM PRODUCTION //
        
        double sampletrace, sonde1, sonde2;
        SampleTracePi(Q,q0,qT,PhiQ,yQ,EtaQ,Xi,Teff,qSupp,MQ,alphas, sampletrace, sonde1, sonde2);
        
        fg=sonde1;
        temperature=T;
        energy=e;
        
    }
    
}
