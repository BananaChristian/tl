#ifndef AST_H

#define AST_H

#include "literals.h"
#include "operators.h"
#include "span.h"

typedef struct ASTExpr ASTExpr;

typedef enum {
  NODE_LITERAL,
  NODE_INFIX,
} ASTExprTag;

typedef struct {
  ASTExpr *left;
  BinaryOps operator;
  ASTExpr *right;
} ASTInfix;

typedef union {
  ASTLiteral literal;
  ASTInfix infix;
} ASTExprData;

typedef struct {
  ASTExprTag tag;
  ASTExprData data;
} ASTExprkind;

struct ASTExpr {
  ASTExprkind kind;
  Span span;
};

#endif // !AST_H
