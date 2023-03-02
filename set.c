#include "set.h";

void initializeSet(Set s)
{
    for (int i = 0; i < MAX_SET_SIZE; i++)
        s[i] = 0;
}

void addToSet(Set s, int element)
{
    s[element] = 1;
}

void deleteFromSet(Set s, int element)
{
    s[element] = 0;
}

bool findElementInSet(Set s, int element)
{
    return s[element];
}

void unionOfSets(Set resultantSet, Set s1, Set s2)
{
    for (int i = 0; i < MAX_SET_SIZE; i++)
        resultantSet[i] = s1[i] || s2[i];
}

bool checkIfEqual(Set s1, Set s2)
{
    for (int i = 0; i < MAX_SET_SIZE; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}