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

/**
 * Display initial banner for Address.street field
 */
void display_address_street_initial_banner();

/**
 * Display error banner for Address.street field
 */
void display_address_street_error_banner();

/**
 * Display initial banner for Address.postal_code field
 */
void display_postal_code_initial_banner();

/**
 * Display error banner for Address.postal_code field
 */
void display_postal_code_error_banner();

/**
 * Display initial banner for pharmacists firstname
 */
void display_first_name_initial_banner();

/**
 * Display error banner for pharmacists firstname
 */
void display_first_name_error_banner();

/**
 * Display initial banner for pharmacists lastname
 */
void display_last_name_initial_banner();

/**
 * Display error banner for pharmacists lastname
 */
void display_last_name_error_banner();

/**
 * Display initial banner for entity id
 */
void display_id_initial_banner();

/**
 * Display error banner for entity id
 */
void display_id_error_banner();

#endif //SEMESTRAL_PROJECT_INPUT_MESSAGES_H
