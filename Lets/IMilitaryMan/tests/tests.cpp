#include <gmock/gmock.h>


#include "../src/Officer.h"
#include "../src/Soldier.h"


TEST(IMilitaryMan, test_soldier)
{
    Soldier soldier;
    IMilitaryMan &militaryMan = soldier;
    militaryMan.Serve();

    EXPECT_EQ(soldier.getServe(), 1);
}

TEST(IMilitaryMan, five_soldiers_two_officer)
 {
    Soldier *firstSoldier = new Soldier;
    Soldier *secondSoldier = new Soldier;
    Soldier *thirdSoldier = new Soldier;
    Soldier *fourthSoldier = new Soldier;
    Soldier *fifthSoldier = new Soldier;

    IMilitaryMan *firstSubordinates[2]={firstSoldier,secondSoldier};
    Officer *firstOfficer = new Officer(firstSubordinates,2);

    IMilitaryMan *secondSubordinates[4]={thirdSoldier, fourthSoldier, 
    fifthSoldier,firstOfficer};
    Officer *secondOfficer = new Officer(secondSubordinates, 4);

    secondOfficer->Serve();

    EXPECT_EQ(firstSoldier->getServe(),1);
    EXPECT_EQ(secondSoldier->getServe(),1);
    EXPECT_EQ(thirdSoldier->getServe(),1);
    EXPECT_EQ(fourthSoldier->getServe(),1);
    EXPECT_EQ(fifthSoldier->getServe(),1);
    delete secondOfficer;
    
}

TEST(IMilitaryMan, destructors)
{
    IMilitaryMan *firstSubordinates[5]={new Soldier,
    new Soldier,new Soldier,new Soldier,new Soldier};
    Officer *firstOfficer = new Officer(firstSubordinates, 5);
    delete firstOfficer;
    EXPECT_EQ(countDestructors, 0);
}
