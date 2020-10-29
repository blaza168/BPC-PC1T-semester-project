/**
 * UI functions that will lead user to successfully submitted request from user input
 */
#ifndef SEMESTRAL_PROJECT_INPUT_MESSAGES_H
#define SEMESTRAL_PROJECT_INPUT_MESSAGES_H

/**
 * Display initial banner for user before input
 * including acceptable formats
 */
void display_phone_initial_banner();

/**
 * Display message to user when validation error occurs
 */
void display_phone_error_banner();

/**
 * Display initial banner before requesting input
 * including acceptable formats
 */
void display_pharmacy_name_initial_banner();

/**
 * Display error message
 */
void display_pharmacy_name_error_banner();

/**
 * Display initial banner for Address.city field
 */
void display_address_city_initial_banner();

/**
 * Display error banner for Address.city field
 */
void display_address_city_error_banner();

#endif //SEMESTRAL_PROJECT_INPUT_MESSAGES_H
