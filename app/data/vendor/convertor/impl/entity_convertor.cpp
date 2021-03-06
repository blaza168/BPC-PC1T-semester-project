#include "stdlib.h"
#include "string.h"
#include "../../../../entity/pharmacy.h"
#include "../../../../entity/requests/create/pharmacy_create_request.h"
#include "../../../../entity/pharmacist.h"
#include "../../../../entity/requests/create/pharmacist_create_request.h"

Pharmacy* create_request_to_pharmacy(PharmacyCreateRequest* request) {
    Pharmacy* pharmacy = (Pharmacy*)malloc(sizeof(Pharmacy));

    pharmacy->phone = (char*)malloc(sizeof(char) * strlen(request->phone) + 1);
    pharmacy->name = (char*)malloc(sizeof(char) * strlen(request->name) + 1);

    strcpy(pharmacy->name, request->name);
    strcpy(pharmacy->phone, request->phone);

    pharmacy->address = request->address;

    free(request->name);
    free(request->phone);
    free(request);

    return pharmacy;
}

Pharmacist* create_request_to_pharmacist(PharmacistCreateRequest* request) {
    Pharmacist* pharmacist = (Pharmacist*)malloc(sizeof(Pharmacist));

    pharmacist->first_name = request->first_name;
    pharmacist->last_name = request->last_name;
    pharmacist->phone = request->phone;
    pharmacist->pharmacy_id = 0;

    free(request);

    return pharmacist;
}