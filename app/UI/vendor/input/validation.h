/**
 * Functions for user input validation
 */
#ifndef SEMESTRAL_PROJECT_VALIDATION_H
#define SEMESTRAL_PROJECT_VALIDATION_H

/**
 * @param buffer - buffer containing text to validate
 * @return true if buffer contains only digits, false otherwise
 */
bool validate_only_digits(char* buffer);

/**
 * Acceptable:
 *      - xxx xxx xxx (digits)
 *
 * @param buffer - buffer containing text to validate
 * @return true if buffer fits required format
 */
bool validate_phone_number_without_prefix(char* buffer);

/**
 * Acceptable:
 *      - +xxx xxx xxx (digits)
 * @param buffer - buffer containing text to validate
 * @return true if buffer firs required format
 */
bool validate_phone_number_with_prefix(char* buffer);


#endif //SEMESTRAL_PROJECT_VALIDATION_H
