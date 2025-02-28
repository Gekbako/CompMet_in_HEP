#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>


using namespace std;

void gen_data()
{
    char datafname[20] = "data.root";
    TFile *file = new TFile(datafname, "RECREATE");

    TTree *tree = new TTree("tree", "Tree with normally distributed data");

    double value;

    // branch of a tree
    tree->Branch("value", &value, "value/D");

    TRandom3 randGen(42);

    // generate 1000 normal dist. numbers
    for (int i = 0; i < 1000; i++) {
        value = randGen.Gaus(0, 1);
        tree->Fill();
    }

    tree->Write();
    file->Close();
    
    cout << "Data written to file: "<<datafname<<endl;
}
