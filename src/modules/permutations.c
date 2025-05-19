#include <stdio.h>

void GeneratePermutations(int numberOfElements)
{
    // Produce all permutations of set size equal to input
    int permutationSet[numberOfElements];
    int stopSet[numberOfElements];
    InitializeSet(permutationSet, numberOfElements);
    InitializeStopSet(stopSet, numberOfElements);
    PrintPermutation(permutationSet, numberOfElements);
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
    for (int i = 0; i < numberOfElements; i++)
    {
    }
}

void PrintPermutation(int permutationSet[], int numberOfElements)
{
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("%d", permutationSet[i]);
    }
}