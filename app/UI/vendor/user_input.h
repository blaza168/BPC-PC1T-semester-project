
/**
 * Functions for handling user input
 */
#ifndef SEMESTRAL_PROJECT_USER_INPUT_H
#define SEMESTRAL_PROJECT_USER_INPUT_H

#include "../../entity/address.h"

// Shared

/**
 * Acceptable formats:
 *      - +xxx xxx xxx xxx
 *      - xxx xxx xxx
 *
 * @return Valid phone number from user
 */
char* get_phone_number();

// Pharmacy

/**
 * @return Name for pharmacy from user
 */
char* get_pharmacy_name();




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




#endif //SEMESTRAL_PROJECT_USER_INPUT_H
