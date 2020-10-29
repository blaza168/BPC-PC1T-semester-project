#include "stdio.h"

void display_phone_initial_banner() {
    printf("Telefonni cislo (kontakt)\n");
    printf("-------------------------\n");
    printf("Povolene fomaty: \n");
    printf("+xxx xxx xxx\n");
    printf("xxx xxx xxx\n");
    printf("xxxxxxxxx\n\n");
    printf("Zadejte prosim tel. cislo: ");
};


void display_phone_error_banner() {
    printf("Vase tel. cislo bohuzel nevyhovuje pozadavkum.");
    printf("Zkuste to prosim znovu: ");
};