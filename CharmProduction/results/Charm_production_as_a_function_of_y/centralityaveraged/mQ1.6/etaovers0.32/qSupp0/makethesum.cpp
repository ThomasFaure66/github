#include <iostream>
#include <sstream>
#include <string>
#include<math.h>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cmath>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>


#define M_HBARC 0.197
using namespace std;

int main(){

      char filexsec1[6000];
      sprintf(filexsec1,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality0_5.txt");
      ifstream dataFile1(filexsec1);
      int counter1 = 0;
      string line1;
      double all1[600];
      double y[40];
      double zerocinq[40];

      int j1 = 0;
     for(int i = 0; i<600; i++){
 	    all1[i] = 0;
      }
      
      while(getline(dataFile1, line1)){
  	  istringstream iss1(line1);
  	  string token1;
	  while(getline(iss1, token1, ' ')){
		  double num_float1 = stod(token1);
 		  all1[counter1] = num_float1;
  		  counter1++;
  	  }
     }
      while(j1<40){
 	      y[j1] = all1[j1*5];
 	      zerocinq[j1]=all1[j1*5+3];
 	      j1++;
	      }
	      
      char filexsec2[6000];
      sprintf(filexsec2,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality5_10.txt");
      ifstream dataFile2(filexsec2);
      int counter2 = 0;
      string line2;
      double all2[600];
      double cinqdix[40];

      int j2 = 0;
     for(int i = 0; i<600; i++){
 	    all2[i] = 0;
      }
      
      while(getline(dataFile2, line2)){
  	  istringstream iss2(line2);
  	  string token2;
	  while(getline(iss2, token2, ' ')){
		  double num_float2 = stod(token2);
 		  all2[counter2] = num_float2;
  		  counter2++;
  	  }
     }
      while(j2<40){
 	      cinqdix[j2]=all2[j2*5+3];
 	      j2++;
	      }
	      

      char filexsec3[6000];
      sprintf(filexsec3,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality10_20.txt");
      ifstream dataFile3(filexsec3);
      int counter3 = 0;
      string line3;
      double all3[600];
      double dixvingt[40];

      int j3 = 0;
     for(int i = 0; i<600; i++){
 	    all3[i] = 0;
      }
      
      while(getline(dataFile3, line3)){
  	  istringstream iss3(line3);
  	  string token3;
	  while(getline(iss3, token3, ' ')){
		  double num_float3 = stod(token3);
 		  all3[counter3] = num_float3;
  		  counter3++;
  	  }
     }
      while(j3<40){
 	      dixvingt[j3]=all3[j3*5+3];
 	      j3++;
	      }

      char filexsec4[6000];
      sprintf(filexsec4,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality20_30.txt");
      ifstream dataFile4(filexsec4);
      int counter4 = 0;
      string line4;
      double all4[600];
      double vingttrente[40];

      int j4 = 0;
     for(int i = 0; i<600; i++){
 	    all4[i] = 0;
      }
      
      while(getline(dataFile4, line4)){
  	  istringstream iss4(line4);
  	  string token4;
	  while(getline(iss4, token4, ' ')){
		  double num_float4 = stod(token4);
 		  all4[counter4] = num_float4;
  		  counter4++;
  	  }
     }
      while(j4<40){
 	      vingttrente[j4]=all4[j4*5+3];
 	      j4++;
	      }
	      
      char filexsec5[6000];
      sprintf(filexsec5,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality30_40.txt");
      ifstream dataFile5(filexsec5);
      int counter5 = 0;
      string line5;
      double all5[600];
      double trentequarante[40];

      int j5 = 0;
     for(int i = 0; i<600; i++){
 	    all5[i] = 0;
      }
      
      while(getline(dataFile5, line5)){
  	  istringstream iss5(line5);
  	  string token5;
	  while(getline(iss5, token5, ' ')){
		  double num_float5 = stod(token5);
 		  all5[counter5] = num_float5;
  		  counter5++;
  	  }
     }
      while(j5<40){
 	      trentequarante[j5]=all5[j5*5+3];
 	      j5++;
	      }

      char filexsec6[6000];
      sprintf(filexsec6,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality40_50.txt");
      ifstream dataFile6(filexsec6);
      int counter6 = 0;
      string line6;
      double all6[600];
      double qc[40];

      int j6 = 0;
     for(int i = 0; i<600; i++){
 	    all6[i] = 0;
      }
      
      while(getline(dataFile6, line6)){
  	  istringstream iss6(line6);
  	  string token6;
	  while(getline(iss6, token6, ' ')){
		  double num_float6 = stod(token6);
 		  all6[counter6] = num_float6;
  		  counter6++;
  	  }
     }
      while(j6<40){
 	      qc[j6]=all6[j6*5+3];
 	      j6++;
	      }

      char filexsec7[6000];
      sprintf(filexsec7,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality50_60.txt");
      ifstream dataFile7(filexsec7);
      int counter7 = 0;
      string line7;
      double all7[600];
      double cs[40];

      int j7 = 0;
     for(int i = 0; i<600; i++){
 	    all7[i] = 0;
      }
      
      while(getline(dataFile7, line7)){
  	  istringstream iss7(line7);
  	  string token7;
	  while(getline(iss7, token7, ' ')){
		  double num_float7 = stod(token7);
 		  all7[counter7] = num_float7;
  		  counter7++;
  	  }
     }
      while(j7<40){
 	      cs[j7]=all7[j7*5+3];
 	      j7++;
	      }

      char filexsec8[6000];
      sprintf(filexsec8,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality60_70.txt");
      ifstream dataFile8(filexsec8);
      int counter8 = 0;
      string line8;
      double all8[600];
      double ss[40];

      int j8 = 0;
     for(int i = 0; i<600; i++){
 	    all8[i] = 0;
      }
      
      while(getline(dataFile8, line8)){
  	  istringstream iss8(line8);
  	  string token8;
	  while(getline(iss8, token8, ' ')){
		  double num_float8 = stod(token8);
 		  all8[counter8] = num_float8;
  		  counter8++;
  	  }
     }
      while(j8<40){
 	      ss[j8]=all8[j8*5+3];
 	      j8++;
	      }

      char filexsec9[6000];
      sprintf(filexsec9,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality70_80.txt");
      ifstream dataFile9(filexsec9);
      int counter9 = 0;
      string line9;
      double all9[600];
      double sq[40];

      int j9 = 0;
     for(int i = 0; i<600; i++){
 	    all9[i] = 0;
      }
      
      while(getline(dataFile9, line9)){
  	  istringstream iss9(line9);
  	  string token9;
	  while(getline(iss9, token9, ' ')){
		  double num_float9 = stod(token9);
 		  all9[counter9] = num_float9;
  		  counter9++;
  	  }
     }
      while(j9<40){
 	      sq[j9]=all9[j9*5+3];
 	      j9++;
	      }

      char filexsec[6000];
      sprintf(filexsec,"/local/home/tf275865/Bureau/Stage_code/CharmProduction/centrality/mQ1.6/etaovers0.32/qSupp0/dCharmdy_gg_mQ1.6_qSupp0_NSamples10million_QMin3.2_QMax12_etaovers0.32_alphas0.2395_centrality80_90txt");
      ifstream dataFile(filexsec);
      int counter = 0;
      string line;
      double all10[600];
      double gg[40];

      int j = 0;
     for(int i = 0; i<600; i++){
 	    all10[i] = 0;
      }
      
      while(getline(dataFile, line)){
  	  istringstream iss(line);
  	  string token;
	  while(getline(iss, token, ' ')){
		  double num_float = stod(token);
 		  all10[counter] = num_float;
  		  counter++;
  	  }
     }
      while(j<40){
 	      gg[j]=all10[j*5+3];
 	      j++;
	      }

for (int k = 0; k<40; k++){
  	    cout << y[k] << " " << (1.0/18.0)*zerocinq[k]+(1.0/18.0)*cinqdix[k]+(1.0/9.0)*dixvingt[k]+(1.0/9.0)*vingttrente[k]+(1.0/9.0)*trentequarante[k]+(1.0/9.0)*qc[k]+(1.0/9.0)*cs[k]+(1.0/9.0)*ss[k]+(1.0/9.0)*sq[k]+(1.0/9.0)*gg[k] << endl;
  	         } 
}

