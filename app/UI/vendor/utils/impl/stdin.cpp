#include "stdio.h"

void clear_stdin() {
    while ((getchar()) != '\n');
}