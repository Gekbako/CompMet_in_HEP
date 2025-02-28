import ROOT
from ROOT import TFile,TTree,TRandom3,TH1F,TCanvas,AddressOf
import sys
import numpy as np

def gen_data():
    datafname = "data_py.root"
    file = TFile(datafname, "RECREATE")
    tree = TTree("tree", "Tree with normally distributed data")

    # branch of a tree
    value = np.array([0.],dtype=np.float64)
    tree.Branch("value", value, "value/D")
    randGen = TRandom3(42)

    # generate 1000 normal dist. numbers
    for i in range(1000):
        value[0] = randGen.Gaus(0, 1)
        tree.Fill()

    tree.Write()
    file.Close()

    print("Data written to file: ",datafname)

def plot_data():
    fname = "data_py.root"
    figname = "histogram_py.png"
    file = TFile(fname, "READ")
    
    # read tree
    tree = file.Get("tree")
    if ( not tree) :
        sys.exit(f"Error: Tree not found in: {fname}")
        
    # histogram
    hist = TH1F("hist", "Normal distribution of 1000 random variables", 50, -4, 4)

    value = np.array([0.],dtype=np.float64)
    tree.SetBranchAddress("value",value)
    # pass data to hist
    for i in range(0,tree.GetEntries()) :
        tree.GetEntry(i)
        hist.Fill(value[0])

    hist.SetLineColor(ROOT.kBlack) 
    hist.SetLineWidth(5)      
    hist.SetFillColor(ROOT.kYellow)
    hist.SetStats(0)   

    hist.GetXaxis().SetTitle("value x")
    hist.GetXaxis().CenterTitle(True)
    hist.GetYaxis().SetTitle("count N")
    hist.GetYaxis().CenterTitle(True)
    
    c1 = TCanvas("c1", "Canvas", 800, 600)
    c1.SetFillColor(ROOT.kWhite)
    
    hist.Fit("gaus","S")
    hist.Draw()
    
    c1.SaveAs(figname)
    print("Histogram saved in file: ",figname)
    
    c1.Close()
    del hist
    file.Close()
    del c1
    del file

if __name__=="__main__":
    gen_data()
    plot_data()