#include "stdio.h"
#include "stdlib.h"
#include "../constants.h"
#include "../../entity/requests/create/pharmacist_create_request.h"

// Private functions declaration
void clear_screen();

// Public functions implementations
void init_ui() {
    setbuf(stdout, NULL);
}

void display_welcome_screen() {
    printf("Hello");
    clear_screen();
}

MenuOption display_menu() {
    enum MenuOption option;

    return option;
}

PharmacistCreateRequest display_create_pharmacist_page() {

};

// Private functions implementations
void clear_screen() {
#ifdef unix
    system("clear");
#else
    system("cls");
#endif
}
