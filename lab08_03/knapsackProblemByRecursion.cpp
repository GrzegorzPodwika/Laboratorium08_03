#include "knapsackProblemByRecursion.h"

using namespace std;

void manageAndShowResultsOnScreen()
{
	fstream inFile = createInputFile();

	//pomocnicze zmienne
	int numberOfDataSets{};
	int capacityOfKnapsack{}, numberOfItems{};
	int *weightsOfItems{};
	vector <int> resVec;

	try
	{
		inFile >> numberOfDataSets;
		if (numberOfDataSets < 0)
			throw EXCEPTION_CODE::notNaturalNumber;
	}
	catch (EXCEPTION_CODE error)
	{
		seeExceptions(error);
		exit(0);
	}


	for (int i = 0; i < numberOfDataSets; i++)
	{
		try
		{
			inFile >> capacityOfKnapsack >> numberOfItems;
			if (capacityOfKnapsack < 0 || numberOfItems < 0)
				throw EXCEPTION_CODE::notNaturalNumber;
		}
		catch (EXCEPTION_CODE error)
		{
			seeExceptions(error);
			exit(0);
		}

		weightsOfItems = new int[numberOfItems];

		for (int j = 0; j < numberOfItems; j++)
		{
			try
			{
				inFile >> weightsOfItems[j];
				if (weightsOfItems[j])
					throw EXCEPTION_CODE::notNaturalNumber;
			}
			catch (EXCEPTION_CODE error)
			{
				seeExceptions(error);
				exit(0);
			}
		}

		if (isCapacityOfKnapsackEnough(weightsOfItems, resVec, numberOfItems, capacityOfKnapsack))
		{
			cout << capacityOfKnapsack << " = ";
			for (int x : resVec)
			{
				cout << x << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "BRAK" << endl;
		}

		resVec.clear();
		delete[] weightsOfItems;
	}

}

bool isCapacityOfKnapsackEnough(int *weightsOfItems, vector <int> &resVec, int sizeOfTOW, int maxCapacity, int sumOfElem, int begIterator, int midIterator, int endIterator)
{
	//warunki zerowe, jesli suma elementow = maxCapacity, program zwraca true, jesli begIterator = rozmiar tablicy wag, czyli wszystkie kombinacje zostaly wykorzystane i nie ma rozwiazania, zwracamy false
	if (sumOfElem == maxCapacity)
		return true;
	else if (begIterator == sizeOfTOW)
	{
		return false;
	}

	if (sumOfElem > maxCapacity)		//np. 25 > const 20
	{
		//jesli srodkowy iterator = rozmiar tablicy wag, czyli zostalo wykorzystane dla danego elementu x wszystkie kombinacje, przeskakujemy do nastepnego elementu begIteratorem x+1
		if (midIterator == sizeOfTOW)
		{
		begIterator++;

		resVec.clear();
		sumOfElem = 0;
		midIterator = 1;
		endIterator = begIterator;

		return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		//jesli endIterator sluzacy do poruszania sie po elementach jest mniejszy od rozmiaru tablicy wag
		if (endIterator < sizeOfTOW)
		{
		sumOfElem -= weightsOfItems[endIterator - 1];
		sumOfElem += weightsOfItems[endIterator];

		resVec.pop_back();
		resVec.push_back(weightsOfItems[endIterator]);

		endIterator++;

		return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)		// jesli endIterator = rozmiar tablicy wag wtedy 11+8+5>20 => 11+6+5 itd. 
		{
		sumOfElem = 0;
		sumOfElem += weightsOfItems[begIterator];

		resVec.clear();
		resVec.push_back(weightsOfItems[begIterator]);

		midIterator++;
		endIterator = endIterator - sizeOfTOW + midIterator;

		return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}


	}

	if (sumOfElem < maxCapacity)		//np. 18 > const 20
	{
		//jesli srodkowy iterator = rozmiar tablicy wag, czyli zostalo wykorzystane dla danego elementu x wszystkie kombinacje, przeskakujemy do nastepnego elementu begIteratorem x+1
		if (midIterator == sizeOfTOW)
		{
			begIterator++;

			resVec.clear();
			sumOfElem = 0;
			midIterator = 1;
			endIterator = begIterator;

			return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		//jesli endIterator sluzacy do poruszania sie po elementach jest mniejszy od rozmiaru tablicy wag
		if (endIterator < sizeOfTOW) {
			sumOfElem += weightsOfItems[endIterator];
			resVec.push_back(weightsOfItems[endIterator]);

			endIterator++;

			return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)		// jesli endIterator = rozmiar tablicy wag wtedy 11+8+5>20 => 11+6+5 itd. 
		{
			sumOfElem = 0;
			sumOfElem += weightsOfItems[begIterator];

			resVec.clear();
			resVec.push_back(weightsOfItems[begIterator]);

			midIterator++;
			endIterator = endIterator - sizeOfTOW + midIterator;

			return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
	}


}

