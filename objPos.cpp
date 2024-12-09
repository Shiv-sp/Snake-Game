#include "objPos.h"
#include <cstddef>

// Default constructor: Initializes position to (0, 0) and symbol to null
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; // NULL
}

// Initializes position and symbol with given values
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule
// Destructor
objPos::~objPos()
{
    delete pos; // deallocation
}

// Copy Constructor
objPos::objPos(const objPos &reference)
{
    this->symbol = reference.symbol;
    this->pos = new Pos;
    pos->x = reference.pos->x;
    pos->y = reference.pos->y;
}

// Copy Assignment Operator
objPos &objPos::operator=(const objPos &reference)
{

    if (this != &reference)
    {
        this->symbol = reference.symbol;
        pos->x = reference.pos->x;
        pos->y = reference.pos->y;
    }
    return *this;
}

bool objPos::operator==(const objPos &other)
{
    return this->pos->x == other.pos->x &&
           this->pos->y == other.pos->y;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// setting object position with what is given
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// returning the object position
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;

    return returnPos;
}

// retriving the symbol
char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos *refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos *refPos) const
{
    if (isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

// self-explanatory below
void objPos::xPosIncrease()
{
    (pos->x)++;
}

void objPos::xPosDecrease()
{
    (pos->x)--;
}
void objPos::yPosIncrease()
{
    (pos->y)++;
}
void objPos::yPosDecrease()
{
    (pos->y)--;
}