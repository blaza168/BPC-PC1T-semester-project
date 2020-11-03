#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../constants.h"
#include "../vendor/user_input.h"
#include "../../entity/requests/create/pharmacist_create_request.h"
#include "../../entity/requests/create/pharmacy_create_request.h"

// Private functions declaration
void clear_screen();

/**
* Map data given from user 
* @return Pointer to ApplocationAction structure 
*/
ApplicationAction map_user_input_to_application_action(int user_input);

/**
 * Create Address entity from data given by user
 * @return Pointer to Address structure with filled data
 */
Address* perform_address_create_subaction();

// Public functions implementations
void init_ui() {
    setbuf(stdout, NULL);
}

void display_welcome_screen() {

    printf("  ____   _                                           _                ____          _          _                       \n");
    printf(" |  _ . | |__    __ _  _ __  _ __ ___    __ _   ___ (_)  ___  ___    |  _ .   __ _ | |_  __ _ | |__    __ _  ___   ___ \n");
    printf(" | |_) || '_  . / _` || '__|| '_ ` _ .  / _` | / __|| | / _ ./ __|   | | | | / _` || __|/ _` || '_ .  / _` |/ __| / _ .\n");
    printf(" |  __/ | | | || (_| || |   | | | | | || (_| || (__ | ||  __/.__ .   | |_| || (_| || |_| (_| || |_) || (_| |.__ .|  __/\n");
    printf(" |_|    |_| |_| .__,_||_|   |_| |_| |_| .__,_| .___||_| .___||___/   |____/  .__,_| .__|.__,_||_.__/  .__,_||___/ .___|\n\n");
    printf("Press Enter to continue"); 
    getchar();
    clear_screen();
}

ApplicationAction display_menu() {
     ApplicationAction option = MENU;
     int vstup = 0;

     printf(" ____  ____  ____  ____ \n");
     printf("||m ||||e ||||n ||||u ||\n");
     printf("||__||||__||||__||||__||\n\n");
     printf("Choose number of action you would like to perform:\n\n");
     printf("SEARCH FOR:                   CREATE:\n");
     printf("Pharmacist (1)                Pharmacist (3)\n");
     printf("Pharmacy (2)                  Pharmacy (4)\n\n");
     printf("EDIT:                         DELETE:\n");
     printf("Pharmacist (5)                Pharmacist (7)\n");
     printf("Pharmacy (6)                  Pharmacy (8)\n");
     printf("ASSIGN:                       Pharmacist to Pharmacy (9)\n");
     scanf("%d", &vstup);

     return map_user_input_to_application_action(vstup);
}

PharmacistCreateRequest* perform_create_pharmacist_action() {
    PharmacistCreateRequest* request = (PharmacistCreateRequest*)malloc(sizeof(PharmacistCreateRequest));
    char* first_name;
    char* last_name;
    char* phone_number;

    printf("Create pharmacist\n");
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

PharmacyCreateRequest* perform_create_pharmacy_action() {
    PharmacyCreateRequest* request = (PharmacyCreateRequest*)malloc(sizeof(PharmacyCreateRequest));
    char* name;
    char* phone;
    Address* address;

    printf("Create pharmacy\n");
    printf("---------------");

    name = get_pharmacy_name();
    phone = get_phone_number();
    address = perform_address_create_subaction();

    strcpy(request->name, name);
    strcpy(request->phone, phone);
    request->address = address;

    free(name);
    free(phone);

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

ApplicationAction map_user_input_to_application_action(int user_input) {
    if (vstup = 1) {
        return SEARCH_FOR_PHARMACIST;
    }
    if (vstup = 2) {
        return  SEARCH_FOR_PHARMACY;
    }
    if (vstup = 3) {
        return CREATE_PHARMACIST;
    }
    if (vstup = 4) {
        return  CREATE_PHARMACY;
    }
    if (vstup = 5) {
        return EDIT_PHARMACIST;
    }
    if (vstup = 6) {
        return  EDIT_PHARMACY;
    }
    if (vstup = 7) {
        return DELETE_PHARMACIST;
    }
    if (vstup = 8) {
        return  DELETE_PHARMACY;
    }
    if (vstup = 9) {
        return ASSIGN_PHARMACIST_TO_PHARMACY;
    }
}

Address* perform_address_create_subaction() {
    Address* address = (Address*)malloc(sizeof(Address));
    char* city;
    char* street;
    char* postal_code;

    printf("Address:\n");

    city = get_address_city();
    street = get_address_street();
    postal_code = get_address_postal_code();

    strcpy(address->city, city);
    strcpy(address->street, street);
    strcpy(address->postal_code, postal_code);

    free(city);
    free(street);
    free(postal_code);

    return address;
}