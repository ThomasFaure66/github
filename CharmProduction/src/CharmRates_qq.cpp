#include <stdlib.h>

namespace CharmRates_qq{
    
 
    // NON-EQUILIBIRIUM CURRENT-CURRENT CORRELATION FUNCTION -- yQ IS PSEUDORPAIDITY OF CHARM/ANTICHARM PAIR //
    void SampleTracePi(double Q, double q0,double qT,double PhiQ, double yQ,double EtaX,double Xi,double Teff,double qSupp, double MQ, double alphas, double &sampletrace, double &sonde1, double &sonde2){
        
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
        
        double CosThetaPQ=(qAbs*qAbs+2.0*pAbs*q0-q0*q0)/(2.0*pAbs*qAbs);
//        if(CosThetaPQ > 1.0){
//       	if(CosThetaPQ >1.1){
//        		cout << "Fail" << endl;
//        		exit(EXIT_FAILURE);}
//        	CosThetaPQ = 1.0;}
        double SinThetaPQ=sqrt(1.0-CosThetaPQ*CosThetaPQ);
        
        // GET RELEVANT VECTORS //
        double qVec[3]; double pVec[3];  double qMpVec[3];
        
        qVec[0]=qAbs*eq[0];
        qVec[1]=qAbs*eq[1];
        qVec[2]=qAbs*eq[2];
        
        pVec[0]=pAbs*(SinThetaPQ*cos(PhiP)*et[0]+SinThetaPQ*sin(PhiP)*el[0]+CosThetaPQ*eq[0]);
        pVec[1]=pAbs*(SinThetaPQ*cos(PhiP)*et[1]+SinThetaPQ*sin(PhiP)*el[1]+CosThetaPQ*eq[1]);
        pVec[2]=pAbs*(SinThetaPQ*cos(PhiP)*et[2]+SinThetaPQ*sin(PhiP)*el[2]+CosThetaPQ*eq[2]);
        
        qMpVec[0]=qVec[0]-pVec[0];
        qMpVec[1]=qVec[1]-pVec[1];
        qMpVec[2]=qVec[2]-pVec[2];
        
        double pT=sqrt(pVec[0]*pVec[0]+pVec[1]*pVec[1]);
        double yP=atanh(pVec[2]/pAbs);
        
        double qMpT=sqrt(qMpVec[0]*qMpVec[0]+qMpVec[1]*qMpVec[1]);
        double qMpAbs=sqrt(qMpVec[0]*qMpVec[0]+qMpVec[1]*qMpVec[1]+qMpVec[2]*qMpVec[2]);
        double yqMP=atanh(qMpVec[2]/qMpAbs);
        
        double m = MQ;
        //double E = pAbs+sqrt(pAbs*pAbs+qAbs*qAbs-2*pAbs*qAbs*CosThetaPQ);
        double v = sqrt(1.0-(4.0*m*m)/(Q*Q));
//	double alphas = 1.0/137.0;
//        double sigma=((M_PI*alphas*alphas)/(2.0*Q*Q))*(((11.0/4.0)-(3.0/2.0)*v*v+(1.0/12.0)*v*v*v*v)*atanh(v)-(v/24.0)*(59.0-31.0*v*v));
       double sigma= ((4.0*M_PI*alphas*alphas)/(9.0*Q*Q))*v*(1.0-(v*v)/3.0);
//	double sigma =((2.0*4.0*M_PI*alphas*alphas)/(3.0*9.0*Q*Q));
        // GET PHASE SPACE DISTRIBUTION //
        //double fg=PhaseSpaceDistribution::fG(pT,yP,EtaX,Xi,Teff,qSupp);
        //double fgMP=PhaseSpaceDistribution::fG(qMpT,yqMP,EtaX,Xi,Teff,qSupp);
        
        double fp=PhaseSpaceDistribution::fQ(pT,yP,EtaX,Xi,Teff,qSupp);
        double fqMp=PhaseSpaceDistribution::fQ(qMpT,yqMP,EtaX,Xi,Teff,qSupp);
        
        // GET POLARIZATION TENSOR //
        sampletrace=(sigma/qAbs)*Jacobian*fp*fqMp;
        sonde1 = fp;
        sonde2 = qAbs;
    }
    
    
    // SAMPLE DILPETON PRODUCTION -- QSqr INVARIANT MASS SQUARE, qT TRANSVERSE MOMENTUM , EtaQ RAPIDITY OF CHARM/ANTICHARM PAIR //
    void SampledNdQdy(double QSqr,double qTMin,double qTMax,double TauMin,double TauMax,double EtaQ,double dNchdEta,double Area,double etas,double MQ,double alphas, double &dN,double &dNPreEq,double &dNHydro, double &test){
    
        
        // SAMPLE INTEGRATION POINT //
        double Jacobian=1.0;
        
        double EtaMin=-8+EtaQ;
        double EtaMax=8+EtaQ;
        double EtaX=EtaMin+(EtaMax-EtaMin)*rng();
        double qT=qTMin+(qTMax-qTMin)*rng();
        double PhiQ=2.0*M_PI*rng();
        
        double Q=sqrt(QSqr);
        
        // ENERGY AND MOMENTUM OF CHARM/ANTICHARM PAIR //
        double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);
        
