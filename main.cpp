#include "app/data/data_management.h"
#include "app/entity/pharmacist.h"
#include "app/entity/pharmacy.h"
#include "app/UI/console.h"
#include "app/UI/constants.h"

int main() {
    // Application data
    struct DatabaseMetadata databaseMetadata = {0,0};
    struct Pharmacy pharmacies[20];
    struct Pharmacist pharmacists[20];
    // Program flow variables
    MenuOption menuOption = MENU;

    // Initialization
    init_ui();

    // Start of app
    display_welcome_screen();

    while (menuOption != EXIT) {
        if (menuOption == MENU) {
            menuOption = display_menu();
        } else if (menuOption == CREATE_PHARMACIST) {
            PharmacistCreateRequest createRequest = display_create_pharmacist_page();
        }
    }

    return 0;
}
