/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#ifndef HASHDEF_H
#define HASHDEF_H

#define LOOKUP_TABLE_SIZE 199
#define PRIME 197
// #define struct lookupTableRecord lookupTableRecord
#define m 1000000007
#define p 53

typedef struct lookupTableRecord
{
    char *lexeme;
    int token;
} lookupTableRecord;
lookupTableRecord lookupTable[LOOKUP_TABLE_SIZE];

#endif
