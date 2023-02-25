enum tokenNo {
    DUMMY = -1,
    INTEGER,
    REAL,
    BOOLEAN,
    OF,
    ARRAY,
    START,
    END,
    DECLARE,
    MODULE,
    DRIVER,
    PROGRAM,
    GET_VALUE,
    PRINT,
    USE,
    WITH,
    PARAMETERS,
    TAKES,
    INPUT,
    RETURNS,
    FOR,
    IN,
    SWITCH,
    CASE,
    BREAK,
    DEFAULT,
    WHILE,
    AND,
    OR,
    TRUE,
    FALSE
};

typedef struct Token {
    int tokenNo;
    int lineNo;
    typedef union value{
        int decimalValue;
        float floatingPointValue;
        char* lexeme;
    } value;
} Token;
