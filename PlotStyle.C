#include "TStyle.h"

void SetPlotStyle() 
{
  TStyle *plotStyle = new TStyle("plotStyle","custom plotting style");

// For the canvas:
  plotStyle->SetCanvasBorderMode(0);
  plotStyle->SetCanvasColor(kWhite);
  plotStyle->SetCanvasDefH(600); //Height of canvas
  plotStyle->SetCanvasDefW(600); //Width of canvas
  plotStyle->SetCanvasDefX(0);   //POsition on screen
  plotStyle->SetCanvasDefY(0);

// For the Pad:
  plotStyle->SetPadBorderMode(0);
  // plotStyle->SetPadBorderSize(Width_t size = 1);
  plotStyle->SetPadColor(kWhite);
  plotStyle->SetPadGridX(false);
  plotStyle->SetPadGridY(false);
  plotStyle->SetGridColor(0);
  plotStyle->SetGridStyle(3);
  plotStyle->SetGridWidth(1);

// For the frame:
  plotStyle->SetFrameBorderMode(0);
  plotStyle->SetFrameBorderSize(1);
  plotStyle->SetFrameFillColor(0);
  plotStyle->SetFrameFillStyle(0);
  plotStyle->SetFrameLineColor(1);
  plotStyle->SetFrameLineStyle(1);
  plotStyle->SetFrameLineWidth(1);
  
// For the histo:
  // plotStyle->SetHistFillColor(1);
  // plotStyle->SetHistFillStyle(0);
  plotStyle->SetHistLineColor(1);
  plotStyle->SetHistLineStyle(0);
  plotStyle->SetHistLineWidth(1);
  // plotStyle->SetLegoInnerR(Float_t rad = 0.5);
  // plotStyle->SetNumberContours(Int_t number = 20);

  plotStyle->SetEndErrorSize(2);
  // plotStyle->SetErrorMarker(20);
  //plotStyle->SetErrorX(0.);
  
  plotStyle->SetMarkerStyle(20);
  
//For the fit/function:
  plotStyle->SetOptFit(1);
  plotStyle->SetFitFormat("5.4g");
  plotStyle->SetFuncColor(2);
  plotStyle->SetFuncStyle(1);
  plotStyle->SetFuncWidth(1);

//For the date:
  plotStyle->SetOptDate(0);
  // plotStyle->SetDateX(Float_t x = 0.01);
  // plotStyle->SetDateY(Float_t y = 0.01);

// For the statistics box:
  plotStyle->SetOptFile(0);
  plotStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  plotStyle->SetStatColor(kWhite);
  plotStyle->SetStatFont(42);
  plotStyle->SetStatFontSize(0.025);
  plotStyle->SetStatTextColor(1);
  plotStyle->SetStatFormat("6.4g");
  plotStyle->SetStatBorderSize(1);
  plotStyle->SetStatH(0.1);
  plotStyle->SetStatW(0.15);
  // plotStyle->SetStatStyle(Style_t style = 1001);
  // plotStyle->SetStatX(Float_t x = 0);
  // plotStyle->SetStatY(Float_t y = 0);

// Margins:
  plotStyle->SetPadTopMargin(0.06);
  plotStyle->SetPadBottomMargin(0.13);
  plotStyle->SetPadLeftMargin(0.12);
  plotStyle->SetPadRightMargin(0.05);

// For the Global title:

  plotStyle->SetOptTitle(0);
  plotStyle->SetTitleFont(42);
  plotStyle->SetTitleColor(1);
  plotStyle->SetTitleTextColor(1);
  plotStyle->SetTitleFillColor(10);
  plotStyle->SetTitleFontSize(0.05);
  // plotStyle->SetTitleH(0); // Set the height of the title box
  // plotStyle->SetTitleW(0); // Set the width of the title box
  // plotStyle->SetTitleX(0); // Set the position of the title box
  // plotStyle->SetTitleY(0.985); // Set the position of the title box
  // plotStyle->SetTitleStyle(Style_t style = 1001);
  // plotStyle->SetTitleBorderSize(2);

// For the axis titles:

  plotStyle->SetTitleColor(1, "XYZ");
  plotStyle->SetTitleFont(42, "XYZ");
  plotStyle->SetTitleSize(0.06, "XYZ");
  // plotStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // plotStyle->SetTitleYSize(Float_t size = 0.02);
  plotStyle->SetTitleXOffset(0.9);
  plotStyle->SetTitleYOffset(1.00);
  // plotStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

// For the axis labels:

  plotStyle->SetLabelColor(1, "XYZ");
  plotStyle->SetLabelFont(42, "XYZ");
  plotStyle->SetLabelOffset(0.007, "XYZ");
  plotStyle->SetLabelSize(0.05, "XYZ");

// For the axis:

  plotStyle->SetAxisColor(1, "XYZ");
  plotStyle->SetStripDecimals(kTRUE);
  plotStyle->SetTickLength(0.03, "XYZ");
  plotStyle->SetNdivisions(510, "XYZ");
  plotStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  plotStyle->SetPadTickY(1);

  // Change for log plots:
  plotStyle->SetOptLogx(0);
  plotStyle->SetOptLogy(0);
  plotStyle->SetOptLogz(0);

  // Postscript options:
  plotStyle->SetPaperSize(20.,20.);
  // plotStyle->SetLineScalePS(Float_t scale = 3);
  // plotStyle->SetLineStyleString(Int_t i, const char* text);
  // plotStyle->SetHeaderPS(const char* header);
  // plotStyle->SetTitlePS(const char* pstitle);

  // plotStyle->SetBarOffset(Float_t baroff = 0.5);
  // plotStyle->SetBarWidth(Float_t barwidth = 0.5);
  // plotStyle->SetPaintTextFormat(const char* format = "g");
  // plotStyle->SetPalette(Int_t ncolors = 0, Int_t* colors = 0);
  // plotStyle->SetTimeOffset(Double_t toffset);
  // plotStyle->SetHistMinimumZero(kTRUE);

  // plotStyle->SetHatchesLineWidth(5);
  // plotStyle->SetHatchesSpacing(0.05);

  plotStyle->cd();

}