#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// #define ll long long;
#define LOOKUP_TABLE_SIZE 199
#define PRIME 197
// #define struct lookupTableRecord lookupTableRecord
const int m = 1000000007;
const int p = 53;

typedef struct lookupTableRecord {
    char* lexeme;
    int token;
} lookupTableRecord;
// lookupTableRecord lookupTable[30];

void initializeLookupTable(lookupTableRecord* lookupTable);
long long rollingHashFun(char* lexeme);
int hash1(long long rollingHash);
int hash2(long long rollingHash);
void insert(lookupTableRecord* lookupTable, lookupTableRecord rec);
int search(lookupTableRecord* lookupTable, char* lexeme);
void generateLookupTable();
