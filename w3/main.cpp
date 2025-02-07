#include <iostream>
#include "Met.h"

using namespace std;

int main()
{
    Met energy(3.0, 4.0);
    

    cout << "MET X: " << energy.getX() << endl;
    cout << "MET Y: " << energy.getY() << endl;
    cout << "MET Value: " << energy.getValue() << endl;
    cout << "MET Phi: " << energy.getPhi() << endl;

    return 0;
}