import pythia8
import ROOT

pythia = pythia8.Pythia()
# default collison energy: 14 TeV
pythia.readString("Print:quiet = on")
# enable hb production, gluon -> hb
pythia.readString("HiggsSM:gg2H = on")  
# CTEQ6L1 -> option 8 in PDFs
pythia.readString("PDF:pSet = 8")

pythia.init()


# ROOT histogram
hist = ROOT.TH1F("Higgs_Mass", "Higgs Mass Distribution", 100, 124.8, 125.2)


# get 1000 generations
for i in range(1000):
    if not pythia.next():
        continue
    for particle in pythia.event:
        # PDG ID for hb = 25
        if particle.id() == 25:  
            hist.Fill(particle.m())
            break

# fit hist with Breit-Wigner
bw_func = ROOT.TF1("bw_func", "[0]*TMath::BreitWigner(x, [1], [2])", 124.8, 125.2)
# init guess: norm=100, mean=125 GeV, width=3 MeV
bw_func.SetParameters(100, 125, 0.003)  

# fit BW func in range
hist.Fit(bw_func, "R")  
hist.SetXTitle("Higgs Mass [GeV]")
hist.SetYTitle("Count")

# get BW width
higgs_width = bw_func.GetParameter(2)
print(f"\n########\nExtracted Higgs Width from Fit: {higgs_width:.6f} GeV\n########\n")

# draw hist
c1 = ROOT.TCanvas("c1", "Higgs Mass", 800, 600)
hist.Draw()
bw_func.Draw("same")
c1.SaveAs("hist.png")

pythia.stat()
