#ifndef SEMESTRAL_PROJECT_ENTITY_H
#define SEMESTRAL_PROJECT_ENTITY_H

/**
 * Structure for holding core metadata about every entity array
 */
struct DatabaseMetadata {
    unsigned int pharmacists_count;
    unsigned int pharmacists_capacity;
    unsigned int pharmacists_last_id;

    unsigned int pharmacies_count;
    unsigned int pharmacies_capacity;
    unsigned int pharmacies_last_id;
};

#endif //SEMESTRAL_PROJECT_ENTITY_H
