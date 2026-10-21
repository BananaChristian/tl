#ifndef AST_LITERALS_H

#define AST_LITERALS_H

#include <stddef.h>
typedef enum {
  INTEGER,
} ASTLiteralTag;

typedef union {
  size_t value;
} ASTLiteralValue;

typedef struct {
  ASTLiteralTag literal_tag;
  ASTLiteralValue literal_value;
} ASTLiteral;

#endif // !AST_LITERALS_H
