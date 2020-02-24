#ifndef IMILITARYMAN_OFFICER_H
#define IMILITARYMAN_OFFICER_H


#include "IMilitaryMan.h"
#include "Soldier.h"


class Officer : public IMilitaryMan
{
public:
    Officer(IMilitaryMan **subordinates, unsigned int count);
    void Serve() override;
    ~Officer() override;

private:
    IMilitaryMan **_subordinates;
    unsigned int _count;
};


#endif //IMILITARYMAN_OFFICER_H
