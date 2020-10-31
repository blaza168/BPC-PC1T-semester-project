#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../input/input_messages.h"
#include "../input/validation.h"

// Private functions declaration
void clear_stdin();

// Public functions implementation

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

char* get_pharmacy_name() {
    char* buffer = (char*)malloc(sizeof(char) * 51);
    bool validation_error = false;

    while (true) {

        if (!validation_error) {
            display_pharmacy_name_initial_banner();
        } else {
            display_pharmacy_name_error_banner();
        }

        scanf("%50[^\n]s", buffer);
        clear_stdin();

        if (strlen(buffer) >= 3) {
            return buffer;
        }

        validation_error = true;
    }

};

char* get_address_city() {
    char* buffer = (char*)malloc(sizeof(char) * 51);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_address_city_initial_banner();
        } else {
            display_address_city_error_banner();
        }

        scanf("%50[^\n]s", buffer);
        clear_stdin();

        if (strlen(buffer) >= 2) {
            return buffer;
        }

        validation_error = true;
    }
}

char* get_address_street() {
    char* buffer = (char*)malloc(sizeof(char) * 51);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_address_street_initial_banner();
        } else {
            display_address_street_error_banner();
        }

        scanf("%50[^\n]s", buffer);
        clear_stdin();

        if (strlen(buffer) >= 2) {
            return buffer;
        }

        validation_error = true;
    }
}

char* get_address_postal_code() {
    char* buffer = (char*)malloc(sizeof(char) * 6);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_postal_code_initial_banner();
        } else {
            display_postal_code_error_banner();
        }

        scanf("%50[^\n]s", buffer);
        clear_stdin();

        if (strlen(buffer) == 5 && validate_only_digits(buffer)) {
            return buffer;
        }

        validation_error = true;
    }
}

char* get_first_name() {
    char* buffer = (char*)malloc(sizeof(char) * 6);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_first_name_initial_banner();
        } else {
            display_first_name_error_banner();
        }

        scanf("%20s", buffer);
        clear_stdin();

        if (strlen(buffer) >= 2) {
            return buffer;
        }

        validation_error = true;
    }
}

char* get_last_name() {
    char* buffer = (char*)malloc(sizeof(char) * 21);
    bool validation_error = false;

    while (true) {
        if (!validation_error) {
            display_last_name_initial_banner();
        } else {
            display_last_name_error_banner();
        }

        scanf("%20s", buffer);
        clear_stdin();

        if (strlen(buffer) >= 2) {
            return buffer;
        }

        validation_error = true;
    }
}

// Private functions implementation
void clear_stdin() {
    while ((getchar()) != '\n');
};