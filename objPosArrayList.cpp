
#include "objPosArrayList.h"
#include <stdexcept>

// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.

// default constructor (intialized to 0)
objPosArrayList::objPosArrayList()
{
    int i;
    arraySize = ARRAY_MAX_CAP;
    aList = new objPos[arraySize];
    listSize = 0;

    for (i = 0; i < arraySize; i++)
    {
        (*(aList + i)->pos).x = 0;
        (*(aList + i)->pos).y = 0;
        (aList + i)->symbol = 0;
    }
}
// copy constructor
objPosArrayList::objPosArrayList(const objPosArrayList &other)
{
    int i;

    listSize = other.listSize;
    arraySize = other.arraySize;
    aList = new objPos[arraySize];

    for (i = 0; i < listSize; i++)
    {
        *(aList + i) = other.aList[i];
    }
}

// copy assignment operator
objPosArrayList &objPosArrayList::operator=(const objPosArrayList &other)
{
    int i;

    if (this != &other)
    {
        listSize = other.listSize;
        arraySize = other.arraySize;

        for (i = 0; i < listSize; i++)
        {
            aList[i] = other.aList[i];
        }
    }
    return *this;
}

// doubling the size of array if the list is bigger than the array
void objPosArrayList::doubleSize()
{
    int i;

    arraySize *= 2;
    objPos *newArr = new objPos[arraySize];
    for (i = 0; i < listSize; i++)
    {
        *(newArr + i) = *(aList + i);
    }
    delete[] aList;

    aList = newArr;
    delete[] newArr;
}

// destructor is neccessary
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    int i;

    if (listSize == arraySize)
    {
        doubleSize();
    }

    for (i = listSize; i > 0; i--)
    {
        *(aList + i) = *(aList + i - 1);
    }
    *aList = thisPos;

    listSize++; // increasing since we are adding element
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arraySize)
    {
        doubleSize();
    }
    *(aList + listSize) = thisPos;

    listSize++; // increasing since we are adding element
}

void objPosArrayList::removeHead()
{
    int i;

    if (listSize > 0)
    {
        for (i = 0; i < listSize; i++)
        {
            *(aList + i) = *(aList + i + 1);
        }
        listSize--; // decreasing since we are removing element
    }
    else
    {
    }
}

void objPosArrayList::removeTail()
{
    if (listSize == 0)
    {
    }
    else
    {
        listSize--; // decreasing since we are removing element
    }
}

// self explanatory
objPos objPosArrayList::getHeadElement() const
{
    return *(aList);
}

objPos objPosArrayList::getTailElement() const
{
    return *(aList + listSize - 1);
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0 || index >= arraySize)
    {
        ;
    }
    return *(aList + index); // returning the value asked for
}
