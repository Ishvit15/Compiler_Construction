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
