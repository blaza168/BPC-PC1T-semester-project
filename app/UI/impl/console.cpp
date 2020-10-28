#include "stdio.h"
#include "stdlib.h"
#include "../constants.h"

// Private functions declaration
void clear_screen();

// Public functions implementations
void init_ui() {
    setbuf(stdout, NULL);
}

void print_welcome_screen() {
    printf("Hello");
    clear_screen();
}

MenuOption display_menu() {
    enum MenuOption option;
    option == NONE;

    return option;
}

// Private functions implementations
void clear_screen() {
#ifdef unix
    system("clear");
#else
    system("cls");
#endif
}
