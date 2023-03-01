#include <stdbool.h>

// bool set[TERMINALS_COUNT];

void initializeSet(bool *s);

void addToSet(bool *s, int element);

void deleteFromSet(bool *s, int element);

bool findElementInSet(bool s[], int element);

void unionOfSets(bool *resultantSet, bool *s1, bool *s2);