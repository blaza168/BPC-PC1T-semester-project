#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../input_messages.h"
#include "../validation.h"

// Private functions declaration
void clear_stdin();

// Public functions implementation

/**
 * Acceptable formats:
 *      - +xxx xxx xxx xxx
 *      - xxx xxx xxx
 *      - 9 digits
 *
 * @return Valid phone number from user
 */
char* get_phone_number() {
    char* buffer = (char*)malloc(sizeof(char) * 17);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_phone_initial_banner();
        } else {
            display_phone_error_banner();
        }

        scanf("%16[^\n]s", buffer);
        clear_stdin();

        if (strlen(buffer) == 9 && validate_only_digits(buffer)) {
            return buffer;
        } else if (strlen(buffer) == 16 && validate_phone_number_with_prefix(buffer)) {
            return buffer;
        } else if (strlen(buffer) == 11 && validate_phone_number_without_prefix(buffer)) {
            return buffer;
        }

        validation_error = true;
    }
};

// Private functions implementation
void clear_stdin() {
    while ((getchar()) != '\n');
};