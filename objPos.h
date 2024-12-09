#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct
{
    int x;
    int y;
} Pos;

class objPos
{
public:
    Pos *pos;
    char symbol;

    objPos();
    objPos(int xPos, int yPos, char sym);

    // Respect the rule of six / minimum four
    // [TODO] Implement the missing special member functions to meet the minimum four rule

    ~objPos(); // Destrcutor

    // Copy Constructor
    objPos(const objPos &reference);

    // Copy Assignemnt Operator
    objPos &operator=(const objPos &reference);

    bool operator==(const objPos &other);

    void setObjPos(objPos o);
    void setObjPos(int xPos, int yPos, char sym);

    objPos getObjPos() const;
    char getSymbol() const;
    char getSymbolIfPosEqual(const objPos *refPos) const;

    bool isPosEqual(const objPos *refPos) const;

    void xPosIncrease();
    void xPosDecrease();
    void yPosIncrease();
    void yPosDecrease();
};

#endif