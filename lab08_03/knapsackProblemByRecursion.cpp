#include "knapsackProblemByRecursion.h"

using namespace std;

void showResultsOnScreen()
{
	fstream inFile = createInputFile();

	//pomocnicze zmienne
	int numberOfDataSets{};
	int capacityOfKnapsack{}, numberOfItems{};
	int *weightsOfItems{}, *resTab;

	inFile >> numberOfDataSets;

	for (int i = 0; i < numberOfDataSets; i++)
	{
		inFile >> capacityOfKnapsack >> numberOfItems;

		weightsOfItems = new int[numberOfItems];
		resTab = new int[numberOfItems];

		for (int j = 0; j < numberOfItems; j++)
		{
			inFile >> weightsOfItems[j];
		}

		cout << rekurencja(weightsOfItems, numberOfItems, capacityOfKnapsack) << endl;

		delete[] weightsOfItems;
		delete[] resTab;
	}

}

int rekurencja(int *weightsOfItems, int sizeOfTOW, int maxCapacity, int sumOfElem, int begIterator, int midIterator, int endIterator)
{
	if (sumOfElem == maxCapacity)
		return 1;
	else if (begIterator == sizeOfTOW)
	{
		return -1;
	}

	if (sumOfElem > maxCapacity)
	{
	
		if (midIterator == sizeOfTOW)
		{
		begIterator++;

		sumOfElem = 0;
		midIterator = 1;
		endIterator = begIterator;

		return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		if (endIterator < sizeOfTOW)
		{
		sumOfElem -= weightsOfItems[endIterator - 1];
		sumOfElem += weightsOfItems[endIterator];
		endIterator++;

		return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)
		{
		sumOfElem = 0;
		sumOfElem += weightsOfItems[begIterator];

		midIterator++;
		endIterator = endIterator - sizeOfTOW + midIterator;

		return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}


	}

	if (sumOfElem < maxCapacity)
	{
		if (midIterator == sizeOfTOW)
		{
			begIterator++;

			sumOfElem = 0;
			midIterator = 1;
			endIterator = begIterator;

			return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		if (endIterator < sizeOfTOW) {
			sumOfElem += weightsOfItems[endIterator];
			endIterator++;


			return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)
		{
			sumOfElem = 0;
			sumOfElem += weightsOfItems[begIterator];

			midIterator++;
			endIterator = endIterator - sizeOfTOW + midIterator;

			return rekurencja(weightsOfItems, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
	}


}

