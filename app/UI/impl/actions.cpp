#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../constants.h"
#include "../vendor/user_input.h"
#include "../../entity/requests/create/pharmacist_create_request.h"
#include "../../entity/requests/create/pharmacy_create_request.h"
#include "../vendor/utils/print_utils.h"
#include "../../entity/requests/update/pharmacist_to_pharmacy_request.h"
#include "../vendor/utils/stdin.h"
#include "../../entity/requests/update/pharmacy_update_request.h"
#include "../../entity/requests/update/pharmacist_update_request.h"

// Private function declaration

/**
* Map action code to ApplicationAction
* @return ApplicationAction
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
    clear_stdin();
    clear_screen();
}

ApplicationAction display_menu() {
     ApplicationAction option = MENU;
     int action_code = 0;

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
     scanf("%d", &action_code);
     clear_stdin();
     clear_screen();

     return map_user_input_to_application_action(action_code);
}

PharmacistCreateRequest* perform_create_pharmacist_action() {
    PharmacistCreateRequest* request = (PharmacistCreateRequest*)malloc(sizeof(PharmacistCreateRequest));

    printf("Create pharmacist\n");
    printf("-----------------\n");

    request->first_name = get_first_name();
    request->last_name = get_last_name();
    request->phone = get_phone_number();


    return request;
}

PharmacyCreateRequest* perform_create_pharmacy_action() {
    PharmacyCreateRequest* request = (PharmacyCreateRequest*)malloc(sizeof(PharmacyCreateRequest));

    printf("Create pharmacy\n");
    printf("---------------\n");

    request->name = get_pharmacy_name();
    request->phone = get_phone_number();
    request->address = perform_address_create_subaction();


    return request;
}

PharmacistIdentifier* perform_delete_pharmacist_action() {
    PharmacistIdentifier* request = (PharmacistIdentifier*)malloc(sizeof(PharmacistIdentifier));

    printf("Delete pharmacist\n");
    printf("-----------------\n");

    request->first_name = get_first_name();
    request->last_name = get_last_name();
    clear_screen();

    return request;
}

char* perform_delete_pharmacy_action() {
    char* pharmacy_name;

    printf("Delete pharmacy\n");
    printf("---------------\n");

    pharmacy_name = get_pharmacy_name();
    clear_screen();

    return pharmacy_name;
}

PharmacistToPharmacyRequest* perform_assign_action() {
    PharmacistToPharmacyRequest* request = (PharmacistToPharmacyRequest*)malloc(sizeof(PharmacistToPharmacyRequest));
    PharmacistIdentifier* identifier = (PharmacistIdentifier*)malloc(sizeof(PharmacistIdentifier));

    printf("Assign pharmacist to pharmacy\n");
    printf("-----------------------------\n");

    request->pharmacy_name = get_pharmacy_name();
    identifier->first_name = get_first_name();
    identifier->last_name = get_last_name();

    request->pharmacistIdentifier = identifier;

    return request;
}

// Private functions implementations

ApplicationAction map_user_input_to_application_action(int user_input) {
    if (user_input == 1) {
        return SEARCH_FOR_PHARMACIST;
    }
    if (user_input == 2) {
        return  SEARCH_FOR_PHARMACY;
    }
    if (user_input == 3) {
        return CREATE_PHARMACIST;
    }
    if (user_input == 4) {
        return  CREATE_PHARMACY;
    }
    if (user_input == 5) {
        return EDIT_PHARMACIST;
    }
    if (user_input == 6) {
        return  EDIT_PHARMACY;
    }
    if (user_input == 7) {
        return DELETE_PHARMACIST;
    }
    if (user_input == 8) {
        return  DELETE_PHARMACY;
    }
    if (user_input == 9) {
        return ASSIGN_PHARMACIST_TO_PHARMACY;
    }

    return MENU;
}

Address* perform_address_create_subaction() {
    Address* address = (Address*)malloc(sizeof(Address));

    printf("Address:\n");

    address->city = get_address_city();
    address->street = get_address_street();
    address->postal_code = get_address_postal_code();

    return address;
}

PharmacyUpdateRequest* perform_update_pharmacy_action() {
    PharmacyUpdateRequest* request = (PharmacyUpdateRequest*)malloc(sizeof(PharmacyUpdateRequest));

    printf("Edit pharmacy\n");
    printf("-------------\n");

    request->id = get_id();
    printf("Enter new values for entity\n");
    request->name = get_pharmacy_name();
    request->phone = get_phone_number();
    request->address = perform_address_create_subaction();

    return request;
}

PharmacistUpdateRequest* perform_update_pharmacist_action() {
    PharmacistUpdateRequest* request = (PharmacistUpdateRequest*)malloc(sizeof(PharmacistUpdateRequest));

    printf("Edit pharmacist\n");
    printf("---------------\n");

    request->id = get_id();
    printf("Enter new values for entity:\n");
    request->first_name = get_first_name();
    request->last_name = get_last_name();
    request->phone = get_phone_number();

    return request;
}

PharmacistIdentifier* perform_pharmacist_detail_action() {
    PharmacistIdentifier* identifier = (PharmacistIdentifier*)malloc(sizeof(PharmacistIdentifier));

    printf("Search for pharmacist\n");
    printf("---------------------\n");

    identifier->first_name = get_first_name();
    identifier->last_name = get_last_name();

    return identifier;
}

char* perform_pharmacy_detail_action() {

    printf("Search for pharmacy\n");
    printf("-------------------\n");

    return get_pharmacy_name();
}
