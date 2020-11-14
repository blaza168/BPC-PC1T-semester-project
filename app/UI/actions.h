#include "constants.h"
#include "../entity/requests/create/pharmacist_create_request.h"
#include "../entity/requests/create/pharmacy_create_request.h"
#include "../entity/requests/update/pharmacist_to_pharmacy_request.h"
#include "../entity/requests/update/pharmacy_update_request.h"
#include "../entity/requests/update/pharmacist_update_request.h"

#ifndef SEMESTRAL_PROJECT_CONSOLE_H
#define SEMESTRAL_PROJECT_CONSOLE_H

/**
 * Function for initializing console.
 * Functions:
 *  - Set stdout buffer to NULL
 */
void init_ui();

/**
 * Print initial welcome screen of this application and pause screen
 * until user presses enter
 * Clear screen after that
 */
void display_welcome_screen();

/**
 * Display menu of available operations
 * Clear screen after getting input from user
 *
 * @return Action that user wants to perform
 */
ApplicationAction display_menu();

/**
 * Display page for creating pharmacist
 * Get data from user
 * Clear screen
 *
 * @return Request to create pharmacist filled with data from user
 */
PharmacistCreateRequest* perform_create_pharmacist_action();

/**
 * Display page for creating pharmacy
 * Get data from user
 * Clear screen
 *
 * @return Request to create pharmacist filled with data from user
 */
 PharmacyCreateRequest* perform_create_pharmacy_action();

/**
 * Display page for deleting pharmacy
 * Get name of pharmacy which user want to delete
 * Clear screen
 *
 * @return Name of pharmacy that user wants to delete
 */
char* perform_delete_pharmacy_action();

/**
 * Display page for deleting pharmacist
 * Get first name and last name
 * Clear screen
 *
 * @return PharmacistIdentifier filled with data
 */
PharmacistIdentifier* perform_delete_pharmacist_action();

/**
 * Display page from assigning pharmacist to pharmacy
 *
 * @return
 */
PharmacistToPharmacyRequest* perform_assign_action();

/**
 * Display page for updating pharmacy
 * Get all necessary data from user
 *
 * @return Data from user mapped to entity
 */
PharmacyUpdateRequest* perform_update_pharmacy_action();

/**
 * Display page for updating pharmacist
 * Get all necessary data from user
 *
 * @return Data from user mapped to entity
 */
PharmacistUpdateRequest* perform_update_pharmacist_action();

/**
 * Display page for getting pharmacist detail identifiers
 *
 * @return Pharmacist identifiers
 */
PharmacistIdentifier* perform_pharmacist_detail_action();

/**
 * Display page for getting pharmacy details identifier
 *
 * @return pharmacy name
 */
char* perform_pharmacy_detail_action();

#endif //SEMESTRAL_PROJECT_CONSOLE_H
