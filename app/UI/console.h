#include "constants.h"

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
void print_welcome_screen();

/**
 * Display menu of available operations
 *
 * Returns:
 *      MenuOption - action that user wants to perform
 */
MenuOption display_menu();

#endif //SEMESTRAL_PROJECT_CONSOLE_H
