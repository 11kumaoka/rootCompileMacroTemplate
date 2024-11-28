// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 
// 2024/11/28 Template a macro to compile written by Kumaoka
// Please replace the name Algorithm to your analysis name, (anyname ok).
// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 
#include "Algorithm.h"
#include "Algorithm.cc"

#include <typeinfo>

int main(){
  TChain *tc = new TChain("tree");
  
  // please replace directory and "fInput.root" the file name to yours
  std::string fDir = "./";
  std::string fInputName = fDir + "fInput.root";
  tc->Add(fInputName.c_str());
  std::string fOutputName = fDir+"fOutput.root";

  TTree *tt = (TTree*)tc;

  Algorithm *h = new Algorithm(tt, fInputName, fOutputName);

  //h->Show(1);
  h->Loop();
  
}
