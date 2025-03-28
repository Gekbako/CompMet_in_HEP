import pythia8
import ROOT

pythia = pythia8.Pythia()
pythia.readString("Print:quiet = on")
# energy of 13.6 TeV
pythia.readString("Beams:eCM = 13600.")
# minimum bias events
pythia.readString("SoftQCD:inelastic = on")
pythia.init()

# histograms
h_pT = ROOT.TH1F("h_pT", "Muon Transverse Momentum Distribution; p_{T} (GeV/c); Entries", 50, -2.5, 10)
h_eta = ROOT.TH1F("h_eta", "Muon Pseudo-rapidity Distribution; #eta; Entries", 50, -10, 10)

n_muons = 0
n_suit_muons = 0
# generate events
n_events = 10000
for _ in range(n_events):
    if not pythia.next():
        continue

    for i in range(pythia.event.size()):
        particle = pythia.event[i]
        # Muon PDG: 13
        if abs(particle.id()) == 13:
            pT = particle.pT()
            eta = particle.eta()
            h_pT.Fill(pT)
            h_eta.Fill(eta)
            n_muons+=1

            # EXE 2 -> check for suitable muons
            if pT > 5. and abs(eta) < 2.5:
                n_suit_muons += 1

# probability of detecting 
p = n_suit_muons/n_muons

print(f"Feasible muons: {n_suit_muons}, detected muons: {n_muons}")
print(f"Proability of detecting a suitable muon from a min bias even: {p:.3f} -> {p*100:.1f}%\n")
# P(pT>5GeV/c and |eta|<2.5) = 0.4%

# create plot
canvas = ROOT.TCanvas("canvas", "Muon Distributions", 800, 600)
canvas.Divide(2, 1)

# pT dist
canvas.cd(1)
h_pT.SetLineColor(ROOT.kBlue)
h_pT.SetLineWidth(2)
h_pT.Draw()

# eta dist
canvas.cd(2)
h_eta.SetLineColor(ROOT.kRed)
h_eta.SetLineWidth(2)
h_eta.Draw()

canvas.Update()
canvas.Draw()

canvas.SaveAs("exe1_plot.png")

canvas.Close()
del h_pT
del h_eta
del canvas
