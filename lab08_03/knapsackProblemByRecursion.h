#ifndef KNAPSACKPROBLEMBYRECURSION_H
#define KNAPSACKPROBLEMBYRECURSION_H

#include "libFiles.h"
#include <iostream>

void showResultsOnScreen();

int rekurencja(int *weightsOfItems, int sizeOfTOW, int maxCapacity, int sumOfElem = 0, int begIterator = 0, int midIterator = 1, int endIterator = 0);



#endif // !KNAPSACKPROBLEMBYRECURSION_H

