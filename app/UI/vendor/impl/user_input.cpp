#include "stdio.h"

// Private functions declaration
void flush_stdin();

// Public functions implementation

// Private functions implementation
void flush_stdin() {
    while ((getchar()) != '\n');
};