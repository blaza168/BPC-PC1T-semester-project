#include "stdlib.h"
#include "string.h"
#include "app/data/data_management.h"
#include "app/entity/pharmacist.h"
#include "app/entity/pharmacy.h"
#include "app/UI/actions.h"
#include "app/UI/alerts.h"
#include "app/UI/constants.h"
#include "app/entity/requests/identifiers/pharmacist_identifier.h"

void free_pharmacist_creation_entities(PharmacistIdentifier* identifier, PharmacistCreateRequest* request);

int main() {
    // Application data
    DatabaseMetadata* databaseMetadata = init_db_metadata();
    Pharmacy** pharmacies = init_pharmacy_space();
    Pharmacist** pharmacists = init_pharmacist_space();
    // Program flow variables
    ApplicationAction menuOption = MENU;

    // Initialization
    init_ui();

    // Start of app
    display_welcome_screen();

    while (menuOption != EXIT) {
        if (menuOption == MENU) {
            menuOption = display_menu();
        } else if (menuOption == CREATE_PHARMACY) {
            PharmacyCreateRequest* request = perform_create_pharmacy_action();

            // duplicate check
            if (find_pharmacy(request->name, &pharmacies, databaseMetadata)) {
                display_pharmacy_creation_error_alert();
                menuOption = MENU;
                continue;
            }

            unsigned int id = insert_pharmacy(request, &pharmacies, databaseMetadata);
            Pharmacy* pharmacy = find_pharmacy_by_id(id, &pharmacies, databaseMetadata);
            display_pharmacy_creation_success_alert(pharmacy);

            free(request);
        } else if (menuOption == CREATE_PHARMACIST) {
            PharmacistCreateRequest* request = perform_create_pharmacist_action();

            // TODO: move to converter
            PharmacistIdentifier* identifier = (PharmacistIdentifier*)malloc(sizeof(PharmacistIdentifier));
            strcpy(identifier->first_name, request->first_name);
            strcpy(identifier->last_name, request->last_name);

            // check for duplicate
            if (find_pharmacist(identifier, &pharmacists, databaseMetadata)) {
                display_pharmacist_creation_error_alert();
                menuOption = MENU;
                continue;
            }

            unsigned int id = insert_pharmacist(request, &pharmacists, databaseMetadata);
            Pharmacist* pharmacist = find_pharmacist_by_id(id, &pharmacists, databaseMetadata);

            display_pharmacist_creation_success_alert(pharmacist);
            free_pharmacist_creation_entities(identifier, request);

            menuOption = MENU;
        }
    }

    return 0;
}

void free_pharmacist_creation_entities(PharmacistIdentifier* identifier, PharmacistCreateRequest* request) {
    free(request->first_name);
    free(request->last_name);
    free(request->phone);
    free(request);

    free(identifier->first_name);
    free(identifier->last_name);
    free(identifier);
}
