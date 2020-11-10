#include "ctype.h"
#include "stdlib.h"

// Public functions implementation

bool validate_only_digits(char* buffer) {
    for (int i = 0; buffer[i] != NULL; i++) {
        if (!isdigit(buffer[i])) {
            return false;
        }
    }

    return true;
};

// xxx xxx xxx
bool validate_phone_number_without_prefix(char* buffer) {
    const unsigned short format_len = 11;

    for (int i = 1; i < format_len; i += 4) {
        // validate spaces between blocks
        if (buffer[i - 1] != ' ' && i != 1) {
            return false;
        }
        // validate block of three digits
        for (int j = 0; j < 3; j++) {
            if (!isdigit(buffer[i + j])) {
                return false;
            }
        }
    }

    return true;
};

// +xxx xxx xxx xxx
bool validate_phone_number_with_prefix(char* buffer) {
    const unsigned short format_len = 12;

    //check +xxx part
    if (buffer[0] != '+') {
        return false;
    }

    for (int i = 1; i < 4; i++) {
        if (!isdigit(buffer[i])) {
            return false;
        }
    }

    // check xxx xxx part
    for (int i = 5; i < format_len; i += 4) {
        // validate spaces between blocks
        if (buffer[i - 1] != ' ') {
            return false;
        }
        // validate block of three digits
        for (int j = 0; j < 3; j++) {
            if (!isdigit(buffer[i + j])) {
                return false;
            }
        }
    }

    return true;
}
