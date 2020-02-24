#ifndef IMILITARYMAN_SOLDIER_H
#define IMILITARYMAN_SOLDIER_H


#include "IMilitaryMan.h"



class Soldier : public IMilitaryMan 
{
public:
    Soldier();
    ~Soldier() override;
    void Serve() override;
    unsigned int getServe();
private:
    unsigned int _jobCount;
};


#endif //IMILITARYMAN_SOLDIER_H
