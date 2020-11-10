#include "stdlib.h"
#include "string.h"
#include "../entity.h"
#include "../vendor/convertor/entity_convertor.h"
#include "../../entity/pharmacist.h"
#include "../../entity/pharmacy.h"
#include "../../entity/requests/create/pharmacy_create_request.h"
#include "../../entity/requests/create/pharmacist_create_request.h"
#include "../../entity/requests/identifiers/pharmacist_identifier.h"

#define INITIAL_ENTITY_CAPACITY 20

DatabaseMetadata* init_db_metadata() {
    DatabaseMetadata* databaseMetadata = (DatabaseMetadata*)malloc(sizeof(DatabaseMetadata));

    databaseMetadata->pharmacies_capacity = INITIAL_ENTITY_CAPACITY;
    databaseMetadata->pharmacists_capacity = INITIAL_ENTITY_CAPACITY;

    databaseMetadata->pharmacies_count = 0;
    databaseMetadata->pharmacists_count = 0;

    databaseMetadata->pharmacies_last_id = 0;
    databaseMetadata->pharmacists_last_id = 0;

    return databaseMetadata;
}

Pharmacist** init_pharmacist_space() {
    return (Pharmacist**)malloc(sizeof(struct  Pharmacist*) * INITIAL_ENTITY_CAPACITY);
}

Pharmacy** init_pharmacy_space() {
    return (Pharmacy**)malloc(sizeof(struct Pharmacy*) * INITIAL_ENTITY_CAPACITY);
}

unsigned int insert_pharmacy(PharmacyCreateRequest* request, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {
    // Allocate larger memory if needed
    if (databaseMetadata->pharmacies_count == databaseMetadata->pharmacies_capacity) {
        databaseMetadata->pharmacies_capacity += 10;
        Pharmacy** buffer = (Pharmacy**)malloc(sizeof(struct Pharmacy*) * databaseMetadata->pharmacies_capacity);

        // copy data from old to new
        for (int i = 0; i < databaseMetadata->pharmacies_count; i++) {
            buffer[i] = *table[i];
        }
        free(*table);

        *table = buffer;
    }

    databaseMetadata->pharmacies_last_id += 1;
    databaseMetadata->pharmacies_count += 1;

    Pharmacy* pharmacy = create_request_to_pharmacy(request);
    pharmacy->id = databaseMetadata->pharmacies_last_id;

    *table[databaseMetadata->pharmacies_count - 1] = pharmacy;

    return databaseMetadata->pharmacies_last_id;
}

unsigned int insert_pharmacist(PharmacistCreateRequest* request, Pharmacist*** table, DatabaseMetadata* databaseMetadata) {
    // Allocate larger memory if needed
    if (databaseMetadata->pharmacists_count == databaseMetadata->pharmacists_capacity) {
        databaseMetadata->pharmacists_capacity += 10;
        Pharmacist** buffer = (Pharmacist**)malloc(sizeof(struct Pharmacist*) * databaseMetadata->pharmacists_capacity);

        // copy data from old to new
        for (int i = 0; i < databaseMetadata->pharmacists_count; i++) {
            buffer[i] = *table[i];
        }
        free(*table);

        *table = buffer;
    }

    databaseMetadata->pharmacists_last_id += 1;
    databaseMetadata->pharmacists_count += 1;

    Pharmacist* pharmacy = create_request_to_pharmacist(request);
    pharmacy->id = databaseMetadata->pharmacists_last_id;

    *table[databaseMetadata->pharmacists_count - 1] = pharmacy;

    return databaseMetadata->pharmacists_last_id;
}

Pharmacist* find_pharmacist(PharmacistIdentifier* identifier, Pharmacist*** table, DatabaseMetadata* databaseMetadata) {

    for (int i = 0; i < databaseMetadata->pharmacists_count; i++) {
        if (strcmp((*table)[i]->first_name, identifier->first_name) == 0 && strcmp((*table)[i]->last_name, identifier->last_name) == 0) {
            return *table[i];
        }
    }

    return NULL;
}

Pharmacy* find_pharmacy(char* name, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {

    for (int i = 0; i < databaseMetadata->pharmacies_count; i++) {
        if (strcpy((*table)[i]->name, name) == 0) {
            return *table[i];
        }
    }

    return NULL;
}

Pharmacist* find_pharmacist_by_id(unsigned int id, Pharmacist*** table, DatabaseMetadata* databaseMetadata) {

    for (int i = 0; databaseMetadata->pharmacists_count; i++) {
        if ((*table)[i]->id == id) {
            return *table[i];
        }
    }

    return NULL;
}

Pharmacy* find_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {

    for (int i = 0; databaseMetadata->pharmacies_count; i++) {
        if ((*table)[i]->id == id) {
            return *table[i];
        }
    }

    return NULL;
}

void delete_pharmacist_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {

}

void delete_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {

}