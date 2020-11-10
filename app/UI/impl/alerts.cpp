#include "stdio.h"
#include "../vendor/utils/print_utils.h"
#include "../../entity/pharmacy.h"
#include "../../entity/pharmacist.h"
#include "../../entity/address.h"

void display_pharmacy_creation_success_alert(Pharmacy* pharmacy) {
	printf("Creation of pharmacy was successful.\n\n");
	printf("ID: %d\n", pharmacy->id);
	printf("Name: %s\n", pharmacy->name);
	printf("Phone number: %s\n", pharmacy->phone);
	printf("Street: %s\n", pharmacy->address->street);
	printf("City: %s\n", pharmacy->address->city);
	printf("Postal code: %s\n", pharmacy->address->postal_code);
	getchar();
	clear_screen();
}

void display_pharmacy_creation_error_alert() {
	printf("Creation of pharmacy was not successful.\n");
	printf("This pharmacy is already registered in this system.\n\n");
	printf("Press Enter to continue");
	getchar();
	clear_screen();
}

void display_pharmacist_creation_success_alert(Pharmacist* pharmacist) {
	printf("Creation of pharmacist was successful.\n\n");
	printf("ID: %d\n", pharmacist->id);
	printf("Pharmacy ID: %d\n", pharmacist->pharmacy_id);
	printf("First name: %s\n", pharmacist->first_name);
	printf("Last name: %s\n", pharmacist->last_name);
	printf("Phone number: %s\n", pharmacist->phone);
	getchar();
	clear_screen();
}

void display_pharmacist_creation_error_alert() {
	printf("Creation of pharmacist was not successful.\n");
	printf("This pharmacist is already registered in this system.\n\n");
	printf("Press Enter to continue");
	getchar();
	clear_screen();
}

void display_assign_success_alert() {

}

void display_assign_error_alert(char* error_message) {

}
