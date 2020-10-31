#include "stdlib.h"
#include "../entity.h"
#include "../../entity/pharmacist.h"
#include "../../entity/pharmacy.h"
#define INITIAL_ENTITY_CAPACITY 20

DatabaseMetadata* init_db_metadata() {
    DatabaseMetadata* databaseMetadata = (DatabaseMetadata*)malloc(sizeof(DatabaseMetadata));

    databaseMetadata->pharmacies_capacity = INITIAL_ENTITY_CAPACITY;
    databaseMetadata->pharmacist_capacity = INITIAL_ENTITY_CAPACITY;

    databaseMetadata->pharmacies_count = 0;
    databaseMetadata->pharmacists_count = 0;

    return databaseMetadata;
}

Pharmacist** init_pharmacist_space() {
    return (Pharmacist**)malloc(sizeof(struct  Pharmacist*) * INITIAL_ENTITY_CAPACITY);
}

Pharmacy** init_pharmacy_space() {
    return (Pharmacy**)malloc(sizeof(struct Pharmacy*) * INITIAL_ENTITY_CAPACITY);
}
