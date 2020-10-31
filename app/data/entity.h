#ifndef SEMESTRAL_PROJECT_ENTITY_H
#define SEMESTRAL_PROJECT_ENTITY_H

/**
 * Structure for holding core metadata about every entity array
 */
struct DatabaseMetadata {
    unsigned int pharmacists_count;
    unsigned int pharmacist_capacity;

    unsigned int pharmacies_count;
    unsigned int pharmacies_capacity;
};

#endif //SEMESTRAL_PROJECT_ENTITY_H
