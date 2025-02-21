#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

using namespace std;

int main(int argc, char* argv[])
{
    char fname[20] = "data.root";
    char figname[30] = "histogram.png";

    TFile *file = new TFile(fname, "READ");

    // read tree
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        cerr << "Error: Tree not found in: " << fname << endl;
        return 1;
    }

    // histogram
    TH1F *hist = new TH1F("hist", "Normal distribution of 1000 random variables", 50, -4, 4);

    double value;
    tree->SetBranchAddress("value", &value);
    Long64_t entries = tree->GetEntries();

    // pass data to hist
    for (Long64_t i = 0; i < entries; ++i) {
        tree->GetEntry(i);
        hist->Fill(value);
    }

    hist->SetLineColor(kBlack); 
    hist->SetLineWidth(3);      
    hist->SetFillColor(kYellow);
    hist->SetStats(0);   

    hist->GetXaxis()->SetTitle("value x");
    hist->GetXaxis()->CenterTitle(true);
    hist->GetYaxis()->SetTitle("count N");
    hist->GetYaxis()->CenterTitle(true);       

    TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);

    c1->SetFillColor(kWhite);

    hist->Draw("HIST");

    hist->Fit("gaus");

    hist->Draw("SAME");

    c1->SaveAs(figname);
    cout << "Histogram saved in file: " << figname << endl;

    file->Close();
    delete hist;
    delete c1;

    return 0;
}
