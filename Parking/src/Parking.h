/**
 * @file
 * @brief Заголовочный файл с объявлением класса Parking
 */


#ifndef PARKING_PARKING_H
#define PARKING_PARKING_H


#include "DataBase.h"
#include "RegNumber.h"
#include "SizeOfCar.h"


/**
 * @brief Класс, представляющий автоматизированный доступ на парковку;
 */ 
class Parking
{
public:
    /**
     * @brief Конструктор
     * @param[in] db Указатель на объект, реализующий интерфейс DataBase
     * @param[in] rn Указатель на объект, реализующий интерфейс RegNumber
     * @param[in] sk Указатель на объект, реализующий интерфейс SizeOfCar
     * @par Returns
     * Nothing
     */
    Parking(DataBase *db, RegNumber *rn, SizeOfCar *sk);

    /**
     * @brief Инициирует процесс открытия ворот
     * @retval true Ворота открываются
     * @retval false Поищите другую парковку
     */
    bool GatesOpen();
private:
    DataBase* _db;
    RegNumber* _rn;
    SizeOfCar*  _sc;
    const double maxLenght = 4.80;
    const double maxWidth = 1.90;
};


#endif //PARKING_PARKING_H
