#include "threads/synch.h"

/* Get max value in most efficent way.
   In c++:
     *a = max(*b, *c) */
void
max (int *a, const int *b, const int *c) {
  *a = *b > *c ? *b : *c;
}
