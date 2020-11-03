#ifndef SEMESTRAL_PROJECT_CONSTANTS_H
#define SEMESTRAL_PROJECT_CONSTANTS_H

enum ApplicationAction {
    MENU, // Display menu
    SEARCH_FOR_PHARMACIST, // Search for pharmacist entity
    SEARCH_FOR_PHARMACY, // Search for pharmacy entity
    CREATE_PHARMACIST, // Create pharmacist entity
    CREATE_PHARMACY, // Create pharmacy entity
    EDIT_PHARMACIST, // Edit pharmacist entity
    EDIT_PHARMACY, // Edit pharmacy entity
    DELETE_PHARMACIST, // Delete pharmacist entity
    DELETE_PHARMACY, // Delete pharmacy entity
    ASSIGN_PHARMACIST_TO_PHARMACY, // Assign pharmacist entity to pharmacy entity
    EXIT, // Exit application
};

#endif //SEMESTRAL_PROJECT_CONSTANTS_H
