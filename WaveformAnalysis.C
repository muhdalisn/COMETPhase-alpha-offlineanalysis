// Usage:
// root -l -b -q WaveformAnalysis.C
//
//
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"

#if defined(__CLING__)
  R__ADD_INCLUDE_PATH(../analyser/include/)
  R__ADD_LIBRARY_PATH(../analyser/obj/)
  R__LOAD_LIBRARY(../analyser/obj/libcalphaanalyzer.so)
#endif
#if !defined(__CLING__) || defined(__ROOTCLING__)
  #include "user/TWaveform.hh"
  #include "generated/CAlphaPicoData.h"
#endif

void WaveformAnalysis(){
  //
  //
  //
  TFile* inFilePicoTree = new TFile("/group/had/muon/2023.2.Phase-Alpha/anadata/picotree01513.root");
  TTree* inPicoTree = (TTree*) inFilePicoTree->Get("picotree");

  CAlphaPicoData* picoData = nullptr; 
  inPicoTree->SetBranchAddress("pico", &picoData);

  //
  // Get first entry of the TTree
  //
  inPicoTree->GetEntry(0);
  //
  // Get the waveforms for T0R and TOL
  //
  TWaveform* wf_T0R = picoData->GetWfAt(0);
  TWaveform* wf_T0L = picoData->GetWfAt(1);
  //
  // Get the waveforms in the format of a TH1.
  //
  TH1* hwf_T0R = wf_T0R->GetHist();
  TH1* hwf_T0L = wf_T0L->GetHist();
  
  //
  // Save the histogram
  //
  TFile* outFileHisto = new TFile("histo.root","RECREATE");
  outFileHisto->WriteTObject(hwf_T0R);
  outFileHisto->WriteTObject(hwf_T0L);
  outFileHisto->Close();
   
  //
  // To loop over events
  //
  // int nEntry = inPicoTree->GetEntries();
  // for(int iEntry=0; iEntry<nEntry; ++iEntry){ 
  //   if(iEntry == 1) break;
  // }
}

int main(){
  WaveformAnalysis();
}