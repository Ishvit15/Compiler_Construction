#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "hashDef.h"

// #define ll long long;
void initializeLookupTable(lookupTableRecord *lookupTable);
long long rollingHashFun(char *lexeme);
int hash1(long long rollingHash);
int hash2(long long rollingHash);
void insert(lookupTableRecord *lookupTable, lookupTableRecord rec);
int search(char *lexeme);
void generateLookupTable();

#endif