/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "set.h";

void initializeSet(Set s) {
    s = 0;
}

void addToSet(Set s, int element) {
    s = s | 1 << element;
}

void deleteFromSet(Set s, int element) {
    s = s & ~(1 << element);
}

bool findElementInSet(Set s, int element) {
    return s & 1 << element;
}

void unionOfSets(Set resultantSet, Set s1, Set s2) {
    resultantSet = s1 | s2;
}
