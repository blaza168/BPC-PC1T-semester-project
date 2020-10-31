#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../constants.h"
#include "../vendor/user_input.h"
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

PharmacistCreateRequest* perform_create_pharmacist_action() {
    PharmacistCreateRequest* request = (PharmacistCreateRequest*)malloc(sizeof(PharmacistCreateRequest));
    char* first_name;
    char* last_name;
    char* phone_number;

    printf("Create pharmacist");
    printf("-----------------");

    first_name = get_first_name();
    last_name = get_last_name();
    phone_number = get_phone_number();

    strcpy(request->first_name, first_name);
    strcpy(request->last_name, last_name);
    strcpy(request->phone, phone_number);

    free(first_name);
    free(last_name);
    free(phone_number);

    return request;
}

// Private functions implementations
void clear_screen() {
#ifdef unix
    system("clear");
#else
    system("cls");
#endif
}