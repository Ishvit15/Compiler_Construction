#include "hashtable.h"
#include "lexerDef.h"

void initializeLookupTable(lookupTableRecord* lookupTable) {
    for(int i = 0; i < LOOKUP_TABLE_SIZE; i++) {
        lookupTable[i].lexeme = "dummy";
        lookupTable[i].token = DUMMY;
    }
}

long long rollingHashFun(char* lexeme) {
    int lexeme_length = strlen(lexeme);
    long long hash_value = 0;
    long long prime_power = 1;
    for(int i = 0; i < lexeme_length; i++) {
        hash_value = (hash_value + (lexeme[i] - 'A' + 1) * prime_power) % m;
        // printf("hv = %d\n", hash_value);
        prime_power = (prime_power * p) % m;
        // printf("pp = %d\n", prime_power);
    }
    return hash_value;
}

int hash1(long long rollingHash) {
    return rollingHash % LOOKUP_TABLE_SIZE;
}

int hash2(long long rollingHash) {
    return PRIME - (rollingHash % PRIME);
}

void insert(lookupTableRecord* lookupTable, lookupTableRecord rec) {
    long long rollingHash = rollingHashFun(rec.lexeme);
    int probe = hash1(rollingHash);
    int offset = hash2(rollingHash);
    // if(strcmp(rec.lexeme, "boolean") == 0)
    // printf("%s insert!!!!%d@@@@%d@@@@%d\n", rec.lexeme, rollingHash, probe, offset);
    while(lookupTable[probe].token != DUMMY) {
        probe = (probe + offset) % LOOKUP_TABLE_SIZE;
    }
    lookupTable[probe] = rec;
}

int search(lookupTableRecord* lookupTable, char* lexeme) {
    long long rollingHash = rollingHashFun(lexeme);
    int initial_probe = hash1(rollingHash);
    int offset = hash2(rollingHash);
    // printf("%d!!!%d!!!%d\n", rollingHash, initial_probe, offset);
    int probe = initial_probe;
    while(lookupTable[probe].token != DUMMY) {
        if(strcmp(lookupTable[probe].lexeme, lexeme) == 0)
            return lookupTable[probe].token;
        probe = (probe + offset) % LOOKUP_TABLE_SIZE;
        if(probe == initial_probe)
            return DUMMY;
        printf("Hmmmm\n");
    }
    return DUMMY;
    
}


