#include "../../address.h"

#ifndef SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H


struct PharmacyCreateRequest {
    char* name;
    char* phone;
    Address* address;
};

#endif //SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H
