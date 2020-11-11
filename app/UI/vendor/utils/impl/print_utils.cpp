#include "stdlib.h"

void clear_screen() {
#ifdef unix
    system("clear");
#else
    system("cls");
#endif
}