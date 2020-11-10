#include "stdio.h"

void clear_stdin() {
    if (fseek(stdin, 0, SEEK_END)) {
        while ((getchar()) != '\n');
    }
}