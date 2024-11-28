//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 27 07:44:42 2024 by ROOT version 6.26/06
// from TTree temp_tree_/temp_tree_
// found on file: AnaTutorial_zvtx_10K_zvtx20.root
//////////////////////////////////////////////////////////

#ifndef AlgorithmTwoFile_h
#define AlgorithmTwoFile_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <stdio.h>
#include <iostream>

// Header file for the classes stored in the TTree if any.

#include "vector"

class AlgorithmTwoFile {
public :
    TTree          *fChain1;   //!pointer to the analyzed TTree or TChain
    TTree          *fChain2;
    Int_t           fCurrent1; //!current Tree number in a TChain
    Int_t           fCurrent2;

    // Fixed size dimensions of array or collections stored in the TTree if any.

    // List of valuable of file1
    std::vector<double>  *x1;

    // List of valuable of file2
    std::vector<double>  *x2;


    // List of branches of file1
    TBranch        *b_x1;   //!
    
    // List of branches of file2
    TBranch        *b_x2;   //!


   AlgorithmTwoFile(TTree *tree1=0, TTree *tree2=0,  std::string fInputName1="",  std::string fInputName2="",  std::string fOutputName="");
   virtual ~AlgorithmTwoFile();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init1(TTree *tree);
   virtual void     Init2(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   std::string fDir = "./";

   std::string fInputName1 = "iFile1.root";
   std::string fInputName2 = "iFile2.root";
   std::string fOutpuName = "result.root";

   TFile *oFile;
};

#endif

#ifndef AlgorithmTwoFile_cxx
#define AlgorithmTwoFile_cxx
AlgorithmTwoFile::AlgorithmTwoFile(TTree *tree1, TTree *tree2,  std::string iFileName1,  std::string iFileName2,  std::string fOutputName) : fChain1(0),fChain2(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree1 == 0) {
      TFile *f1 = (TFile*)gROOT->GetListOfFiles()->FindObject(iFileName1.c_str());
      if (!f1 || !f1->IsOpen()) {
         f1 = new TFile(iFileName1.c_str());
      }
      f1->GetObject("tree1",tree1);

      TFile *f2 = (TFile*)gROOT->GetListOfFiles()->FindObject(iFileName2.c_str());
      if (!f2 || !f2->IsOpen()) {
         f2 = new TFile(iFileName2.c_str());
      }
      f2->GetObject("tree2",tree2);
   }
   Init1(tree1);
   Init2(tree2);
}

AlgorithmTwoFile::~AlgorithmTwoFile()
{
   if (!fChain1) return;
   delete fChain1->GetCurrentFile();
   delete fChain2->GetCurrentFile();
}

Int_t AlgorithmTwoFile::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain1) return 0;
   return fChain1->GetEntry(entry);
   return fChain2->GetEntry(entry);
}
Long64_t AlgorithmTwoFile::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain1) return -5;
   Long64_t centry1 = fChain1->LoadTree(entry);
   Long64_t centry2 = fChain2->LoadTree(entry);
   if (centry1 < 0) return centry1;
   if (fChain1->GetTreeNumber() != fCurrent1) {
      fCurrent1 = fChain1->GetTreeNumber();
      fCurrent2 = fChain2->GetTreeNumber();
      Notify();
   }
   return centry1;
}

// file1    ////////////////////
void AlgorithmTwoFile::Init1(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   x1 = 0;

    // Set object pointer
   x2 = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain1 = tree;
   fCurrent1 = -1;
   fChain1->SetMakeClass(1);

   fChain1->SetBranchAddress("x1", &x1, &b_x1);

   Notify();

   std::cout << fChain1->GetEntriesFast() << std::endl; 
}


// file2    ////////////////////
void AlgorithmTwoFile::Init2(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain2 = tree;
   fCurrent2 = -1;
   fChain2->SetMakeClass(1);

   fChain2->SetBranchAddress("x2", &x2, &b_x2);
   
   Notify();
}


Bool_t AlgorithmTwoFile::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AlgorithmTwoFile::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain1) return;
   fChain1->Show(entry);
}
Int_t AlgorithmTwoFile::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

#endif // #ifdef AlgorithmTwoFile_cxx
