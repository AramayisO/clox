#ifndef CLOX_SCANNER_H 
#define CLOX_SCANNER_H

enum TokenType {
    // Sinlge character tokens
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
    // One or two character tokens
    NOT,
    NOT_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    // Literanls
    IDENTIFIER,
    STRING,
    NUMBER,
    // Keywords
    NIL,
    VAR,
    FUN,
    CLASS,
    SUPER,
    THIS,
    RETURN,
    TRUE,
    FALSE,
    IF,
    ELSE,
    AND,
    OR,
    FOR,
    WHILE,
    PRINT
};

typedef enum TokenType TokenType;

struct Token {
    TokenType type;
    int line;
    int col;
    char *str;
};

typedef struct Token Token;

struct Scanner {
    Token tokens[256];
};

typedef struct Scanner Scanner;

#endif
