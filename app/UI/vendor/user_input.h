/**
 * Functions for handling user input
 * Workflow for working with longer values than are allowed has been inspired by MySQL => quietly strip away :)
 */
#ifndef SEMESTRAL_PROJECT_USER_INPUT_H
#define SEMESTRAL_PROJECT_USER_INPUT_H

#include "../../entity/address.h"

// Shared

/**
 * Acceptable formats:
 *      - +xxx xxx xxx xxx
 *      - xxx xxx xxx
 *		- xxxxxxxxx
 *      - digits with len 9
 *
 * @return Valid phone number from user
 */
char* get_phone_number();

// Pharmacy

/**
 * Acceptable format:
 *      - string with len 3 - 50
 *
 * @return Name for pharmacy from user
 */
char* get_pharmacy_name();

// Address

/**
 * Acceptable formats:
 *      - string with len 2 - 50
 *
 * @return char* representing city in address structure
 */
char* get_address_city();

/**
 * Acceptable formats:
 *      - string with len 2 - 50
 *
 * @return char* representing street
 */
char* get_address_street();

/**
 * Acceptable formats:
 *      - string with len 5 characters
 *
 * @return char* representing postal code for address structure
 */
char* get_address_postal_code();


// Pharmacist

/**
 * Acceptable formats:
 *      - string with len 2 - 20 characters
 *
 * @return char* representing valid first name
 */
char* get_first_name();

/**
 * Acceptable formats:
 *      - string with len 2 - 20 characters
 *
 * @return char* representing valid last name
 */
char* get_last_name();

/**
 * Acceptable formats:
 *      - int > 0
 *
 * @return number representing id of entity
 */
unsigned int get_id();


#endif //SEMESTRAL_PROJECT_USER_INPUT_H
