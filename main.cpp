#include "app/data/data_management.h"
#include "app/entity/pharmacist.h"
#include "app/entity/pharmacy.h"
#include "app/UI/console.h"
#include "app/UI/constants.h"

int main() {
    // Application data
    DatabaseMetadata* databaseMetadata = init_db_metadata();
    Pharmacy** pharmacies = init_pharmacy_space();
    Pharmacist** pharmacists = init_pharmacist_space();
    // Program flow variables
    ApplicationAction menuOption = MENU;

    // Initialization
    init_ui();

    // Start of app
    display_welcome_screen();

    while (menuOption != EXIT) {
        if (menuOption == MENU) {
            menuOption = display_menu();
        }
    }

    return 0;
}
