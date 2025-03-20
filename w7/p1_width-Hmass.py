import ROOT
import numpy as np
import pandas as pd

# for 125 GeV the width is 0.4077E-02 GeV

# Read data from br.sm2 output by HDECAY
df = pd.read_csv("br.sm2",sep="\s+", comment="_", skiprows=2,names=["MHSM", "GG", "GAM", "GAMZ", "WW", "ZZ", "WIDTH"])

# higgs mass and width
masses = df['MHSM'].values
widths = df['WIDTH'].values

# ROOT graph
graph = ROOT.TGraph(len(masses), masses, widths)
graph.SetTitle("Higgs Boson Decay Width;Mass (GeV);Width (GeV)")
graph.SetLineColor(ROOT.kBlue)
graph.SetLineWidth(2)

# make plot
canvas = ROOT.TCanvas("canvas", "Higgs Width", 800, 600)
graph.Draw("AL")
canvas.SaveAs("higgs_width.png")

