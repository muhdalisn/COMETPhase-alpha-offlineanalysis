//
// root -l -b -q FitMuonDecayCurve.C
// Before executing this script, copy histogram rootfiles from Roden's storage space:
// > /gpfs/group/had/muon/derveni/phasealpha/data/output/hists/merged/
//
//
#include "TF1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TPaveStats.h"
#include "TVirtualFitter.h"

#include "Utils.h"
#include "PlotStyle.C"



void DoFit(TString runRange = "1530-1880"){
  SetPlotStyle();
  gStyle->SetOptStat(0);

  // 
  // 
  //
  TFile* inFile = new TFile("hists/merged/"+runRange+".root");
  TH1D*  muonDecayCurve = (TH1D*) inFile->Get("histos/RCMuonDecayAnalysisHistos/MuonDecayCurve/MuonDecayCurve");
  
  // std::cout << muonDecayCurve->GetNbinsX() << std::endl;
  muonDecayCurve->Rebin(20);
  // std::cout << muonDecayCurve->GetNbinsX() << std::endl;
  // 

  float minRange = 0.;
  float maxRange = 9.;

  float minFitRange = 0.;
  float maxFitRange = 8.5;

  int totalEntries = muonDecayCurve->Integral(0,muonDecayCurve->GetNbinsX()+1);
  
  TVirtualFitter::SetMaxIterations( 10000 );
  //
  // Setup total function
  //
  auto fTotal = new TF1("fTotal", "[0]/[1]*exp(-x/[1]) + [2]/[3]*exp(-x/[3]) + \
    gaus(4) + gaus(7) + gaus(10) + gaus(13) + gaus(16) + gaus(19) + gaus(22) + gaus(25) + \
    gaus(28) +  gaus(31) + gaus(34) + [37]", 
    minRange, maxRange
  );
  SetLineCosmetics(fTotal, kRed+1, 2, 2);
  // 
  SetParInfo(fTotal, 0, 250, 0, totalEntries, "Exp0Norm");
  SetParInfo(fTotal, 1, 2.2, 0.2, 25, "Exp0Decay");
  //
  SetParInfo(fTotal, 2, 50, 0, totalEntries, "Exp1Norm");
  SetParInfo(fTotal, 3, 0.16, 0.02, 2.0, "Exp1Decay");
  // Gauss0
  SetParInfo(fTotal, 4, 1000, 0., totalEntries, "Gaus0Norm");
  SetParInfo(fTotal, 5, 1.1, 0.5,2.0, "Gaus0Mu");
  SetParInfo(fTotal, 6, 0.1, 0.,1., "Gaus0Sigma");
  // Gauss1
  SetParInfo(fTotal, 7, 300, 0., totalEntries, "Gaus1Norm");
  SetParInfo(fTotal, 8, 1.7, 1.0, 2.5, "Gaus1Mu");
  SetParInfo(fTotal, 9, 0.1, 0.,1., "Gaus1Sigma");
  // Gauss2
  SetParInfo(fTotal, 10, 500, 0., totalEntries, "Gaus2Norm");
  SetParInfo(fTotal, 11, 2.4, 1.5, 3.0, "Gaus2Mu");
  SetParInfo(fTotal, 12, 0.1, 0.,1., "Gaus2Sigma");
  // Gauss3
  SetParInfo(fTotal, 13, 500, 0., totalEntries, "Gaus3Norm");
  SetParInfo(fTotal, 14, 2.9, 2.5, 3.5, "Gaus3Mu");
  SetParInfo(fTotal, 15, 0.1, 0.,1., "Gaus3Sigma");
  // Gauss4
  SetParInfo(fTotal, 16, 200, 0., totalEntries, "Gaus4Norm");
  SetParInfo(fTotal, 17, 3.4, 3.0, 4.0, "Gaus4Mu");
  SetParInfo(fTotal, 18, 0.1, 0.,1., "Gaus4Sigma");
  // Gauss5
  SetParInfo(fTotal, 19, 1000, 0., totalEntries, "Gaus5Norm");
  SetParInfo(fTotal, 20, 4.2, 3.5, 4.5, "Gaus5Mu");
  SetParInfo(fTotal, 21, 0.1, 0.,1., "Gaus5Sigma");
  // Gauss6
  SetParInfo(fTotal, 22, 900, 0., totalEntries, "Gaus6Norm");
  SetParInfo(fTotal, 23, 5.3, 4.5, 5.5, "Gaus6Mu");
  SetParInfo(fTotal, 24, 0.1, 0.,1., "Gaus6Sigma");
  // Gauss7
  SetParInfo(fTotal, 25, 500, 0., totalEntries, "Gaus7Norm");
  SetParInfo(fTotal, 26, 6.4, 5.0, 7.0, "Gaus7Mu");
  SetParInfo(fTotal, 27, 0.1, 0.,1., "Gaus7Sigma");
  // Gauss8
  SetParInfo(fTotal, 28, 500, 0., totalEntries, "Gaus8Norm");
  SetParInfo(fTotal, 29, 7.0, 6.5, 7.5, "Gaus8Mu");
  SetParInfo(fTotal, 30, 0.1, 0.,1., "Gaus8Sigma");
  // Gauss9
  SetParInfo(fTotal, 31, 600, 0., totalEntries, "Gaus9Norm");
  SetParInfo(fTotal, 32, 7.5, 7.0, 8.0, "Gaus9Mu");
  SetParInfo(fTotal, 33, 0.1, 0.,1., "Gaus9Sigma");
  // Gauss10
  SetParInfo(fTotal, 34, 600, 0., totalEntries, "Gaus10Norm");
  SetParInfo(fTotal, 35, 8.2, 7.5, 8.5, "Gaus10Mu");
  SetParInfo(fTotal, 36, 0.1, 0.,1., "Gaus10Sigma");
  // pol0
  SetParInfo(fTotal, 37, 30., 0., 200., "Pol0");


  //
  // Run the fit here
  //

  muonDecayCurve->Fit(fTotal, "L", "", minFitRange, maxFitRange);

  auto fitPar0 = fTotal->GetParameter(0);
  auto fitPar1 = fTotal->GetParameter(1);
  auto fitPar2 = fTotal->GetParameter(2);
  auto fitPar3 = fTotal->GetParameter(3);
  auto fitPar4 = fTotal->GetParameter(4);
  auto fitPar5 = fTotal->GetParameter(5);
  auto fitPar6 = fTotal->GetParameter(6);
  auto fitPar7 = fTotal->GetParameter(7);
  auto fitPar8 = fTotal->GetParameter(8);
  auto fitPar9 = fTotal->GetParameter(9);

  //
  //
  //
  auto fExp0 = new TF1("fExp0","[0]/[1]*exp(-x/[1])", minRange, maxRange);
  fExp0->SetParameter(0, fitPar0);//Initial parameter values
  fExp0->SetParameter(1, fitPar1);//Initial parameter values
  SetLineCosmetics(fExp0, kRed+1, 2, 2);

  auto fExp1 = new TF1("fExp1","[0]/[1]*exp(-x/[1])", minRange, maxRange);
  fExp1->SetParameter(0, fitPar2);//Initial parameter values
  fExp1->SetParameter(1, fitPar3);//Initial parameter values
  SetLineCosmetics(fExp1, kGreen+1, 2, 2);

  auto fGaus0 = new TF1("fGaus0","gaus", minRange, maxRange);
  fGaus0->SetParameter(0, fitPar4);//Initial parameter values
  fGaus0->SetParameter(1, fitPar5);//Initial parameter values
  fGaus0->SetParameter(2, fitPar6);//Initial parameter values
  SetLineCosmetics(fGaus0, kMagenta+1, 2, 2);

  auto fGaus1 = new TF1("fGaus1","gaus", minRange, maxRange);
  fGaus1->SetParameter(0, fitPar7);//Initial parameter values
  fGaus1->SetParameter(1, fitPar8);//Initial parameter values
  fGaus1->SetParameter(2, fitPar9);//Initial parameter values
  SetLineCosmetics(fGaus1, kMagenta+1, 2, 2);

  TCanvas* canv = MakeCanvas_WithStatsPad("FitMuonDecayCurve_"+runRange);
  auto pad1 = GetPadFromCanvas(canv, "pad1");
  auto pad2 = GetPadFromCanvas(canv, "pad2");

  //
  //
  //
  pad1->cd();

  muonDecayCurve->SetMinimum(10);
  muonDecayCurve->Draw("HIST");
  fTotal->Draw("SAME");
  // fExp0->Draw("SAME");
  // fExp1->Draw("SAME");
  // fGaus0->Draw("SAME");
  // fGaus1->Draw("SAME");
  gPad->Update();

  muonDecayCurve->SetStats(1);
  TPaveStats* st = (TPaveStats*)muonDecayCurve->FindObject("stats");
  TPaveStats* stC = (TPaveStats*)st->Clone("statsC");
  muonDecayCurve->SetStats(0);

  pad1->SetLogy();

  //
  //
  //
  pad2->cd();
  stC->SetTextSize(0.05);
  stC->SetX1NDC(0.025);
  stC->SetX2NDC(0.950);
  stC->SetY1NDC(0.025);
  stC->SetY2NDC(0.950);
  stC->Draw();
  
  canv->SaveAs("./plots/"+TString(canv->GetName())+".pdf");

  delete canv;
}

void FitMuonDecayCurve(){
  // DoFit("1436-1464");
  // DoFit("1465-1524");
  DoFit("1530-1880");
}

int main(){
  FitMuonDecayCurve();
  return 1;
}