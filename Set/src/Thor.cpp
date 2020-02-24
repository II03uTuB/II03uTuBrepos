#include "Thor.h"


Thor::Thor() : _externalRadius(0), 
               _internalRadius(0),
               _thickness(0)
{
    
};

Thor::Thor(double externalRadius, double internalRadius, double thickness)
{
    if(externalRadius > 0 && internalRadius > 0 && thickness > 0)
    {
        _externalRadius = externalRadius;
        _internalRadius = internalRadius;
        _thickness = thickness;
    }
    else
    {
        throw ErrorMake();
    }
};

double Thor::getExternalRadius() const
{
    return _externalRadius;
};

double Thor::getInternalRadius() const
{
    return _internalRadius;
};

double Thor::getThickness() const
{
    return _thickness;
};

double Thor::getVolume() const
{
    return 2 * pow(M_PI, 2) * _externalRadius * pow(_internalRadius, 2);
};

double Thor::getArea() const
{
    return 4 * pow(M_PI, 2) * _externalRadius * _internalRadius;
};

bool Thor::openThor() const
{
    if(((_externalRadius + _internalRadius) * 0.5) > _thickness)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool Thor::closeThor() const
{
    if(((_externalRadius + _internalRadius) * 0.5) <= _thickness)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Thor::operator==(Thor &anotherThor) const
{
    if(_externalRadius == anotherThor.getExternalRadius() &&
       _internalRadius == anotherThor.getInternalRadius() &&
       _thickness == anotherThor.getThickness())
    {
        return true;
    }
    else
    {
        return false;
    }
};
