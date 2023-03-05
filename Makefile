ROOTFLAG = $(shell root-config --glibs --cflags)
CFLAG = -Wall -I./ -I$(ANAHOME)/include -I$(ROMESYS)/include -I$(HOME)/.rootmacros $(ROOTFLAG)
CLIBS = -L$(ANAHOME)/obj -lcalphaanalyzer 

CXX = g++

SRC = $(ANAHOME)/src
OBJ = $(ANAHOME)/obj

all: FitMuonDecayCurve.exe WaveformAnalysis.exe

FitMuonDecayCurve.exe: FitMuonDecayCurve.C
	$(CXX) $(CFLAG) $(CLIBS) -Wall -g -o FitMuonDecayCurve.exe FitMuonDecayCurve.C

WaveformAnalysis.exe: WaveformAnalysis.C
	$(CXX) $(CFLAG) $(CLIBS) -Wall -g -o WaveformAnalysis.exe WaveformAnalysis.C

clean:
	rm -f *.o *.exe
