#ifndef Met_h
#define Met_h

class Met
{
private:
    double met_x;
    double met_y;

public:
    Met(double x, double y);

    double getX() const;
    double getY() const;
    double getValue() const;
    double getPhi() const;
};
#endif