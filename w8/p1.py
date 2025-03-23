import pythia8

pythia = pythia8.Pythia()
# default collison energy: 14 TeV
# enable hb production, gluon -> hb
pythia.readString("HiggsSM:all = on")
# taking only sm hb
pythia.readString("Higgs:useBSM = off")  
pythia.init()

# PDG ID for hb = 25
higgs_data = pythia.particleData.mWidth(25)

print(f"SM Higgs boson width for m_H = 125 GeV is {higgs_data:.6f} GeV")
# 0.004083428388965407 GeV