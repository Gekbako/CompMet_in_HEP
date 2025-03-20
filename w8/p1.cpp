#include "Pythia8/Pythia.h"
#include <iostream>

using namespace Pythia8;
using namespace std;

int main(int argc, char* argv[]) {
    // Initialize Pythia
    Pythia pythia;
    // proton beam
    pythia.readString("Beams:idA = 2212");
    // proton beam
    pythia.readString("Beams:idB = 2212"); 
    // 13 TeV collisions
    pythia.readString("Beams:eCM = 13000."); 
    // higgs production -> on
    pythia.readString("HiggsSM:all = on"); 
    pythia.init();
    
    // h boson width,PDG ID 25 for h boson
    double higgsWidth = pythia.particleData.mWidth(25); 
    
    
    cout << "Width at 125 GeV = " << higgsWidth << " GeV" << endl;
    
    return 0;
}
