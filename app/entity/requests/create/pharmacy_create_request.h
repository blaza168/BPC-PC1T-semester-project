#include "../../address.h"

#ifndef SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H


struct PharmacyCreateRequest {
    char name[51];
    char phone[17];
    Address address;
};

#endif //SEMESTRAL_PROJECT_PHARMACY_CREATE_REQUEST_H
