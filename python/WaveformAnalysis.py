#
# NOTE: Still under development
#
import ROOT
ROOT.gROOT.SetBatch(True)
#
# After compiling with fast_romebuilder.sh, execute:
# > make so
# to generate the shared library

#
# Note: we need to add include because we're not running
# this script in the same directory as the analyser
#
ROOT.gInterpreter.AddIncludePath("../../analyser/include/")
ROOT.gSystem.Load("../../analyser/obj/libcalphaanalyzer.so")

inFile = ROOT.TFile("/group/had/muon/2023.2.Phase-Alpha/anadata/picotree01513.root")
inTree = inFile.Get("picotree")
