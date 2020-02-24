#ifndef PARKING_SIZEOFCAR_H
#define PARKING_SIZEOFCAR_H


/**
 * @brief Класс-сканер, который определяет габариты
 * (длину,ширину) автомобиля, заехавшего на платформу;
 */

class SizeOfCar
{
public:
    virtual double scanLenght() const = 0;
    virtual double scanWidth() const = 0;
};


#endif //PARKING_SIZEOFCAR_H
