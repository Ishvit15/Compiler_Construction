/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

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