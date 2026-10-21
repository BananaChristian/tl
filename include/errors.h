#ifndef ERRORS_H
#define ERRORS_H

#include "strv.h"

typedef enum {
  OPERATIONAL,
  ERROR,
  ICE,
} ErrorTier;

typedef struct {
  ErrorTier tier;
  Strv message;
} Error;

Error operational_error();
Error error_new(ErrorTier tier, const char *message);

#endif // !ERRORS_H
