#ifndef IMILITARYMAN_IMILITARYMAN_H
#define IMILITARYMAN_IMILITARYMAN_H


extern unsigned int countDestructors;


class IMilitaryMan
{
public:
    virtual void Serve()= 0;
    virtual ~IMilitaryMan() {};
};


#endif //IMILITARYMAN_IMILITARYMAN_H
