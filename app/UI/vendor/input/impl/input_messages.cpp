#include "stdio.h"

void display_phone_initial_banner() {
    printf("Phone number (contact)\n");
    printf("----------------------\n");
    printf("Allowed formats: \n");
    printf("+xxx xxx xxx\n");
    printf("xxx xxx xxx\n");
    printf("xxxxxxxxx\n\n");
    printf("Please, enter phone number: ");
}

void display_phone_error_banner() {
    printf("Format of entered phone number is not allowed.\n");
    printf("Please, enter correct format: ");
}

void display_pharmacy_name_initial_banner() {
    printf("Pharmacy name\n");
    printf("-------------\n");
    printf("Allowed format: \n");
    printf("From 3 to 50 characters.\n");
    printf("Please, enter name of pharmacy: ");
}

void display_pharmacy_name_error_banner() {
    printf("The name of pharmacy contains more or less characters than allowed.\n");
    printf("Please, enter correct format: ");
}

void display_address_city_initial_banner() {
    printf("City\n");
    printf("----\n");
    printf("Allowed format: \n");
    printf("From 2 to 50 characters.\n");
    printf("Please, enter city name: ");
}

void display_address_city_error_banner() {
    printf("City name contains more or less characters than allowed.\n");
    printf("Please, enter correct format: ");
}

void display_address_street_initial_banner() {
    printf("Street\n");
    printf("------\n");
    printf("Allowed format: \n");
    printf("From 2 to 50 characters.\n");
    printf("Please, enter street name: ");
}

void display_address_street_error_banner() {
    printf("Street name contains more or less characters than allowed.\n");
    printf("Please, enter correct format: ");
}

void display_postal_code_initial_banner() {
    printf("Postal code\n");
    printf("-----------\n");
    printf("Allowed format: \n");
    printf("5 characters.\n");
    printf("Please, enter postal code: ");
}

void display_postal_code_error_banner() {
    printf("Format of the postal code is not allowed.\n");
    printf("Please, enter correct format: ");
}

void display_first_name_initial_banner() {
    printf("First name\n");
    printf("----------\n");
    printf("Allowed format: \n");
    printf("From 2 to 20 characters.\n");
    printf("Please, enter first name: ");
}

void display_first_name_error_banner() {
    printf("First name contains more or less characters than allowed.\n");
    printf("Please, enter correct format: ");
}

void display_last_name_initial_banner() {
    printf("Last name\n");
    printf("---------\n");
    printf("Allowed format: \n");
    printf("From 2 to 20 characters.\n");
    printf("Please, enter last name: ");
}

void display_last_name_error_banner() {
    printf("Last name contains more or less characters than allowed.\n");
    printf("Please, enter correct format: ");
}