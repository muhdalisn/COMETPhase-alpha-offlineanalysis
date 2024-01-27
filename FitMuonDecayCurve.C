//
// root -l -b -q FitMuonDecayCurve.C
// Before executing this script, copy histogram rootfiles from Roden's storage space:
// > /gpfs/group/had/muon/derveni/phasealpha/data/output/hists/merged/
//
//
#include <stdio.h>
#include <string>
#include "math.h"
#include "TF1.h"  
#include "TH1D.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TPaveStats.h"
#include "TVirtualFitter.h"

#include "Utils.h"
#include "PlotStyle.C"



void DoFit(TString runRange = "3204-3281"){
  SetPlotStyle();
  gStyle->SetOptStat(0);


  TFile* inFile = new TFile("/home/muhdalisn/phase-alpha-histo/"+runRange+".root");
  TH1D*  muonDecayCurve = (TH1D*) inFile->Get("histos/RCMuonDecayAnalysisHistos/MuonDecayCurve/MuonDecayCurve");
  
   

  float minRange = 0; // optimum is -1
  float maxRange = 8.7;  // optimum is 9.

  float minFitRange = 0.1;   //optimum is -1
  float maxFitRange = 8.7;  //optimum is 8.7

  Double_t totalEntries = muonDecayCurve->Integral(0,muonDecayCurve->GetNbinsX()+1);


 TH1D *norm = (TH1D *)muonDecayCurve->Clone("norm");
 norm->Scale(4.28 /norm->Integral(), "width");
 
 TVirtualFitter::SetMaxIterations(10000);
 

 auto fTotal = new TF1("fTotal", "(0<x)*([0]/[1])*exp(-x/[1])+([2]/[3])*exp(-x/([3]))+[4]+gaus(5)+gaus(8)+gaus(11)+gaus(14)+gaus(17)+gaus(20)+gaus(23)+gaus(26)+gaus(29)+gaus(32)+gaus(35)+gaus(38)", minRange, maxRange);

  SetLineCosmetics(fTotal, kRed+1, 2, 2);

 SetParInfo(fTotal, 0, 1300, -1, 1300, "N_DIO");  // 0.09, 0.15,2.5
 SetParInfo(fTotal, 1, 0.185, 0.18, 0.219,  "T_DIO");  //0.165,0.18,0.25 //2.0, 0.18, 2.3 //0.165, 0.16, 0.1691
 SetParInfo(fTotal, 2, 250, -1, 250, "N_free");     //1.2,5.1,8.5,
 SetParInfo(fTotal, 3, 2.2, 2.0, 2.20, "T_free");      //2.20,2.1,3  //3.3, 3.0, 3.5 //2.2, 2.1, 2.20
 SetParInfo(fTotal, 4, 0.14, 0.11, 0.18, "BG");
 SetParInfo(fTotal, 5, 200, 0., totalEntries, "Gaus1Norm");
 SetParInfo(fTotal, 6, 0.05, 0., 0.1, "Gaus1Mu"); //1.1, 0.5, 2.0
 SetParInfo(fTotal, 7, 0.05, 0.,0.1, "Gaus1Sigma");
 SetParInfo(fTotal, 8, 30, 0., totalEntries, "Gaus2Norm");
 SetParInfo(fTotal, 9, 1.1, 1.0, 1.2, "Gaus2Mu"); //1.7, 1.0, 2.5
 SetParInfo(fTotal, 10, 0.05, 0.,0.1, "Gaus2Sigma");
 SetParInfo(fTotal, 11, 50, 0., totalEntries, "Gaus3Norm");
 SetParInfo(fTotal, 12, 1.7, 1.6, 1.8, "Gaus3Mu"); //2.4, 1.5, 3.0
 SetParInfo(fTotal, 13, 0.05, 0.,0.1, "Gaus3Sigma");
 SetParInfo(fTotal, 14, 10, 0., totalEntries, "Gaus4Norm");
 SetParInfo(fTotal, 15, 2.2, 2.1, 2.4, "Gaus4Mu"); //2.9,2.5, 3.5
 SetParInfo(fTotal, 16, 0.05, 0.,0.1, "Gaus4Sigma");
 SetParInfo(fTotal, 17, 20, 0., totalEntries, "Gaus5Norm");
 SetParInfo(fTotal, 18, 2.9, 2.8, 3.0, "Gaus5Mu"); //3.4, 3.0, 4.0
 SetParInfo(fTotal, 19, 0.05, 0.,0.1, "Gaus5Sigma");
 SetParInfo(fTotal, 20, 10, 0., totalEntries, "Gaus6Norm");
 SetParInfo(fTotal, 21, 3.5, 3.4, 3.6, "Gaus6Mu"); //4.2, 3.5, 4.5
 SetParInfo(fTotal, 22, 0.05, 0.,0.1, "Gaus6Sigma");
 SetParInfo(fTotal, 23, 20, 0., totalEntries, "Gaus7Norm");
 SetParInfo(fTotal, 24, 4.1, 4.0, 4.2, "Gaus7Mu"); //5.3, 4.5, 5.5
 SetParInfo(fTotal, 25, 0.05, 0.,0.1, "Gaus7Sigma");
 SetParInfo(fTotal, 26, 20, 0., totalEntries, "Gaus8Norm");
 SetParInfo(fTotal, 27, 5.2, 5.1, 5.3, "Gaus8Mu"); //6.4, 5.0, 7.0
 SetParInfo(fTotal, 28, 0.05, 0.,0.1, "Gaus8Sigma");
 SetParInfo(fTotal, 29, 20, 0., totalEntries, "Gaus9Norm");
 SetParInfo(fTotal, 30, 6.4, 6.3, 6.5, "Gaus9Mu"); //7.0, 6.5, 7.5
 SetParInfo(fTotal, 31, 0.05, 0.,0.1, "Gaus9Sigma");
 SetParInfo(fTotal, 32, 20, 0., totalEntries, "Gaus10Norm");
 SetParInfo(fTotal, 33, 6.8, 6.7, 7.1, "Gaus10Mu"); //7.5, 7.0, 8.5
 SetParInfo(fTotal, 34, 0.05, 0.,0.1, "Gaus10Sigma");
 SetParInfo(fTotal, 35, 20, 0., totalEntries, "Gaus11Norm");
 SetParInfo(fTotal, 36, 7.6, 7.5, 7.7, "Gaus11Mu"); //8.2, 7.5, 8.5
 SetParInfo(fTotal, 37, 0.05, 0.,0.1, "Gaus11Sigma");
 SetParInfo(fTotal, 38, 20, 0., totalEntries, "Gaus12Norm");
 SetParInfo(fTotal, 39, 8.1, 8.0, 8.2, "Gaus12Mu"); //0, -0.3, 0.3
 SetParInfo(fTotal, 40, 0.05, 0.,0.1, "Gaus12Sigma");
  //
  // Run the fit here
  //
  norm->Fit(fTotal, "L", "", minFitRange, maxFitRange); 

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
  auto fitPar10 = fTotal->GetParameter(10);
  auto fitPar11 = fTotal->GetParameter(11);
  auto fitPar12 = fTotal->GetParameter(12);
  auto fitPar13 = fTotal->GetParameter(13);
  auto fitPar14 = fTotal->GetParameter(14);
  auto fitPar15 = fTotal->GetParameter(15);
  auto fitPar16 = fTotal->GetParameter(16);
  auto fitPar17 = fTotal->GetParameter(17);
  auto fitPar18 = fTotal->GetParameter(18);
  auto fitPar19 = fTotal->GetParameter(19);
  auto fitPar20 = fTotal->GetParameter(20);
  auto fitPar21 = fTotal->GetParameter(21);
  auto fitPar22 = fTotal->GetParameter(22);
  auto fitPar23 = fTotal->GetParameter(23);
  auto fitPar24 = fTotal->GetParameter(24);
  auto fitPar25 = fTotal->GetParameter(25);
  auto fitPar26 = fTotal->GetParameter(26);
  auto fitPar27 = fTotal->GetParameter(27);
  auto fitPar28 = fTotal->GetParameter(28);
  auto fitPar29 = fTotal->GetParameter(29);
  auto fitPar30 = fTotal->GetParameter(30);
  auto fitPar31 = fTotal->GetParameter(31);
  auto fitPar32 = fTotal->GetParameter(32);
  auto fitPar33 = fTotal->GetParameter(33);
  auto fitPar34 = fTotal->GetParameter(34);
  auto fitPar35 = fTotal->GetParameter(35);
  auto fitPar36 = fTotal->GetParameter(36);
  auto fitPar37 = fTotal->GetParameter(37);
  auto fitPar38 = fTotal->GetParameter(38);
  auto fitPar39 = fTotal->GetParameter(39);
  auto fitPar40 = fTotal->GetParameter(40);
 
  auto fExp0 = new TF1("fExp0","(0<x)*(([0]/[1])*exp(-x/[1])+([2]/[3])*exp(-x/([3]))+[4])", minRange, maxRange);
  fExp0->SetParameter(0, fitPar0);//Initial parameter values
  fExp0->SetParameter(1, fitPar1);//Initial parameter values
  fExp0->SetParameter(2, fitPar2);//Initial parameter values
  fExp0->SetParameter(3, fitPar3);
  fExp0->SetParameter(4, fitPar4);
  SetLineCosmetics(fExp0, kBlack,2,2);

  auto fExp1 = new TF1("fExp1","(0<x)*(([2]/[3])*exp(-x/([3]))+[4])", minRange, maxRange); //(0<x)*(([2]/[3])*exp(-x/[3])+[4])
  fExp1->SetParameter(2, fitPar2);//Initial parameter values
  fExp1->SetParameter(3, fitPar3);//Initial parameter values
  fExp1->SetParameter(4, fitPar4);
  SetLineCosmetics(fExp1, kGreen,2,2); 

  auto fLin = new TF1("fLin","[4]", minRange, maxRange);
  fLin->SetParameter(4, fitPar4);//Initial parameter values
  SetLineCosmetics(fLin, kMagenta,2,2);

 auto fGaus1 = new TF1("fGaus1","gaus(5)", minRange, maxRange);
  fGaus1->SetParameter(5, fitPar5);
  fGaus1->SetParameter(6, fitPar6);
  fGaus1->SetParameter(7, fitPar7);
  SetLineCosmetics(fGaus1, kBlue,2,2);

  auto fGaus2 = new TF1("fGaus2","gaus(8)", minRange, maxRange);
  fGaus2->SetParameter(8,  fitPar8);
  fGaus2->SetParameter(9, fitPar9);
  fGaus2->SetParameter(10, fitPar10);
  SetLineCosmetics(fGaus2, kBlue,2,2);

  auto fGaus3 = new TF1("fGaus3","gaus(11)", minRange, maxRange);
  fGaus3->SetParameter(11,  fitPar11);
  fGaus3->SetParameter(12, fitPar12);
  fGaus3->SetParameter(13, fitPar13);
  SetLineCosmetics(fGaus3, kBlue,2,2);

  auto fGaus4 = new TF1("fGaus4","gaus(14)", minRange, maxRange);
  fGaus4->SetParameter(14,  fitPar14);
  fGaus4->SetParameter(15, fitPar15);
  fGaus4->SetParameter(16, fitPar16);
  SetLineCosmetics(fGaus4, kBlue,2,2);

  auto fGaus5 = new TF1("fGaus5","gaus(17)", minRange, maxRange);
  fGaus5->SetParameter(17,  fitPar17);
  fGaus5->SetParameter(18, fitPar18);
  fGaus5->SetParameter(19, fitPar19);
  SetLineCosmetics(fGaus5, kBlue,2,2);

  auto fGaus6 = new TF1("fGaus6","gaus(20)", minRange, maxRange);
  fGaus6->SetParameter(20,  fitPar20);
  fGaus6->SetParameter(21, fitPar21);
  fGaus6->SetParameter(22, fitPar22);
  SetLineCosmetics(fGaus6, kBlue,2,2);

  auto fGaus7 = new TF1("fGaus7","gaus(23)", minRange, maxRange);
  fGaus7->SetParameter(23,  fitPar23);
  fGaus7->SetParameter(24, fitPar24);
  fGaus7->SetParameter(25, fitPar25);
  SetLineCosmetics(fGaus7, kBlue,2,2);

  auto fGaus8 = new TF1("fGaus8","gaus(26)", minRange, maxRange);
  fGaus8->SetParameter(26,  fitPar26);
  fGaus8->SetParameter(27, fitPar27);
  fGaus8->SetParameter(28, fitPar28);
  SetLineCosmetics(fGaus8, kBlue,2,2);

  auto fGaus9 = new TF1("fGaus9","gaus(29)", minRange, maxRange);
  fGaus9->SetParameter(29,  fitPar29);
  fGaus9->SetParameter(30, fitPar30);
  fGaus9->SetParameter(31, fitPar31);
  SetLineCosmetics(fGaus9, kBlue,2,2);

  auto fGaus10 = new TF1("fGaus10","gaus(32)", minRange, maxRange);
  fGaus10->SetParameter(32,  fitPar32);
  fGaus10->SetParameter(33, fitPar33);
  fGaus10->SetParameter(34, fitPar34);
  SetLineCosmetics(fGaus10, kBlue,2,2);

  auto fGaus11 = new TF1("fGaus11","gaus(35)", minRange, maxRange);
  fGaus11->SetParameter(35,  fitPar35);
  fGaus11->SetParameter(36, fitPar36);
  fGaus11->SetParameter(37, fitPar37);
  SetLineCosmetics(fGaus11, kBlue,2,2);

  auto fGaus12 = new TF1("fGaus12","gaus(38)", minRange, maxRange);
  fGaus12->SetParameter(38,  fitPar38);
  fGaus12->SetParameter(39, fitPar39);
  fGaus12->SetParameter(40, fitPar40);
  SetLineCosmetics(fGaus12, kBlue,2,2);

 
  TCanvas* canv = MakeCanvas_WithStatsPad("FitMuonDecayCurve_"+runRange);
  auto pad1 = GetPadFromCanvas(canv, "pad1");
  auto pad2 = GetPadFromCanvas(canv, "pad2");

  //
  //
  //
  pad1->cd();
  norm->SetMinimum(0.01); //
  norm->SetMaximum(100);
  //muonDecayCurve->Scale(totalEntries);
  norm->Draw("HIST");
//  muonDecayCurve1->SetMinimum(0.5);
//  muonDecayCurve1->Draw("HIST");
  fTotal->SetNpx(500); //500
  fTotal->Draw("SAME");
  fExp0->Draw("SAME");
  fExp1->Draw("SAME");
  fLin->Draw("SAME");
  fGaus1->Draw("SAME");
  fGaus2->Draw("SAME");
  fGaus3->Draw("SAME");
  fGaus4->Draw("SAME");
  fGaus5->Draw("SAME");
  fGaus6->Draw("SAME");
  fGaus7->Draw("SAME");
  fGaus8->Draw("SAME");
  fGaus9->Draw("SAME");
  fGaus10->Draw("SAME");
  fGaus11->Draw("SAME");
  fGaus12->Draw("SAME");
  gPad->Update();

  norm->SetStats(1);
  TPaveStats* st = (TPaveStats*)norm->FindObject("stats");
  TPaveStats* stC = (TPaveStats*)st->Clone("statsC");
  norm->SetStats(0);

  pad1->SetLogy();
  //
  //
  //
  pad2->cd();
  stC->SetTextSize(0.05);
  stC->SetX1NDC(0.025); //0.025
  stC->SetX2NDC(0.950); //0.950
  stC->SetY1NDC(0.025); //0.025
  stC->SetY2NDC(0.950); //0.950
  stC->Draw();
  
  canv->SaveAs("./plots/"+TString(canv->GetName())+".pdf");

  delete canv;
}
void FitMuonDecayCurve(){
  DoFit("3204-3281"); 
}

int main(){
  FitMuonDecayCurve();
  return 1;
}
