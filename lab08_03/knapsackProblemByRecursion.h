#ifndef KNAPSACKPROBLEMBYRECURSION_H
#define KNAPSACKPROBLEMBYRECURSION_H

#include "libFiles.h"
#include "libExceptions.h"
#include <iostream>
#include <vector>

/*
Glowna funkcja zarzadzajaca i pokazujaca wyniki na ekran
*/
void manageAndShowResultsOnScreen();

/*
Funkcja rekurencyjna obliczajaca czy na dana pojemnosc plecaka zmieszcza sie poszczegolne rzeczy
@param weightsOfItems wagi p9oszczegolnych rzeczy pobranych z pliku tekstowego
@param resVec wektor wynikowych wartosci, jesli upakowanie sie powiedzie
@param sizeOfTOW rozmiar tablicy weightsOfItems
@param maxCapacity maksymalnma pojemnosc danego plecaka
@param sumOfElem suma elementow potrzebna do obliczen, domyslnie startowo = 0
@param begIterator iterator wskazujacy na poczatek tablicy weightsOfItems, potrzebny do obliczen, startowo = 0
@param midIterator iterator srodkowy na tablice weightsOfItems, potrzebny do obliczen, startowo = 1
@param endIterator iterator przemieszczajacy sie po poszczegolnych elementach do koncowego elementu, potrzebny do obliczen, startowo = 0
@return true jesli mozna dokladnie upakowac plecak z poszczegolnych rzeczy, czyli maja mase maxCapacity. False w przeciwnym wypadku
*/
bool isCapacityOfKnapsackEnough(int *weightsOfItems, std::vector <int> &resVec, int sizeOfTOW, int maxCapacity, int sumOfElem = 0, int begIterator = 0, int midIterator = 1, int endIterator = 0);



#endif // !KNAPSACKPROBLEMBYRECURSION_H

