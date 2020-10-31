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

    printf(" _        __  _                        _        _      __        _         _          _        __            ");
    printf("| |      ___ | | __ __ _  _ __  _ __   _   ___ | | __ __ _    __| |  __ _ | |_  __ _ | |__    __ _  ____ ___ ");
    printf("| |     / _ .| |/ // _` || '__|| '_ . | | / __|| |/ // _` |  / _` | / _` || __|/ _` || '_ .  / _` ||_  // _ .");
    printf("| |____|  __/|   <| (_| || |   | | | || || (__ |   <| (_| | | (_| || (_| || |_| (_| || |_) || (_| | / /|  __/");
    printf("|______|.___||_|._..__,_||_|   |_| |_||_| .___||_|._..__,_|  .__,_| .__,_| .__|.__,_||_.__/  .__,_|/___|.___|");
    clear_screen();
}

ApplicationAction display_menu() {
     ApplicationAction option = MENU;

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