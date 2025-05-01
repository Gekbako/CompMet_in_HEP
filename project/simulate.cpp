#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TTree.h"
#include <cmath>

using namespace Pythia8;
using namespace std;

struct muon {
    double pt, eta;
};

// struct result {
//     int nEvents,nMuMu,nTrig;
//     double BR,TE;
// };

bool passesTrigger(const vector<muon>& muons) {
    int nPassed = 0;
    for (const auto& mu : muons) {
        if (fabs(mu.eta) < 2.1 && mu.pt > 20.0) nPassed++;
    }
    return nPassed >= 2;
}

void simulate(const int& nEvents, const string& label, const string& mode,vector<double>& data) {
    Pythia pythia;
    if (mode == "z") {
        pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
    } else if (mode == "ttbar") {
        pythia.readString("Top:gg2ttbar = on");
        pythia.readString("Top:qqbar2ttbar = on");
    } else {
        cerr << "Unknown mode: " << mode << endl;
        exit(0);
    }
    pythia.readString("Print:quiet = on");
    pythia.readString("Beams:eCM = 13600.");
    pythia.init();
    int nMuMu = 0, nTrig = 0;

    TFile outFile((label + ".root").c_str(), "RECREATE");
    TTree tree("Events", "all μμ events passing trigger");

    double pt1, eta1, pt2, eta2;
    tree.Branch("pt1", &pt1);
    tree.Branch("eta1", &eta1);
    tree.Branch("pt2", &pt2);
    tree.Branch("eta2", &eta2);

    for (int i = 0; i < nEvents; ++i) {
        if (!pythia.next()) continue;

        vector<muon> muons;
        for (int j = 0; j < pythia.event.size(); ++j) {
            const Particle& p = pythia.event[j];
            if (p.idAbs() == 13 && p.isFinal()) {
                muons.push_back({p.pT(), p.eta()});
            }
        }

        if (muons.size() < 2) continue;

        nMuMu++;

        if (passesTrigger(muons)) {
            pt1 = muons[0].pt;
            eta1 = muons[0].eta;
            pt2 = muons[1].pt;
            eta2 = muons[1].eta;
            tree.Fill();
            nTrig++;
        }
    }

    tree.Write();
    outFile.Close();

    cout << "\n[" << label << "]"
            << "\nTotal events: " << nEvents
            << "\n→ μμ events: " << nMuMu
            << "\n→ Trigger passed: " << nTrig
            << "\nNatural BR to μμ: " << double(nMuMu) / nEvents
            << "\nTrigger efficiency: " << double(nTrig) / nMuMu << "\n";

    data.push_back(double(nMuMu) / nEvents);
}

int main() {
    vector<double> z,ttbar;
    for (int i = 1;i < 6;++i){
        int n = pow(10,i);
        simulate(n,"z", "z",z);
        
    }
    for (int i = 1;i < 6;++i) {
        int n = pow(10,i);
        simulate(n,"ttbar", "ttbar",ttbar);
    }

    for (int i = 0;i < 5;++i) {
        cout << " , "<<z[i];
    }

    cout << endl;

    for (int i = 0;i < 5;++i) {
        cout << " , "<<ttbar[i];
    }

    cout << endl;

    return 0;
}