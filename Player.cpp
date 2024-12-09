#include "Player.h"
// #include "MacUILib.h"
// #include <iostream>

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    objPos start1 = objPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');

    playerPosList->insertTail(start1);
}

Player::~Player()
{
    delete playerPosList;
}

objPosArrayList *Player::getPlayerPos() const
{
    // return the reference to the playerPosList arrray list
    return this->playerPosList;
}

// FSM logic from PPA3
void Player::updatePlayerDir()
{

    if (mainGameMechsRef->getInput() != 0)
    {
        switch (mainGameMechsRef->getInput())
        {
            {
            case 27:
                mainGameMechsRef->setExitTrue();
                break;

            case 'w':
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 'a':
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case 's':
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            case 'd':
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            case 'W':
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

            case 'A':
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;

            case 'S':
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            case 'D':
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
            }
            mainGameMechsRef->setInput(0);
        }
    }
}

// Player movement
void Player::movePlayer()
{
    // PPA3 FSM logic
    objPos snakeHead = playerPosList->getHeadElement();

    switch (myDir)
    {
    case LEFT:
        if (snakeHead.pos->x <= 0)
        {
            snakeHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        snakeHead.pos->x--;
        break;

    case RIGHT:
        if (snakeHead.pos->x == mainGameMechsRef->getBoardSizeX() - 2)
        {
            snakeHead.pos->x = 0;
        }
        snakeHead.pos->x++;
        break;

    case UP:
        if (snakeHead.pos->y <= 0)
        {
            snakeHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
        snakeHead.pos->y--;
        break;

    case DOWN:
        if (snakeHead.pos->y == mainGameMechsRef->getBoardSizeY() - 2)
        {
            snakeHead.pos->y = 0;
        }
        snakeHead.pos->y++;
        break;

    case STOP:
        break;
    }

    if (snakeHead.pos->x <= 0)
    {
        snakeHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
    }
    else if (snakeHead.pos->x >= mainGameMechsRef->getBoardSizeX() - 1)
    {
        snakeHead.pos->x = 1;
    }

    if (snakeHead.pos->y <= 0)
    {
        snakeHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
    }
    else if (snakeHead.pos->y >= mainGameMechsRef->getBoardSizeY() - 1)
    {
        snakeHead.pos->y = 1;
    }
    playerPosList->insertHead(snakeHead);
    playerPosList->removeTail();

    int i;

    for (i = 1; i < playerPosList->getSize(); i++)
    {
        if (playerPosList->getHeadElement() == playerPosList->getElement(i))
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }
}

// More methods to be added

bool Player::checkFoodConsumption(Food *foodItem)
{
    return playerPosList->getElement(0) == foodItem->getFoodPos();
}

// Increasing elngth after having a food item
void Player::increasePlayerLength(Food *foodItem)
{
    objPos currentHead = playerPosList->getHeadElement();

    objPos snakeHead = currentHead;

    snakeHead.symbol = '*';

    playerPosList->insertHead(snakeHead);
    mainGameMechsRef->incrementScore();
}