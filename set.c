#include "set.h";
#include "lexerDef.h"

void initializeSet(bool *s) {
    for(int i=0; i<TERMINALS_COUNT; i++){
        s[i]=FALSE;
    }
}

void addToSet(bool *s, int element) {
    s[element] = TRUE;
}

void deleteFromSet(bool *s, int element) {
    s[element]=FALSE;
}

bool findElementInSet(bool s[], int element) {
    return s[element];
}

void unionOfSets(bool *resultantSet, bool *s1, bool *s2) {
    for(int i=0; i<TERMINALS_COUNT; i++){
        resultantSet[i] = s1[i] || s2[i];
    }
}