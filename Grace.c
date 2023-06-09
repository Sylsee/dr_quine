#include <stdio.h>
#include <stdlib.h>

#define OPEN(file) fopen(file, "w")
#define GRACE "#include <stdio.h>%1$c#include <stdlib.h>%1$c%1$c#define OPEN(file) fopen(file, %2$cw%2$c)%1$c#define GRACE %2$c%3$s%2$c%1$c#define START int main() { fprintf(OPEN(%2$cGrace_kid.c%2$c), GRACE, 10, 34, GRACE); }%1$c%1$cSTART%1$c%1$c// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH%1$c"
#define START int main() { fprintf(OPEN("Grace_kid.c"), GRACE, 10, 34, GRACE); }

START

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH
