#include "../identifiers/pharmacist_identifier.h"

#ifndef SEMESTRAL_PROJECT_PHARMACIST_TO_PHARMACY_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACIST_TO_PHARMACY_REQUEST_H

struct PharmacistToPharmacyRequest {
    PharmacistIdentifier* pharmacistIdentifier;
    char* pharmacy_name;
};

#endif //SEMESTRAL_PROJECT_PHARMACIST_TO_PHARMACY_REQUEST_H
