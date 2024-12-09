
#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
private:
    char input;
    bool exitFlag;
    bool loseFlag;
    int score;

    int boardSizeX;
    int boardSizeY;

    objPos food;

public:
    GameMechs();
    GameMechs(int boardX, int boardY);
    // omitted the destructor as no heap memory is used here

    bool getExitFlagStatus() const;
    void setExitTrue();
    bool getLoseFlagStatus() const;
    void setLoseFlag();

    char getInput() const;
    void setInput(char this_input);
    void clearInput();

    int getBoardSizeX() const;
    int getBoardSizeY() const;

    int getScore() const;
    void incrementScore();
};

#endif
