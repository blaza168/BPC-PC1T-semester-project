#include "constants.h"
#include "../entity/requests/create/pharmacist_create_request.h"

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
 * until user presses button
 * Clear screen after that
 */
void display_welcome_screen();

/**
 * Display menu of available operations
 * Clear screen after getting input from user
 *
 * @return Action that user wants to perform
 */
MenuOption display_menu();

/**
 * Display page for creating pharmacist
 * Get data from user
 * Clear screen
 *
 * @return Request to create pharmacist filled with data from user
 */
PharmacistCreateRequest display_create_pharmacist_page();

#endif //SEMESTRAL_PROJECT_CONSOLE_H
