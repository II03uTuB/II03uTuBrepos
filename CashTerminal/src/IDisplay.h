#ifndef CASHTERMINAL_IDISPLAY_H
#define CASHTERMINAL_IDISPLAY_H


class IDisplay
{
public:
    virtual void PrintMenu() = 0;
    virtual void PrintBalance(unsigned cardId) = 0;
    virtual void PrintMessage(const char* message) = 0;
};


#endif//CASHTERMINAL_IDISPLAY_H
