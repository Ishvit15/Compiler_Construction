#include <stdbool.h>
#define MAX_SET_SIZE 100

typedef bool* Set;

void initializeSet(Set s);

void addToSet(Set s, int element);

void deleteFromSet(Set s, int element);

bool findElementInSet(Set s, int element);

void unionOfSets(Set resultantSet, Set s1, Set s2);

bool checkIfEqual(Set s1, Set s2);
