#include "AlgorithmTwoFile.h"
#include "AlgorithmTwoFile.C"

#include <typeinfo>

int main(){
  TChain *tc1 = new TChain("tree1");
  TChain *tc2 = new TChain("tree2");

  std::string fDir = "./";
  
  std::string fInputName1 = fDir + "iFile1.root";
  std::string fInputName2 = fDir + "iFile2.root";

  tc1->Add("./iFile1.root"); 
  tc2->Add("./iFile2.root"); 

  std::string fOutputName = fDir+"result.root";

  TTree *tree1 = (TTree*)tc1;
  TTree *tree2 = (TTree*)tc2;

  AlgorithmTwoFile *h = new AlgorithmTwoFile(tree1, tree2, fInputName1, fInputName2, fOutputName);

  //h->Show(1);
  h->Loop();
  
}
