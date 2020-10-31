#include "../../address.h"

#ifndef SEMESTRAL_PROJECT_PHARMACY_UPDATE_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACY_UPDATE_REQUEST_H


struct PharmacyUpdateRequest {
    unsigned int id;
    char* name;
    char* phone;
    Address* address;
};

#endif //SEMESTRAL_PROJECT_PHARMACY_UPDATE_REQUEST_H
