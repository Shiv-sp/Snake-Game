#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food
{

private:
    objPos foodPos;
    GameMechs *mainGameMechsRef;

public:
    Food(GameMechs *gameRef, objPosArrayList *playerPosList); // default
    // omitted the destructor as no heap memory is used

    void generateFood(objPosArrayList *blockOff);

    bool checkSelfCollision(objPosArrayList *playerPosList);

    objPos const getFoodPos();
};

#endif