void generateLookupTable() {
    lookupTableRecord rec = {"integer", INTEGER};
    insert(lookupTable, rec);
    rec.lexeme = "real";
    rec.token = REAL;
    insert(lookupTable, rec);
    // rec = {"boolean", BOOLEAN};
    rec.lexeme = "boolean";
    rec.token = BOOLEAN;
    insert(lookupTable, rec);
    // rec = {"of", OF};
    rec.lexeme = "of";
    rec.token = OF;
    insert(lookupTable, rec);
    // rec = {"array", ARRAY};
    rec.lexeme = "array";
    rec.token = ARRAY;
    insert(lookupTable, rec);
   // rec = {"start", START};
    rec.lexeme = "start";
    rec.token = START;
    insert(lookupTable, rec);
    // rec = {"end", END};
    rec.lexeme = "end";
    rec.token = END;
     insert(lookupTable, rec);
   // rec = {"declare", DECLARE};
    rec.lexeme = "declare";
    rec.token = DECLARE;
    insert(lookupTable, rec);
    // rec = {"module", MODULE};
    rec.lexeme = "module";
    rec.token = MODULE;
     insert(lookupTable, rec);
    // rec = {"driver", DRIVER};
    rec.lexeme = "driver";
    rec.token = DRIVER;
    insert(lookupTable, rec);
    // rec = {"program", PROGRAM};
    rec.lexeme = "program";
    rec.token = PROGRAM;
    insert(lookupTable, rec);
    // rec = {"get_value", GET_VALUE};
    rec.lexeme = "get_value";
    rec.token = GET_VALUE;
     insert(lookupTable, rec);
   // rec = {"print", PRINT};
    rec.lexeme = "print";
    rec.token = PRINT;
    insert(lookupTable, rec);
    // rec = {"use", USE};
    rec.lexeme = "use";
    rec.token = USE;
    insert(lookupTable, rec);
    // rec = {"with", WITH};
    rec.lexeme = "with";
    rec.token = WITH;
    insert(lookupTable, rec);
    // rec = {"parameters", PARAMETERS};
    rec.lexeme = "parameters";
    rec.token = PARAMETERS;
    insert(lookupTable, rec);
    // rec = {"takes", TAKES};
    rec.lexeme = "takes";
    rec.token = TAKES;
    insert(lookupTable, rec);
    // rec = {"input", INPUT};
    rec.lexeme = "input";
    rec.token = INPUT;
     insert(lookupTable, rec);
   // rec = {"returns", RETURNS};
    rec.lexeme = "returns";
    rec.token = RETURNS;
    insert(lookupTable, rec);
    // rec = {"for", FOR};
    rec.lexeme = "for";
    rec.token = FOR;
     insert(lookupTable, rec);
   // rec = {"in", IN};
    rec.lexeme = "in";
    rec.token = IN;
    insert(lookupTable, rec);
    // rec = {"switch", SWITCH};
    rec.lexeme = "switch";
    rec.token = SWITCH;
    insert(lookupTable, rec);
   // rec = {"case", CASE};
    rec.lexeme = "case";
    rec.token = CASE;
    insert(lookupTable, rec);
   // rec = {"break", BREAK};
    rec.lexeme = "break";
    rec.token = BREAK;
    insert(lookupTable, rec);
   // rec = {"default", DEFAULT};
    rec.lexeme = "default";
    rec.token = DEFAULT;
    insert(lookupTable, rec);
   // rec = {"while", WHILE};
    rec.lexeme = "while";
    rec.token = WHILE;
    insert(lookupTable, rec);
    // rec = {"AND", AND};
    rec.lexeme = "AND";
    rec.token = AND;
    insert(lookupTable, rec);
    // rec = {"OR", OR};
    rec.lexeme = "OR";
    rec.token = OR;
    insert(lookupTable, rec);
    // rec = {"true", TRUE};
    rec.lexeme = "true";
    rec.token = TRUE;
    insert(lookupTable, rec);
    // rec = {"false", FALSE};
    rec.lexeme = "false";
    rec.token = FALSE;
    insert(lookupTable, rec);
   }

// int main() {

//     initializeLookupTable();
//     // lookupTableRecord rec = {"AND", AND};
//     // insert(rec);
//     generateLookupTable();

//     for(int i = 0; i < LOOKUP_TABLE_SIZE; i++) {
//         if(lookupTable[i].token != DUMMY)
//             printf("%d@@@%s###%d\n", i, lookupTable[i].lexeme, lookupTable[i].token);
//     }
//     printf("@@%d@@\n", search("integer"));
//     printf("@@%d@@\n", search("real"));
//     printf("@@%d@@\n", search("boolean"));
//     printf("@@%d@@\n", search("of"));
//     printf("@@%d@@\n", search("array"));
//     printf("@@%d@@\n", search("start"));
//     printf("@@%d@@\n", search("end"));
//     printf("@@%d@@\n", search("declare"));
//     printf("@@%d@@\n", search("module"));
//     printf("@@%d@@\n", search("driver"));
//     printf("@@%d@@\n", search("program"));
//     printf("@@%d@@\n", search("get_value"));
//     printf("@@%d@@\n", search("print"));
//     printf("@@%d@@\n", search("use"));
//     printf("@@%d@@\n", search("with"));
//     printf("@@%d@@\n", search("parameters"));
//     printf("@@%d@@\n", search("takes"));
//     printf("@@%d@@\n", search("input"));
//     printf("@@%d@@\n", search("returns"));
//     printf("@@%d@@\n", search("for"));
//     printf("@@%d@@\n", search("in"));
//     printf("@@%d@@\n", search("switch"));
//     printf("@@%d@@\n", search("case"));
//     printf("@@%d@@\n", search("break"));
//     printf("@@%d@@\n", search("default"));
//     printf("@@%d@@\n", search("while"));
//     printf("@@%d@@\n", search("AND"));
//     printf("@@%d@@\n", search("OR"));
//     printf("@@%d@@\n", search("true"));
//     printf("@@%d@@\n", search("false"));

//     return 0;
// }