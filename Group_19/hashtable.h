/*
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA
ID: 2019B5A70226P  Name: ISHVIT BHASIN
ID: 2019B2A70878P  Name: RITIK THAKUR
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

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