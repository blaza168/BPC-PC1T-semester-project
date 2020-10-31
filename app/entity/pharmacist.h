#ifndef SEMESTRAL_PROJECT_PHARMACIST_H
#define SEMESTRAL_PROJECT_PHARMACIST_H

struct Pharmacist {
    unsigned int id;
    char* first_name;
    char* last_name;
    char* phone;
    unsigned int pharmacy_id; // 0 if not set
};

#endif //SEMESTRAL_PROJECT_PHARMACIST_H
