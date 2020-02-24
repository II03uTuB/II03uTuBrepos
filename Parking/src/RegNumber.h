#ifndef PARKING_REGNUMBER_H
#define PARKING_REGNUMBER_H 


/**
 * @brief Класс, являющийся сканером номера автомобиля
 */

class RegNumber
{
public:
    virtual unsigned int scanNumber() const = 0;
};


#endif //PARKING_REGNUMBER_H
