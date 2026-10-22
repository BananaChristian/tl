#include "ast/ast.h"
#include "parser.h"

ASTExpr parse_expr(Parser *parser) {}

ASTExpr parse_infix(Parser *parser) { ASTExpr left = parse_expr(parser); }
