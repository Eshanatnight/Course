#include "Fibornacci.h"


int fibornacci::fibornacciMemorize(int numberCheck)
{
    if(numberCheck == 0)
        return 0;

    if (numberCheck == 1)
        return 1;

    if(memorizeTable[numberCheck] != 0)
        return memorizeTable[numberCheck];

    else
    {
        memorizeTable[numberCheck] = fibornacciMemorize(numberCheck - 1) + fibornacciMemorize(numberCheck - 2);
        return memorizeTable[numberCheck];
    }
}

fibornacci::fibornacci()
    {
        memorizeTable.resize(100);
        memorizeTable[0] = 0;
        memorizeTable[1] = 1;
    }
