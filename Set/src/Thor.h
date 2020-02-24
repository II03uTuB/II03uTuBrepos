#ifndef SET_THOR_H
#define SET_THOR_H


#include <cmath>


#include "Exceptions.h"


class Thor
{
public:
    Thor();
    Thor(double externalRadius, double internalRadius, double thickness);
    double getExternalRadius() const;
    double getInternalRadius() const;
    double getThickness() const;
    double getVolume() const;
    double getArea() const;
    bool openThor() const;
    bool closeThor() const;
    bool operator==(Thor &anotherThor) const;

private:
    double _externalRadius;
    double _internalRadius;
    double _thickness;
};

#endif //SET_THOR_H
