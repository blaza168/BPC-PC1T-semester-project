#include "address.h"

#ifndef SEMESTRAL_PROJECT_PHARMACY_H
#define SEMESTRAL_PROJECT_PHARMACY_H

struct Pharmacy {
    unsigned int id;
    char name[51];
    char phone[17];
    Address address;
};

#endif //SEMESTRAL_PROJECT_PHARMACY_H
