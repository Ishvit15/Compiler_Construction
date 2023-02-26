#ifndef HASHDEF_H
#define HASHDEF_H

#define LOOKUP_TABLE_SIZE 199
#define PRIME 197
// #define struct lookupTableRecord lookupTableRecord
#define m 1000000007
#define p 53

typedef struct lookupTableRecord {
    char* lexeme;
    int token;
} lookupTableRecord;
lookupTableRecord lookupTable[30];

#endif