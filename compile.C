// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 
// 2024/11/28 Template a macro to compile written by Kumaoka
// Please replace the name Algorithm to your analysis name, (anyname ok).
// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 
#include "Algorithm.h"
#include "Algorithm.cc"

#include <typeinfo>

int main(){
  TChain *tc = new TChain("tree");

  std::string fDir = "./";
  
  // please replace the file name to yours
  // std::string fInputName = fDir + "fInput.root";
  // tc->Add("./input.root"); 
  std::string fInputName = fDir + "ana439_Electron_2GeV_00150.root";
  tc->Add("./ana439_Electron_2GeV_00150.root"); 
  std::string fOutputName = fDir+"fOutput.root";

  TTree *tt = (TTree*)tc;

  Algorithm *h = new Algorithm(tt, fInputName, fOutputName);

  //h->Show(1);
  h->Loop();
  
}
