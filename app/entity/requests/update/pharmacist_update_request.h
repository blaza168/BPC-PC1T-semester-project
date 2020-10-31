#ifndef SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H

struct  PharmacistUpdateRequest {
    unsigned int id;
    char* first_name;
    char* last_name;
    char* phone;
    unsigned int pharmacy_id;
};

#endif //SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H
