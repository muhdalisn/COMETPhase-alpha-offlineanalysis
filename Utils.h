#include "TCanvas.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH1.h"
#include "TGraphAsymmErrors.h"
#include "TArrow.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TFile.h"
#include "TTree.h"
#include "THStack.h"
#include "TROOT.h"

#include <cmath>
#include <map>
#include <vector>
#include <iostream>

void SetParInfo(TF1* f, int i, float value, float low, float up, TString name){
  f->SetParameter(i, value);
  f->SetParLimits(i, low, up);
  f->SetParName(i, name);
}

template<typename T>
void SetLineCosmetics(T* obj, int color, int style, int width){
  obj->SetLineColor(color);
  obj->SetLineStyle(style);
  obj->SetLineWidth(width);
}

TCanvas* MakeBoxCanvas(TString canvName){
  TCanvas* c = new TCanvas(canvName, canvName , 600, 600);
  c->SetLeftMargin(0.15);
  c->SetRightMargin(0.08);
  c->SetTopMargin(0.05);
  c->SetBottomMargin(0.15);
  
  return c;
}
TPad* GetPadFromCanvas(TCanvas* canv, TString padName){
  TPad* pad = 0;
  pad = (TPad*) canv->GetListOfPrimitives()->FindObject(TString(canv->GetName()) + "_" + padName );
  return pad;
}
TCanvas* MakeBoxCanvas_WithRatioPad(TString canvName){
  TCanvas* c = new TCanvas(canvName, canvName , 600, 600);
  c->SetFillStyle( 4000 );
  c->Draw();
  
  double the_low_margin = 0.3;
  
  TPad* pad1 = new TPad(canvName + "_pad1", canvName + "_pad1",0.0, the_low_margin, 1.0, 1.0);
  pad1->SetTopMargin( 0.06 );
  pad1->SetBottomMargin( 0.0 );
  pad1->SetFillStyle( 4000 );
  pad1->SetFillColor( 0 );
  pad1->SetFrameFillStyle( 4000 );
  pad1->SetFrameFillColor( 0 );
  pad1->Draw();

  TPad* pad2 = new TPad(canvName + "_pad2",canvName + "_pad2",0.0, 0.0, 1.0, the_low_margin);
  pad2->SetTopMargin( 0.05 );
  pad2->SetBottomMargin( 0.325 );
  pad2->SetFillStyle( 4000 );
  pad2->SetFillColor( 0 );
  pad2->SetFrameFillStyle( 4000 );
  pad2->SetFrameFillColor( 0 );
  pad2->Draw();
  
  return c;
}
TCanvas* MakeCanvas43(TString canvName){
  TCanvas* c = new TCanvas(canvName, canvName , 800, 600);
  c->SetLeftMargin(0.15);
  c->SetRightMargin(0.08);
  c->SetTopMargin(0.05);
  c->SetBottomMargin(0.15);
  
  return c;
}
TCanvas* MakeCanvas43_WithRatioPad(TString canvName){
  TCanvas* c = new TCanvas(canvName, canvName , 800, 600);
  c->SetFillStyle( 4000 );
  c->Draw();
  
  double the_low_margin = 0.3;
  
  TPad* pad1 = new TPad(canvName + "_pad1", canvName + "_pad1",0.0, the_low_margin, 1.0, 1.0);
  pad1->SetTopMargin( 0.06 );
  pad1->SetBottomMargin( 0.0 );
  pad1->SetFillStyle( 4000 );
  pad1->SetFillColor( 0 );
  pad1->SetFrameFillStyle( 4000 );
  pad1->SetFrameFillColor( 0 );
  pad1->Draw();

  TPad* pad2 = new TPad(canvName + "_pad2",canvName + "_pad2",0.0, 0.0, 1.0, the_low_margin);
  pad2->SetTopMargin( 0.05 );
  pad2->SetBottomMargin( 0.325 );
  pad2->SetFillStyle( 4000 );
  pad2->SetFillColor( 0 );
  pad2->SetFrameFillStyle( 4000 );
  pad2->SetFrameFillColor( 0 );
  pad2->Draw();
  
  return c;
}
TCanvas* MakeCanvas_WithStatsPad(TString canvName){
  TCanvas* c = new TCanvas(canvName, canvName , 1000, 600);
  c->SetFillStyle( 4000 );
  c->Draw();
  
  double the_right_margin = 0.75;
  
  TPad* pad1 = new TPad(canvName + "_pad1", canvName + "_pad1",0.0, 0.0, the_right_margin, 1.0);
  pad1->SetTopMargin( 0.06 );
  pad1->SetBottomMargin( 0.15 );
  pad1->SetFillStyle( 4000 );
  pad1->SetFillColor( 0 );
  pad1->SetFrameFillStyle( 4000 );
  pad1->SetFrameFillColor( 0 );
  pad1->Draw();

  TPad* pad2 = new TPad(canvName + "_pad2",canvName + "_pad2",the_right_margin, 0.0, 1.0, 1.0);
  pad2->SetTopMargin( 0.05 );
  pad2->SetBottomMargin( 0.15 );
  pad2->SetFillStyle( 4000 );
  pad2->SetFillColor( 0 );
  pad2->SetFrameFillStyle( 4000 );
  pad2->SetFrameFillColor( 0 );
  pad2->Draw();
  
  return c;
}