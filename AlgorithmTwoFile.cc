//#define AlgorithmTwoFile_cxx
#include "AlgorithmTwoFile.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>

void AlgorithmTwoFile::Loop()
{
    if (fChain1 == 0 || fChain2 == 0) return;

    Long64_t nentries = fChain1->GetEntriesFast();
    if (nentries1 == 0) {
        std::cout << "No entries found in the TTree!" << std::endl;
        return;
    }
    Long64_t nbytes1 = 0, nb1 = 0, nbytes2 = 0, nb2 = 0;

    for (Long64_t jentry=0; jentry<1000; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;

        nb1 = fChain1->GetEntry(jentry);   nbytes1 += nb1;
        nb2 = fChain2->GetEntry(jentry);   nbytes2 += nb2;
        // if (Cut(ientry) < 0) continue;

        if(jentry%100 == 0)std::cout << " == event" << jentry << " =====" << std::endl;
        
        ResetValuesForEachEvent();
   }

   WrightHists();


}
