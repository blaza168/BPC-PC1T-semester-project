#include <stdlib.h>
#include <string.h>
#include "../entity.h"
#include "../vendor/convertor/entity_convertor.h"
#include "../../entity/pharmacist.h"
#include "../../entity/pharmacy.h"
#include "../../entity/requests/create/pharmacy_create_request.h"
#include "../../entity/requests/create/pharmacist_create_request.h"
#include "../../entity/requests/identifiers/pharmacist_identifier.h"
#include "../../entity/requests/update/pharmacy_update_request.h"
#include "../../entity/requests/update/pharmacist_update_request.h"

#define INITIAL_ENTITY_CAPACITY 20

// Private functions declaration
/**
 * @param id
 * @param table
 * @param databaseMetadata
 * @param index|NULL index of entity in holding list will be set here.
 * @return
 */
Pharmacist* find_pharmacist_by_id(unsigned int id, Pharmacist*** table, DatabaseMetadata* databaseMetadata, unsigned int* index);

/**
 * @param id
 * @param table
 * @param databaseMetadata
 * @param index|NULL index of entity in holding list will be set here.
 * @return
 */
Pharmacy* find_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata, unsigned int* index);

// public function implementation
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
        Pharmacist **buffer = (Pharmacist **) malloc(sizeof(struct Pharmacist *) * databaseMetadata->pharmacists_capacity);

        // copy data from old to new
        for (int i = 0; i < databaseMetadata->pharmacists_count; i++) {
            buffer[i] = *table[i];
        }
        free(*table);

        *table = buffer;
    }

    databaseMetadata->pharmacists_last_id += 1;
    databaseMetadata->pharmacists_count += 1;

    Pharmacist *pharmacy = create_request_to_pharmacist(request);
    pharmacy->id = databaseMetadata->pharmacists_last_id;

    unsigned int index = databaseMetadata->pharmacists_count - 1;

    (*table)[index] = pharmacy;

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
        char* pharmacy_name = (*table)[i]->name;
        int cmp_result = strcmp(pharmacy_name, name);
        if (cmp_result == 0) {
            return *table[i];
        }
    }

    return NULL;
}

Pharmacist* find_pharmacist_by_id(unsigned int id, Pharmacist*** table, DatabaseMetadata* databaseMetadata) {
    return find_pharmacist_by_id(id, table, databaseMetadata, NULL);
}

Pharmacy* find_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {
    return find_pharmacy_by_id(id, table, databaseMetadata, NULL);
}

void delete_pharmacist_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {
    unsigned int pharmacist_index;

    find_pharmacy_by_id(id, table, databaseMetadata, &pharmacist_index);


}

void delete_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata) {
    unsigned int pharmacy_index;

    find_pharmacy_by_id(id, table, databaseMetadata, &pharmacy_index);

}

void update_pharmacy(PharmacyUpdateRequest* request, Pharmacy* pharmacy) {
    pharmacy->phone = request->phone;
    pharmacy->name = request->name;
    pharmacy->address = request->address;

    free(request);
}

void update_pharmacist(PharmacistUpdateRequest* request, Pharmacist* pharmacist) {
    free(pharmacist->phone);
    free(pharmacist->last_name);
    free(pharmacist->first_name);

    pharmacist->phone = request->phone;
    pharmacist->last_name = request->last_name;
    pharmacist->first_name = request->first_name;

    free(request);
}

// Private functions implementation
Pharmacist* find_pharmacist_by_id(unsigned int id, Pharmacist*** table, DatabaseMetadata* databaseMetadata, unsigned int* index) {
    for (int i = 0; databaseMetadata->pharmacists_count; i++) {
        if ((*table)[i]->id == id) {
            if (index) {
                *index = i;
            }
            return (*table)[i];
        }
    }

    return NULL;
}

Pharmacy* find_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata, unsigned int* index) {
    for (int i = 0; databaseMetadata->pharmacies_count; i++) {
        if ((*table)[i]->id == id) {
            if (index) {
                *index = i;
            }
            return (*table)[i];
        }
    }

    return NULL;
}

Pharmacist** get_associated_pharmacists(unsigned int pharmacy_id, Pharmacist*** table, DatabaseMetadata* databaseMetadata, unsigned int* pharmacists_count) {
    Pharmacist** as_pharmacists = (Pharmacist**)malloc(sizeof(struct  Pharmacist*) * databaseMetadata->pharmacists_count);

    // find associated pharmacists
    *pharmacists_count = 0;
    for (int i = 0; i < databaseMetadata->pharmacists_count; i++) {
        if ((*table)[i]->pharmacy_id == pharmacy_id) {
            as_pharmacists[*pharmacists_count] = (*table)[i];
            *pharmacists_count += 1;
        }
    }

    // sort by last_name
    for (int i = 0; i < *pharmacists_count; i++) {
        for (int j = 0; j < *pharmacists_count - i - 1; j++) {
            if (strcmp(as_pharmacists[j]->last_name, as_pharmacists[j + 1]->last_name) == 1) {
                Pharmacist* buff = as_pharmacists[j + 1];
                as_pharmacists[j + 1] = as_pharmacists[j];
                as_pharmacists[j] = buff;
            }
        }
    }

    return as_pharmacists;
}
