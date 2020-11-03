#include "entity.h"
#include "../entity/pharmacist.h"
#include "../entity/pharmacy.h"
#include "../entity/requests/create/pharmacy_create_request.h"
#include "../entity/requests/create/pharmacist_create_request.h"
#include "../entity/requests/identifiers/pharmacist_identifier.h"

/**
 * Part of application for manipulating with data stored in main
 */
#ifndef SEMESTRAL_PROJECT_DATA_MANAGEMENT_H
#define SEMESTRAL_PROJECT_DATA_MANAGEMENT_H

// Initialization

/**
 * @return DatabaseMetadata with initialized attributes
 */
DatabaseMetadata* init_db_metadata();

/**
 * Allocate initial memory for pharmacist holding structure
 * @return pointer to pointers of elements that we need to store
 */
Pharmacist** init_pharmacist_space();

/**
 * Allocate initial memory for pharmacy holding structure
 * @return pointer to pointers of elements that we need to store
 */
Pharmacy** init_pharmacy_space();

// CRUD operations

/**
 * Insert PharmacyCreateRequest into database and assign id to it.
 * If increment pharmacies_count attribute in DatabaseMetadata struct
 * If database would overflow, allocate bigger space, copy pointers from old space to new
 * and change value of database to bigger space
 * Free request and all unused child fields
 *
 * @param request entity to be inserted into "table"
 * @param table current array of pointers to stored structs
 * @param databaseMetadata info about all tables
 * @return assigned id
 */
unsigned int insert_pharmacy(PharmacyCreateRequest* request, Pharmacy*** table, DatabaseMetadata* databaseMetadata);

/**
 * Insert PharmacyCreateRequest into database and assign id to it.
 * If increment pharmacies_count attribute in DatabaseMetadata struct
 * If database would overflow, allocate bigger space, copy pointers from old space to new
 * and change value of database to bigger space
 * Free request and all unused child fields
 *
 * @param request entity to be inserted into "table"
 * @param table current array of pointers to stored structs
 * @param databaseMetadata info about all tables
 * @return assigned id
 */
unsigned int insert_pharmacist(PharmacistCreateRequest* request, Pharmacist*** table, DatabaseMetadata* databaseMetadata);

/**
 * Search for pharmacist with unique attributes combination
 *
 * @param identifier - pharmacist firstname + lastname unique combination
 * @return pointer to entity or NULL if not found
 */
Pharmacist* find_pharmacist(PharmacistIdentifier* identifier, Pharmacist*** table, DatabaseMetadata* databaseMetadata);

/**
 * Search for pharmacy with specific name
 *
 * @param name
 * @param table
 * @param databaseMetadata
 * @return pointer to pharmacy or NULL if not found
 */
Pharmacy* find_pharmacy(char* name, Pharmacy*** table, DatabaseMetadata* databaseMetadata);

/**
 * Find pharmacist by id
 *
 * @param id
 * @param table
 * @param databaseMetadata
 * @return pointer to entity or NULL if not found
 */
Pharmacist* find_pharmacist_by_id(unsigned int id, Pharmacist*** table, DatabaseMetadata* databaseMetadata);

/**
 * Find pharmacy by id
 *
 * @param id
 * @param table
 * @param databaseMetadata
 * @return pointer to entity or NULL if not found
 */
Pharmacy* find_pharmacy_by_id(unsigned int id, Pharmacy*** table, DatabaseMetadata* databaseMetadata);

#endif //SEMESTRAL_PROJECT_DATA_MANAGEMENT_H
