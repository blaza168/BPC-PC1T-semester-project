#include "stdio.h"
#include "../vendor/utils/print_utils.h"
#include "../../entity/pharmacy.h"
#include "../../entity/pharmacist.h"
#include "../vendor/utils/stdin.h"

void display_pharmacy_creation_success_alert(Pharmacy* pharmacy) {
	printf("Creation of pharmacy was successful.\n\n");
	printf("ID: %d\n", pharmacy->id);
	printf("Name: %s\n", pharmacy->name);
	printf("Phone number: %s\n", pharmacy->phone);
	printf("Street: %s\n", pharmacy->address->street);
	printf("City: %s\n", pharmacy->address->city);
	printf("Postal code: %s\n", pharmacy->address->postal_code);
	clear_stdin();
	clear_screen();
}

void display_pharmacy_creation_error_alert() {
	printf("This pharmacy is already registered in this system.\n\n");
	printf("Press Enter to continue");
	clear_stdin();
	clear_screen();
}

void display_pharmacist_creation_success_alert(Pharmacist* pharmacist) {
	printf("Creation of pharmacist was successful.\n\n");
	printf("ID: %d\n", pharmacist->id);
	printf("Pharmacy ID: %d\n", pharmacist->pharmacy_id);
	printf("First name: %s\n", pharmacist->first_name);
	printf("Last name: %s\n", pharmacist->last_name);
	printf("Phone number: %s\n", pharmacist->phone);
	clear_stdin();
	clear_screen();
}

void display_pharmacist_creation_error_alert() {
	printf("This pharmacist is already registered in this system.\n\n");
	printf("Press Enter to continue");
	clear_stdin();
	clear_screen();
}

void display_assign_success_alert() {

}

void display_assign_error_alert(char* error_message) {

}

void display_pharmacy_not_found_alert() {

}

void display_pharmacist_not_found_alert() {

}

void display_pharmacy_update_success_alert() {

}

void display_pharmacist_update_success_alert() {

}

void display_pharmacy_detail_alert(Pharmacy* pharmacy) {
    printf("Pharmacy detail:\n");
    printf("Name: %s\n", pharmacy->name);
    printf("Phone: %s\n", pharmacy->phone);
    printf("Adrress: \n");
    printf("City: %s\n", pharmacy->address->city);
    printf("Postal code: %s\n", pharmacy->address->postal_code);
    printf("Street: %s\n", pharmacy->address->street);
    clear_stdin();
    clear_screen();
}

void display_pharmacist_detail_alert(Pharmacist* pharmacist, Pharmacy* pharmacy) {
    printf("Pharmacist detail:\n");
    printf("Id: %d\n", pharmacist->id);
    printf("Phone: %s\n", pharmacist->phone);
    printf("First: %s\n", pharmacist->first_name);
    printf("Last name: %s\n", pharmacist->last_name);

    if (pharmacy) {
        printf("Associated pharmacy:\n");
        display_pharmacy_detail_alert(pharmacy);
    }

    clear_stdin();
    clear_screen();
}
