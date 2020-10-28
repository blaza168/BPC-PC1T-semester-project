#ifndef SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H
#define SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H

struct  PharmacistUpdateRequest {
    unsigned int id;
    char first_name[21];
    char last_name[21];
    char phone[17];
    unsigned int pharmacy_id;
};

#endif //SEMESTRAL_PROJECT_PHARMACIST_UPDATE_REQUEST_H
