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
	//dokonczyc z resTab

	if (sumOfElem == maxCapacity)
		return true;
	else if (begIterator == sizeOfTOW)
	{
		return false;
	}

	if (sumOfElem > maxCapacity)
	{
	
		if (midIterator == sizeOfTOW)
		{
		begIterator++;

		resVec.clear();
		sumOfElem = 0;
		midIterator = 1;
		endIterator = begIterator;

		return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		if (endIterator < sizeOfTOW)
		{
		sumOfElem -= weightsOfItems[endIterator - 1];
		sumOfElem += weightsOfItems[endIterator];

		resVec.pop_back();
		resVec.push_back(weightsOfItems[endIterator]);

		endIterator++;

		return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)
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

	if (sumOfElem < maxCapacity)
	{
		if (midIterator == sizeOfTOW)
		{
			begIterator++;

			resVec.clear();
			sumOfElem = 0;
			midIterator = 1;
			endIterator = begIterator;

			return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}

		if (endIterator < sizeOfTOW) {
			sumOfElem += weightsOfItems[endIterator];
			resVec.push_back(weightsOfItems[endIterator]);

			endIterator++;

			return isCapacityOfKnapsackEnough(weightsOfItems, resVec, sizeOfTOW, maxCapacity, sumOfElem, begIterator, midIterator, endIterator);
		}
		else if (endIterator == sizeOfTOW)
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

