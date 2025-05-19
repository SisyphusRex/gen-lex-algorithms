#include <stdio.h>
#include <ui.h>

void GeneratePermutations(int numberOfElements)
{
    // Produce all permutations of set size equal to input
    int permutationSet[numberOfElements];
    int stopSet[numberOfElements];
    InitializeSet(permutationSet, numberOfElements);
    InitializeStopSet(stopSet, numberOfElements);
    PrintIntegerArray(permutationSet, numberOfElements);
    while (CompareArrays(permutationSet, stopSet, numberOfElements) == 1)
    {
    }
}

void InitializeSet(int permutationSet[], int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        permutationSet[i] = i + 1;
    }
}

void InitializeStopSet(int stopSet[], int numberOfElements)
{
    int reverseN = numberOfElements;
    for (int i = 0; i < numberOfElements; i++)
    {
        stopSet[i] = reverseN--;
    }
}

int CompareArrays(int permutationSet[], int stopSet[], int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        if (permutationSet[i] != stopSet[i])
        {
            return 1;
        }
    }
    return 0;
}

void NextPermutation(int permutationSet[], int numberOfElements)
{
    int valueAtPermutationIndexK = 0;
    int indexK;
    int indexJ;
    int valueAtPermutationIndexJ = numberOfElements;

    // find largest P_k such that P_k < P_(k+1)
    // if no k such that P_k < P_(k+1), then no more permutations
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        if (permutationSet[i] < permutationSet[i + 1])
        {
            if (permutationSet[i] > valueAtPermutationIndexK)
            {
                valueAtPermutationIndexK = permutationSet[i];
                indexK = i;
            }
        }
    }
    // check if P_k = 0, then no more permutations
    if (valueAtPermutationIndexK == 0)
    {
        return;
    }

    // Find smallest P_j such that j>k
    for (int i = indexK + 1; i < numberOfElements; i++)
    {
        if (permutationSet[i] < valueAtPermutationIndexJ)
        {
            valueAtPermutationIndexJ = permutationSet[i];
            indexJ = i;
        }
    }

    // Switch P_k and P_j
    permutationSet[indexJ] = valueAtPermutationIndexK;
    permutationSet[indexK] = valueAtPermutationIndexJ;

    // Reorder P_(k+1) to P_(n-1) in ascending order
    // use a sorting algorithm here
}
