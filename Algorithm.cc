// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 
// 2024/11/28 Template a macro to compile written by Kumaoka
// Please replace the name Algorithm to your analysis name, (anyname ok).
// KumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKumaKuma 

// #define Algorithm_cxx
#include "Algorithm.h"

#include <TStyle.h>
#include <TCanvas.h>

void Algorithm::Loop()
{
   if (fChain == 0) return;

   HistInit();

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<1000; jentry++) {
   // for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      if(jentry%100 == 0)std::cout << " == event" << jentry << " =====" << std::endl;
      
      ResetValuesForEachEvent();
   }

   WrightHists();
}


void Algorithm::HistInit(){
   oFile = new TFile(oFileName.c_str(), "recreate");

   m_H1 = new TH1D( "m_H1", "histogram", 100, -50, 50);
}


void Algorithm::ResetValuesForEachEvent(){
   m_vector.clear();
   m_vector.shrink_to_fit();
}

void Algorithm::WrightHists(){
   oFile->cd();

   m_H1->Write();

   oFile->Close();
}


