// compilation:
// g++ track.cpp -o track.exe
// ./track.exe

#include <cmath>
#include <iostream>
#include <ostream>


using namespace std;

class Track {
    private:
    double px,py,pz,eta;

    public:
    Track(double px,double py, double pz,double eta) : px(px),py(py),pz(pz),eta(eta) {}

    double getTransverseMomentum() const {
        double P_t = sqrt(pow(px,2)+pow(py,2));
        return P_t;
    } 

    double getPseudorapidity() const {
        double P_size = sqrt(pow(px,2)+pow(py,2)+pow(pz,2));
        double Eta = - log(tan(acos(pz/P_size)));
        return Eta;
    }

};

class SimulatedTrack : public Track{
    private:
    int particleId;
    int parentParticleId;

    public:
    SimulatedTrack(double px,double py, double pz,double eta,int particleId, int parentParticleId) 
    : Track(px, py, pz, eta), particleId(particleId),parentParticleId(parentParticleId) {}

    int getParticleId() {
        return particleId;
    }

    int getParentParticleId(){
        return parentParticleId;
    }
};

int main(int argc, char* argv[])
{
    Track track(1.0, 2.0, 3.0, 4.0);
    cout << "P_t = " << track.getTransverseMomentum() << endl;
    cout << "Eta = " << track.getPseudorapidity() << endl;
    cout << endl;
    SimulatedTrack simTrack(5.0, 6.0, 7.0, 8.0, 10101, 10100);
    cout << "P_t = " << simTrack.getTransverseMomentum() << endl;
    cout << "Eta = " << simTrack.getPseudorapidity() << endl;
    cout << "Particle Id = " << simTrack.getParticleId() << endl;
    cout << "Perent Particle Id = " << simTrack.getParentParticleId() << endl;
    return 0;
}
