#ifndef PARKING_DATABASE_H
#define PARKING_DATABASE_H


/**
 * @brief Класс-база данных, в котором содержится 
 * номер автомобиля, который может заезжать на парковку 
 */


class DataBase
{
public:
    virtual bool trueNumber(unsigned int) const = 0;
};


#endif //PARKING_DATABASE_H