        // PSEUDO-RAPIDITY OF CHARM/ANTICHARM PAIR //
        double yQ=atanh(qZ/qAbs);
        
        // JACOBIAN  -- d^4Q=QdQ dy d^2qT //
        Jacobian*=2.0*M_PI*(qTMax-qTMin)*(EtaMax-EtaMin)*qT*Q;
        
        // EVOLUTION TIME //
        double Tau=TauMin+(TauMax-TauMin)*rng();
        
        Jacobian*=Tau*(TauMax-TauMin)*Area/(M_HBARC*M_HBARC*M_HBARC*M_HBARC);
       
        // GET EVOLUTION OF MACROSCOPIC FIELDS //
        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,etas,Tau,T,wTilde,e,pL,eQOvereG);
        
        // GET PARAMETERS OF PHASE-SPACE DISTRIBUTION //
        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // SAMPLE CHARM/ANTICHARM PRODUCTION //
        
        double sampletrace, sonde1, sonde2;
        SampleTracePi(Q,q0,qT,PhiQ,yQ,EtaX,Xi,Teff,qSupp,MQ,alphas, sampletrace, sonde1, sonde2);
        double PreFactor=QSqr/(64.0*2.0*M_PI*M_PI*M_PI*M_PI*M_PI*M_PI);
        double dNlld4xd4Q=4.0*9.0*3*PreFactor*sampletrace;
        // GET PRODUCTION YIELD //
        dN=Jacobian*dNlld4xd4Q;
        test=sonde1;
        if(isnan(dN)){
        	dN=0;}
        // SEPARATE INTO PRE-EQ AND HYDRO //
        if(wTilde<1.0){
            dNPreEq=dN; dNHydro=0.0;
        }
        else{
            dNPreEq=0.0; dNHydro=dN;
        }
        
        
    }
  
    // SAMPLE DILPETON PRODUCTION -- Q INVARIANT MASS, qT TRANSVERSE MOMENTUM , EtaQ RAPIDITY OF DILEPTON PAIR //
    void SampledNdy(double QMin,double QMax,double qTMin,double qTMax,double TauMin,double TauMax,double EtaQ,double dNchdEta,double Area,double etas,double MQ,double alphas,double &dN,double &dNPreEq,double &dNHydro, double &test,  double &test2, double &test3){
        
        // SAMPLE INTEGRATION POINT //
        double Jacobian=1.0;
        
        double EtaMin=-8+EtaQ;
        double EtaMax=8+EtaQ;
        double EtaX=EtaMin+(EtaMax-EtaMin)*rng();
        double qT=qTMin+(qTMax-qTMin)*rng();
        double PhiQ=2.0*M_PI*rng();
        
        double Q=QMin+(QMax-QMin)*rng();
        double QSqr=Q*Q;
        
        // JACOBIAN  -- d^4Q=QdQ dy d^2qT //
        Jacobian*=2.0*M_PI*(qTMax-qTMin)*(EtaMax-EtaMin)*(QMax-QMin)*qT*Q;
        
        // ENERGY AND MOMENTUM OF CHARM/ANTICHARM PAIR //
        double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);
        
        // PSEUDO-RAPIDITY OF CHARM/ANTICHARM PAIR //
        double yQ=atanh(qZ/qAbs);
        
        // EVOLUTION TIME //
        double Tau=TauMin+(TauMax-TauMin)*rng();
        
        Jacobian*=Tau*(TauMax-TauMin)*Area/(M_HBARC*M_HBARC*M_HBARC*M_HBARC);
        
        // GET EVOLUTION OF MACROSCOPIC FIELDS //
        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,etas,Tau,T,wTilde,e,pL,eQOvereG);
        
        // GET PARAMETERS OF PHASE-SPACE DISTRIBUTION //
        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // SAMPLE CHARM/ANTICHARM PRODUCTION //
        
        double sampletrace, sonde1, sonde2;
        SampleTracePi(Q,q0,qT,PhiQ,yQ,EtaX,Xi,Teff,qSupp,MQ,alphas, sampletrace, sonde1, sonde2);
        
        double PreFactor=QSqr/(64.0*2.0*M_PI*M_PI*M_PI*M_PI*M_PI*M_PI);
        double dNlld4xd4Q=4.0*9.0*3*PreFactor*sampletrace;

        // GET PRODUCTION YIELD //
        dN=Jacobian*dNlld4xd4Q;
        test2 = sonde1;
        test3=0;
         if(isnan(dN)){
         	test3=1;
        	dN=0;}
        // SEPARATE INTO PRE-EQ AND HYDRO //
        if(wTilde<1.0){
            dNPreEq=dN; dNHydro=0.0; test=qSupp;
        }
        else{
            dNPreEq=0.0; dNHydro=dN;
        }
        
    }
      
   // SAMPLE DILPETON PRODUCTION -- QSqr INVARIANT MASS SQUARE, qT TRANSVERSE MOMENTUM , EtaQ RAPIDITY OF DILEPTON PAIR //
    void SampledNdqTdy(double QMin,double QMax,double qT,double TauMin,double TauMax,double EtaQ,double dNchdEta,double Area,double etas,double MQ,double alphas,double &dN,double &dNPreEq,double &dNHydro){
        
        // SAMPLE INTEGRATION POINT //
        double Jacobian=1.0;
        
        double EtaMin=-8+EtaQ;
        double EtaMax=8+EtaQ;
        double EtaX=EtaMin+(EtaMax-EtaMin)*rng();
        double PhiQ=2.0*M_PI*rng();
        
        double Q=QMin+(QMax-QMin)*rng();
        double QSqr=Q*Q;
        
        
        // ENERGY AND MOMENTUM OF CHARM/ANTICHARM PAIR //
        double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);
        
        // PSEUDO-RAPIDITY OF CHARM/ANTICHARM PAIR //
        double yQ=atanh(qZ/qAbs);
        
        // JACOBIAN  -- d^4Q=QdQ dy d^2qT //
        Jacobian*=2.0*M_PI*(EtaMax-EtaMin)*(QMax-QMin)*qT*Q;
        
        // EVOLUTION TIME //
        double Tau=TauMin+(TauMax-TauMin)*rng();
        
        Jacobian*=Tau*(TauMax-TauMin)*Area/(M_HBARC*M_HBARC*M_HBARC*M_HBARC);
        
        // GET EVOLUTION OF MACROSCOPIC FIELDS //
        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,etas,Tau,T,wTilde,e,pL,eQOvereG);
        
        // GET PARAMETERS OF PHASE-SPACE DISTRIBUTION //
        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // SAMPLE CHARM/ANTICHARM PRODUCTION //
        double sampletrace, sonde1, sonde2;
        SampleTracePi(Q,q0,qT,PhiQ,yQ,EtaX,Xi,Teff,qSupp,MQ, alphas,sampletrace, sonde1, sonde2);
        
        double PreFactor=QSqr/(64.0*2.0*M_PI*M_PI*M_PI*M_PI*M_PI*M_PI);
        double dNlld4xd4Q=4.0*9.0*3*PreFactor*sampletrace;

        // GET PRODUCTION YIELD //
        dN=Jacobian*dNlld4xd4Q;
         if(isnan(dN)){
        	dN=0;}        
        // SEPARATE INTO PRE-EQ AND HYDRO //
        if(wTilde<1.0){
            dNPreEq=dN; dNHydro=0.0;
        }
        else{
            dNPreEq=0.0; dNHydro=dN;
        }
        
        
    }
    
    
    void SampledNdqTdQdy(double Q,double qT,double TauMin,double TauMax,double EtaQ,double dNchdEta,double Area,double MQ,double alphas, double &dN,double &dNPreEq,double &dNHydro,double eta_over_s){


        // SET JACOBIAN FOR MONTE-CARLO INTEGRATION //
        double Jacobian=1.0;

        // SAMPLE EVOLUTION TIME //
        double Tau=TauMin+(TauMax-TauMin)*rng();
        Jacobian*=Tau*(TauMax-TauMin)*Area/(M_HBARC*M_HBARC*M_HBARC*M_HBARC);

        double T,wTilde,e,pL,eQOvereG;
        HydroAttractor::GetValues(dNchdEta,Area,eta_over_s,Tau,T,wTilde,e,pL,eQOvereG);

        // CALCULATE CHARM/ANTICHARM PRODUCTION dN/dydQd2qT FOR ALL BINS //

        // SAMPLE INTEGRATION POINT //
        double EtaMin=-8+EtaQ;
        double EtaMax=8+EtaQ;
        double EtaX=EtaMin+(EtaMax-EtaMin)*rng();
        double PhiQ=2.0*M_PI*rng();

        double QSqr=Q*Q;

        // ENERGY AND MOMENTUM OF CHARM/ANTICHARM PAIR //
        double qZ=std::sqrt(QSqr+qT*qT)*sinh(EtaQ);
        double qAbs=std::sqrt(qT*qT+(QSqr+qT*qT)*sinh(EtaQ)*sinh(EtaQ));
        double q0=std::sqrt(QSqr+qAbs*qAbs);

        // PSEUDO-RAPIDITY OF CHARM/ANTICHARM PAIR //
        double yQ=atanh(qZ/qAbs);


        // JACOBIAN  -- d^4Q=QdQ dy d^2qT //
        Jacobian*=(EtaMax-EtaMin)*Q*qT*2*M_PI;

        double Xi,Teff,qSupp;
        PhaseSpaceDistribution::GetPhaseSpaceDistributionParameters(e,pL,eQOvereG,Xi,Teff,qSupp);
        
        // CALCULATE CHARM/ANTICHARM PRODUCTION //
        double sampletrace, sonde1, sonde2;
        SampleTracePi(Q,q0,qT,PhiQ,yQ,EtaX,Xi,Teff,qSupp,MQ,alphas,sampletrace, sonde1, sonde2);
        
        double PreFactor=QSqr/(64.0*2.0*M_PI*M_PI*M_PI*M_PI*M_PI*M_PI);
        double dNlld4xd4Q=4.0*9.0*3*PreFactor*sampletrace;

        // GET PRODUCTION YIELD //
         dN=Jacobian*dNlld4xd4Q;
         if(isnan(dN)){
        	dN=0;}
        
        // DISTINGUSIH BETWEEN PRE-EQUILIBRIUM AND HYDRO //
        if(wTilde<1.0){
                dNPreEq=dN;
                dNHydro=0;
        }else{
                dNHydro=dN;
                dNPreEq=0;
        }

    }
    }
